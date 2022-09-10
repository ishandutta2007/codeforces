#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 17;
int n;
int a[N];
int prev_bigger[N];
int next_bigger[N];

namespace Lol1
{
	struct node{
		int suf, ans, sum;
		node(){
			suf = ans = sum = 0;
		}
		
		node(int x){
			sum = x;
			suf = ans = max(x, 0);
		}
	};

	node merge(node l, node r){
		node res;
		res.suf = max(r.suf, r.sum + l.suf);
		res.sum = l.sum + r.sum;
		res.ans = max(l.suf + r.sum, r.ans);
		return res;
	}	

	
	node t[N << 1];

	void build(int v, int tl, int tr){
		if (tl == tr){
			t[v] = node(a[tl]);
		}else{
			int tm = (tl + tr) >> 1;
			build(v * 2, tl, tm);
			build(v * 2 + 1, tm + 1, tr);
			t[v] = merge(t[v * 2], t[v * 2 + 1]);
		}
	}

	node get(int v, int tl, int tr, int l, int r){
		if (l == tl && r == tr) return t[v];
		if (l > r || tl > tr) return node();
		int tm = (tl + tr) >> 1;
		return merge(get(v * 2, tl, tm, l, min(r, tm)), 
					 get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	}

	int get_sum(int l, int r){
		if (l > r) return 0;
		return get(1, 0, n - 1, l, r).ans;
	}
};

namespace Lol2
{
	struct node{
		int suf, ans, sum;
		node(){
			suf = ans = sum = 0;
		}
		
		node(int x){
			sum = x;
			suf = ans = max(x, 0);
		}
	};

	node merge(node l, node r){
		node res;
		res.suf = max(l.suf, l.sum + r.suf);
		res.sum = l.sum + r.sum;
		res.ans = max(l.sum + r.suf, l.ans);
		return res;
	}	

	node t[N << 1];

	void build(int v, int tl, int tr){
		if (tl == tr){
			t[v] = node(a[tl]);
		}else{
			int tm = (tl + tr) >> 1;
			build(v * 2, tl, tm);
			build(v * 2 + 1, tm + 1, tr);
			t[v] = merge(t[v * 2], t[v * 2 + 1]);
		}
	}

	node get(int v, int tl, int tr, int l, int r){
		if (l == tl && r == tr) return t[v];
		if (l > r || tl > tr) return node();
		int tm = (tl + tr) >> 1;
		return merge(get(v * 2, tl, tm, l, min(r, tm)), 
					 get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	}

	int get_sum(int l, int r){
		if (l > r) return 0;
		return get(1, 0, n - 1, l, r).ans;
	}
};

int L[1 << 20];
int R[1 << 20];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	
	stack<PII> s;
	s.push({INF, -1});
	FOR(i, 0, n){
		while (s.top().X <= a[i]) s.pop();
		prev_bigger[i] = s.top().Y;
		s.push({a[i], i});
	}
	
	while(SZ(s)) s.pop();
	s.push({INF, n});
	
	RFOR(i, n, 0){
		while (s.top().X <= a[i]) s.pop();
		next_bigger[i] = s.top().Y;
		s.push({a[i], i});
	}
	
	Lol1::build(1, 0, n - 1);
	FOR(i, 0, n){
		L[i] = Lol1::get_sum(prev_bigger[i] + 1, i - 1);
	}
	
	Lol2::build(1, 0, n - 1);
	FOR(i, 0, n){
		R[i] = Lol2::get_sum(i + 1, next_bigger[i] - 1);
	}
	
	int ans = 0;
	FOR(i, 0, n){
		//cout << L[i] << ' ' << R[i] << endl;
		setmax(ans, L[i] + R[i]);
	}
	
	cout << ans << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}