#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,avx")

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
const int INF = 1e9 + 47;
const LL LINF = 1LL * INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1000;

int solve(vector<int>& x, vector<int>& y){
	sort(ALL(x));
	sort(ALL(y));
	if (SZ(x) == 0) return 1;
	if (SZ(y) == 0) return 0;
	
	int b = min(x[0], y[0]);
    double sx = 0, sy = 0;
    for(auto i: x){
        sx += pow(0.75, i - b);
    }
    for(auto i: y){
        sy += pow(0.75, i - b);
    }
    
    double r = (rng() % 1000000) / (double) 1000000 * (sx + sy);
    return r >= sx;
}

int main()
{
	const bool local = 0;	
	int n, m; cin >> n >> m;
	vector<int> mistake(n + 1, 0);
	while(m--){
		string s; cin >> s;
		vector<int> x, y;
		FOR(i, 0, n){
			if (s[i] == '0') x.PB(mistake[i]);
			else y.PB(mistake[i]);
		}
		
		s += (char)('0' + solve(x, y));
		if (!local){
			cout << s[n] << endl;
			fflush(stdout);
		}
		
		char res; cin >> res;
		FOR(i, 0, n + 1){
			mistake[i] += s[i] != res;
		}
		
		//assert(mistake[n] <= 1.3 * (*min_element(ALL(mistake))) + 100);
	//	cerr << mistake[n] << ' ' << (*min_element(ALL(mistake))) << endl;
	}	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}