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
const LL INF = 1e9;
const LL LINF = INF * INF;

const int N = 1 << 20;
int fw[N];

void add(int x, int v){
	for(; x < N; x |= x + 1){
		fw[x] += v;
	}
}

int sum(int r){
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1){
		res += fw[r];
	}
	
	return res;
}

inline int sum(int l, int r){
	return sum(r) - sum(l - 1);
}

int find_kth(int k){
	if (sum(N - 1) < k){
		return 0;
	}
	
	int l = -1, r = N - 1, m;
	while(r - l > 1){
		m = (l + r) >> 1;
		if (sum(m) < k){
			l = m;
		}else{
			r = m;
		}
	}
	
	return r;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  
	int n, q;
	cin >> n >> q;
	FOR(i, 0, n){
		int x;
		cin >> x;
		add(x, 1);
	}
	
	FOR(i, n, n + q){
		int k;
		cin >> k;
		if (k > 0){
			add(k, 1);
		}else{
			k = -k;
			int tut = find_kth(k);
			add(tut, -1);
		}
	}	
	
	cout << find_kth(1) << endl;
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}