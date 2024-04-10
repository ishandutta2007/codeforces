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

LL solver(LL n, LL k, LL len1, LL len2, LL inter, LL dist){
	LL vje = inter * n;
	if (vje >= k){
		return 0;
	}

	k -= vje;
	if (inter){
		if (k <= n * (len1 + len2 - 2*inter)){
			return k;
		}
		return n * (len1 + len2 - 2*inter) + 2 * (k - n *(len1 + len2 - 2*inter));
	}

	LL ans = LINF;
	FOR(i, 1, n + 1){
		LL curr = dist * i;
		LL she = k;
		if (she <= i * (len2 + len1 + dist)){
			curr += she;
		}else{
			she -= i * (len2 + len1 + dist);
			curr += i * (len2 + len1 + dist);			
			curr += 2 * she;
		}

		setmin(ans, curr);
	}

	return ans;
}

LL solver(LL n, LL k, LL len1, LL len2){
	LL vje = len2 * n;
	if (vje >= k){
		return 0;
	}

	k -= vje;
	LL il = (len1 - len2) * n;
	if (k <= il)return k;
	k -= il;
	return il + 2 * k;
}

LL solve(){
	LL n, k, l1, r1, l2, r2;
	cin >> n >> k;
	cin >> l1 >> r1 >> l2 >> r2;
	if (l1 > l2 || (l1 == l2 && r1 < r2)){
		swap(l1, l2);
		swap(r1, r2);
	}

	if (r1 >= r2){
		return solver(n, k, r1 - l1, r2 - l2);
	}
	
	return solver(n, k, r1 - l1, r2 - l2, max(0LL, r1 - l2), l2 - r1);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int tc; cin >> tc;
	while(tc--){
		cout << solve() << '\n';
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}