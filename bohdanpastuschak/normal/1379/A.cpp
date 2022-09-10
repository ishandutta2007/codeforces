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

const string S = "abacaba";
bool test(string s){
	int cnt = 0;
	FOR(i, 0, SZ(s) - SZ(S) + 1){
		cnt += S == s.substr(i, SZ(S));
	}
	
	return cnt == 1;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		bool ok = 0;
		FOR(i, 0, n - SZ(S) + 1) if (!ok){
			string tut = s.substr(i, SZ(S));
			bool T = 1;
			FOR(j, 0, SZ(S)) if (s[j + i] != '?'){
				T &= s[i + j] == S[j];
			}

			if (T){
				string cand;
				
				FOR(j, 0, i) if (s[j] == '?') cand += 'x';
				else cand += s[j];
				cand += S;
				FOR(j, i + SZ(S), n) if (s[j] == '?') cand += 'x';
				else cand += s[j];

				if (test(cand)){
					cout << "YES" << endl;
					cout << cand << endl;
					ok = 1;
					break;
				}
			}
		}
		
		if (!ok) cout << "NO" << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}