#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
vector<int> g[100007];
ll w1[100007];
ll w2[100007];

ll sqr(ll x) { return x*x; }

struct line {
	char type;
	double x;
	ll k, n;
};

bool operator<(line l1, line l2) {
	if (l1.type+l2.type>0) return l1.x<l2.x;
	else return l1.k>l2.k;
}

struct st{
	set<line> env;
	typedef set<line>::iterator sit;

	bool hasPrev(sit it) { return it!=env.begin(); }
	bool hasNext(sit it) { return it!=env.end() && next(it)!=env.end(); }

	double intersect(sit it1, sit it2) {
		return (double)(it1->n-it2->n)/(it2->k-it1->k);
	}

	void calcX(sit it) {
		if (hasPrev(it)) {
			line l = *it;
			l.x = intersect(prev(it), it);
			env.insert(env.erase(it), l);
		}
	}

	bool irrelevant(sit it) {
		//if (hasNext(it) && next(it)->n <= it->n) return true; // x=0 cutoff //useless
		return hasPrev(it) && hasNext(it) && intersect(prev(it),next(it)) <= intersect(prev(it),it);
	}

	void add(ll k, ll a) {
		sit it;
		// handle collinear line
		it=env.lower_bound({0,0,k,a});
		if (it!=env.end() && it->k==k) {
			if (it->n <= a) return;
			else env.erase(it);
		}
		// erase irrelevant lines
		it=env.insert({0,-1000000,k,a}).first;
		if (irrelevant(it)) { env.erase(it); return; }
		while (hasPrev(it) && irrelevant(prev(it))) env.erase(prev(it));
		while (hasNext(it) && irrelevant(next(it))) env.erase(next(it));
		// recalc left intersection points
		if (hasNext(it)) calcX(next(it));
		calcX(it);
	}

	ll query(ll x) {
		auto it = env.upper_bound((line){1,(double)x,0,0});
		it--;
		return it->n+x*it->k;
	}
} st[100007];

ll ans[100007];


void dfs(int v, int pred){
	//cout << v << ' ' << pred << endl;
	int ff = 0;
	for (int to : g[v]) if (to != pred){
		dfs(to, v);
		if (st[to].env.size() > st[v].env.size()) swap(st[to], st[v]);
		for (auto c : st[to].env){
			st[v].add(c.k, c.n);
		}
		ff = 1;
	}
	if (ff) ans[v] = st[v].query(w1[v]); else ans[v] = 0;
	st[v].add(w2[v], ans[v]);
	//for (auto c : st[v].env){
	//	cout << "===" << v + 1 << ' ' << c.k << ' ' << c.n << ' ' << c.x << endl;
	//}
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
   	cin >> n;
   	for (int i = 0; i < n; i++) cin >> w1[i];
   	for (int i = 0; i < n; i++) cin >> w2[i];
   	for (int i = 0; i < n - 1; i++){
   		int a, b;
   		cin >> a >> b;
   		a--; b--;
   		g[a].pb(b);
   		g[b].pb(a);
   	}
   	dfs(0, -1);
   	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}