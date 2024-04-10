#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

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

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
class SparseTable{
public:
	int n, lg;
	vector<vector<T>> table;
	vector<T> a;

	inline T operation(const T& l, const T& r){
		return max(l, r);
	}
	
	void build(){
		FOR(i, 0, n) table[i][0] = a[i];		
		FOR(len, 0, lg - 1) FOR(i, 0, n){
			table[i][len + 1] = i + (1 << len) >= n ? table[i][len] :
			operation(table[i][len], table[i + (1 << len)][len]);			
		}
	}

	T query(int l, int r){
		const int LOG = 31 - __builtin_clz(r - l + 1);
		return operation(table[l][LOG], table[r - (1 << LOG) + 1][LOG]);
	}

	void init(){
		lg = 1;
		while((1 << lg) <= n) lg++;

		table.resize(n);
		FOR(i, 0, n) table[i].resize(lg);
		
		build();
	}
	
	SparseTable(){}
	SparseTable(const vector<T>& A){
		n = SZ(A);
		a = A;
		init();
	}

	SparseTable(int _n, const T* A){
		n = _n;
		a.resize(n);
		FOR(i, 0, n) a[i] = A[i];
		init();
	}	
};

namespace IntModulo
{
	const int mod = 1e9 + 7;

	inline int add(int x, int y, int m = mod)
	{
		if (x + y < m)
			return x + y;
		return x + y - m;
	}

	inline int sub(int x, int y, int m = mod)
	{
		if (x >= y)
			return x - y;
		return x - y + m;
	}

	inline int mult(int x, int y, int m = mod)
	{
		return x * (LL) y % m;
	}

	inline int power(int x, LL y, int m = mod)
	{
		int r = 1;
		while(y)
		{
			if (y & 1)
				r = mult(r, x, m);
			x = mult(x, x, m);
			y >>= 1;
		}
		
		return r;
	}
	
	inline int inverse(int x, int m = mod)
	{
		return power(x, m - 2, m);
	}

	inline void ADD(int& x, int y, int m = mod){
		x += y;
		if (x >= m) x -= m;
	}

	inline void SUB(int& x, int y, int m = mod){
		x -= y;
		if (x < 0) x += m;
	}

	inline void MULT(int& x, int y, int m = mod){
		x = (x * (LL) y) % m;
	}
};

using namespace IntModulo;

const int N = 200001;
int lp[N];
int n, q, id[N];
vector<int> small, big, inv;

namespace PersistentSegmentTree{
	const int A = 1 << 18;
	int ar[A];
	int tree[18*A];
	int lft[18*A];
	int rht[18*A];
	int root[18 * A];
	int rt[A];
	int idx;
	 
	inline void build(int node,int start,int end)
	{
		if(start==end)
		{
			tree[node]=1;
			return;
		}
		lft[node]=idx++;
		rht[node]=idx++;
		int mid=(start+end)/2;
		build(lft[node],start,mid);
		build(rht[node],mid+1,end);
		tree[node]=1;
	}
	 
	inline int update(int node,int start,int end,int pos,int val)
	{
		int x;
		x=idx++;
		if(start==end)
		{
			tree[x]=val;
			return x;
		}
		lft[x]=lft[node];
		rht[x]=rht[node];
		int mid=(start+end)/2;
		if(pos<=mid)
			lft[x]=update(lft[x],start,mid,pos,val);
		else
			rht[x]=update(rht[x],mid+1,end,pos,val);
	 
		tree[x]= mult(tree[lft[x]],tree[rht[x]]);
	 
		return x;
	}
	 
	inline int query(int node,int start,int end,int l,int r)
	{
		if(start>r || end<l){
			return 1;
		}

		
		else if(start>=l && end<=r)
			return tree[node];
		
		int mid=(start+end)/2;
		int q1=query(lft[node],start,mid,l,r);
		int q2=query(rht[node],mid+1,end,l,r);
	 
		return mult(q1, q2);				
	}

	unordered_map<int,int> pos;
	void init(){
		
		build(0, 1, n);		
		int t = 1;
		FOR(i, 1, n + 1){
			int k = pos[ar[i]];
			if(k != 0){
				root[t]=update(root[t-1],1,n,k,1);
				t++;
				root[t]=update(root[t-1],1,n,i,ar[i]);
				t++;
			}
			else
			{
				root[t]=update(root[t-1],1,n,i,ar[i]);
				t++;
			}
			
			rt[i] = t - 1;
			pos[ar[i]] = i;					
		}
	}
	
	int solve(int a, int b){		
		return query(root[rt[b]],1,n,a,b);      
	}
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	iota(lp, lp + N, 0);
	FOR(i, 2, N) if (lp[i] == i){
		if (i * (LL)  i < N){
			id[i] = SZ(small);
			small.PB(i);
		}else{
			id[i] = SZ(big);
			inv.PB(inverse(i));
			big.PB(i);
		}
			
		for(int j = i + i; j < N; j += i){
			setmin(lp[j], i);
		}
	}

	debug(SZ(big))
	cin >> n;
	const int sz = SZ(small);
	vector<vector<char>> here(sz, vector<char>(n, 0));

	FOR(i, 0, n){
		PersistentSegmentTree::ar[i + 1] = 1;
		int x; cin >> x;
		while(x > 1){
			int P = lp[x], cnt = 0;
			while(x % P == 0){
				x /= P;
				cnt++;
			}

			if (P * (LL) P < N){
				here[id[P]][i] = cnt;
			}else{
				PersistentSegmentTree::ar[i + 1] = P;				
			}
		}
	}
	
	vector<SparseTable<char>> table(sz);
	FOR(i, 0, sz){
		table[i] = SparseTable<char>(here[i]);
	}

	PersistentSegmentTree::init();
	cin >> q;
	int last = 0;
	bool huj = false;
	huj &= n > 1000;

	
	vector<vector<int>> vec(sz, vector<int>(25, 0));
	FOR(i, 0, sz){
		vec[i][0] = 1;
		FOR(j, 1, 25) vec[i][j] = vec[i][j - 1] * small[i];
	}
	
	while(q--){
		int x, y; cin >> x >> y;
		int l = (last + x) % n;
		int r = (last + y) % n;
		if (l > r) swap(l, r);
		if (huj){
			last = 1;
		}else{
			last = PersistentSegmentTree::solve(l + 1, r + 1);
		}
		
		FOR(i, 0, sz){
			MULT(last, vec[i][table[i].query(l, r)]);
		}
		
		cout << last << '\n';
	}
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}