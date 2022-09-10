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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		string ans;
		int cnt0 = 0, cnt1 = 0;
		while(SZ(s) && s.back() == '1') cnt1++, s.pop_back();
		reverse(ALL(s));
		while(SZ(s) && s.back() == '0') cnt0++, s.pop_back();
		reverse(ALL(s));
				
		FOR(i, 0, cnt0) cout << 0;
		if (SZ(s)){			
			bool was0 = false;
			for(auto i: s) was0 |= i == '0';
			cout << !was0;
		}
		
		FOR(i, 0, cnt1) cout << 1;
		cout << endl;
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}