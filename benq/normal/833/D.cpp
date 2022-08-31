#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
const int MX = 100001;

int mul(int a, int b) {
    return (ll)a*b % MOD;    
}

class tree {
private:
	struct node {
		node *l = nullptr, *r = nullptr;
		int y, size, value, w, x, s;
		node(int x, int w) : x(x), w(w), value(w) {
		    y = rand();
		    size = 1;
		    s = 1;
		}
	};

	typedef node * treap;
	typedef pair<treap, treap> ptt;

	treap root = nullptr;

	pair<int, int> values(treap t) {
		if (!t) return mp(0, 1);
		return mp(t->size, t->value);
	}

	treap mend(treap t) {
		if (t) {
			pair<int, int> l_values = values(t->l), r_values = values(t->r);
			t->size = l_values.first + r_values.first + t->s;
			t->value = mul(mul(l_values.second, r_values.second), t->w);
		}
		return t;
	}

	ptt split(treap t, int x) // >= x goes to the right
	{
		if (!t) return mp(t, t);

		if (x <= t->x)
		{
			ptt p = split(t->l, x);
			t->l = p.second;

			return mp(p.first, mend(t));
		}
		else
		{
			ptt p = split(t->r, x);
			t->r = p.first;

			return mp(mend(t), p.second);
		}
	}

	treap merge(treap u, treap v)
	{
		if (!u) return v;
		if (!v) return u;

		if (u->y > v->y)
		{
			u->r = merge(u->r, v);
			return mend(u);
		}
		else
		{
			v->l = merge(u, v->l);
			return mend(v);
		}
	}

public:
	tree() {
	}

	void insert(int x, int w)
	{
		ptt p = split(root, x);

		ptt q = split(p.second, x + 1);

		if (!q.first)
			root = merge(merge(p.first, new node(x, w)), p.second);
		else
		{
			q.first->s++;
			q.first->w = mul(q.first->w, w);

			q.first = mend(q.first);

			root = merge(merge(p.first, q.first), q.second);
		}
	}

	pair<int, int> range(int x, bool flag) // 0 = [-inf, x), 1 = [x, +inf)
	{
		ptt p = split(root, x);
		pair<int, int> rv = values(flag ? p.second : p.first);
		root = merge(p.first, p.second);
		return rv;
	}

	void clear()
	{
		root = nullptr;
	}
};

int n, visit[MX], sz[MX], par[MX];
pii info[MX];
vector<pii> adj[MX];
ll ans = 1;

void dfs(int no) {
    sz[no] = 1;
    for (pii x: adj[no]) if (x.f != par[no] && !visit[x.f]) {
        par[x.f] = no;
        dfs(x.f);
        sz[no] += sz[x.f];
    }
}

int get_centroid(int x) {
    par[x] = 0;
    dfs(x);
    int t = sz[x];
    while (1) {
        pii m = {0,0};
        for (pii y: adj[x]) if (y.f != par[x] && !visit[y.f]) m = max(m,{sz[y.f],y.f});
        if (2*m.f <= t) return x;
        x = m.s;
    }
}

vector<pair<int,pii>> data;

ll po(ll b, ll p) {
    ll ans = 1;
    while (p) {
        if (p&1) ans = ans*b % MOD;
        b = b*b % MOD;
        p /= 2;
    }
    return ans;
}

ll divide(int a, int b) {
    return a*po(b,MOD-2) % MOD;
}

void dfs1(int no, int w, int b, int prod) {
    data.pb({prod,{w,b}});
    for (pii v: adj[no]) if (v.f != par[no] && !visit[v.f]) {
        par[v.f] = no;
        dfs1(v.f,w+!info[v.s].s,b+info[v.s].s,mul(prod,info[v.s].f));
    }
}

void process(int x) {
    tree prefix = tree(), suffix = tree();
    int pos = 1, neg = 1;
    par[x] = x;

	for (pii v: adj[x]) if (!visit[v.f]) {
	    par[v.f] = x;
		data.clear();
		dfs1(v.f, !info[v.s].s, info[v.s].s, info[v.s].f);
		for (auto v : data) {
			pii positive = suffix.range(v.s.s-2*v.s.f, true); // (size, value)
			pii negative = prefix.range(v.s.f-2*v.s.s, false);

			pos = mul(pos, positive.s), neg = mul(neg, negative.s);
			ans = mul(ans, po(v.f, positive.f-negative.f));
			
            if (min(v.s.f, v.s.s) * 2 >= max(v.s.f, v.s.s)) ans = mul(ans, v.f);
		}
		for (auto v: data) {
			suffix.insert(2*v.s.f-v.s.s, v.f);
			prefix.insert(2*v.s.s-v.s.f, v.f);
		}
	}
	ans = mul(ans, divide(pos, neg));
}

void solve(int x) {
    x = get_centroid(x);
    process(x);
    visit[x] = 1;
    for (pii i: adj[x]) if (!visit[i.f]) solve(i.f);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n-1) {
	    int a,b; cin >> a >> b;
	    adj[a].pb({b,i}), adj[b].pb({a,i});
	    cin >> info[i].f >> info[i].s;
	}
	solve(1);
	cout << ans;
}

// read!
// ll vs. int!