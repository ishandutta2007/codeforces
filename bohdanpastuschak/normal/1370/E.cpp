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

int solve(string s){
	int cnt = 0;
	for(auto i: s) cnt += (i == 1 ? 1 : -1);
	if (cnt != 0) return -1;
		
	const int n = SZ(s);
	set<int> od, nu;
	FOR(i, 0, n) if (s[i]) od.insert(i);
	else nu.insert(i);
	
	int ans = 0;
	while(SZ(od)){
		int fod = *od.begin();
		int fnu = *nu.begin();
		bool now = fod < fnu;
		int curr = min(fod, fnu);
		if (now) od.erase(curr);
		else nu.erase(curr);
		
		bool start = now;
		
		while(true){
			if (now){
				auto it = nu.lower_bound(curr);
				if (it == nu.end()) break;
				int hto = *it;
				if (start != now){
					auto it2 = od.lower_bound(hto);
					if (it2 == od.end()) break;
				}
				
				curr = hto;
				nu.erase(curr);
			}else{
				auto it = od.lower_bound(curr);
				if (it == od.end()) break;
				int hto = *it;
				if (start != now){
					auto it2 = nu.lower_bound(hto);
					if (it2 == nu.end()) break;
				}
				
				curr = hto;
				od.erase(curr);
			}
			
			now ^= 1;
		}
		
		ans++;
	}
			
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	string S, T;
	cin >> S >> T;
	for(auto& i: S) i -= '0';
	for(auto& i: T) i -= '0';
	
	string s;
	FOR(i, 0, n) if (S[i] != T[i]) s += S[i];
	cout << solve(s) << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}