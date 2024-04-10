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

const int N = 100 + 7;
int n, m;
string s[N];
vector<vector<PII>> ans;
				
void go(int i, int j){
	int c = 0;
	FOR(x, 0, 2) FOR(y, 0, 2) c += s[i + x][j + y] == 0;
	if (c == 4){
		return;
	}

	if (c == 1){
		vector<PII> A;
		FOR(x, 0, 2) FOR(y, 0, 2) if (s[i + x][j + y] == 1){
			A.PB({i + x, j + y});
			s[i + x][j + y] = 0;
		}

		ans.PB(A);
		go(i, j);
		return;
	}

	if (c == 2){
		vector<PII> A;
		int cnt = 0;
		FOR(x, 0, 2) FOR(y, 0, 2) if (s[i + x][j + y] == 0){
			A.PB({i + x, j + y});
			s[i + x][j + y] = 1;
		}else{
			if (cnt < 1){
				cnt++;
				A.PB({i + x, j + y});
				s[i + x][j + y] = 0;
			}
		}

		ans.PB(A);
		go(i, j);
		return;
	}

	if (c == 3){
		vector<PII> A;
		int cnt = 0;
		FOR(x, 0, 2) FOR(y, 0, 2) if (s[i + x][j + y] == 1){
			A.PB({i + x, j + y});
			s[i + x][j + y] = 0;
		}else{
			if (cnt < 2){
				cnt++;
				A.PB({i + x, j + y});
				s[i + x][j + y] = 1;
			}
		}

		ans.PB(A);
		go(i, j);
		return;
	}

	if (c == 0){
		vector<PII> A;
		int cnt = 0;
		FOR(x, 0, 2) FOR(y, 0, 2) if (cnt < 3){
			A.PB({i + x, j + y});
			s[i + x][j + y] = 0;
			cnt++;
		}
		
		ans.PB(A);
		go(i, j);
		return;
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		FOR(i, 0, n){
			cin >> s[i];
			for(auto& j: s[i]) j -= '0';
		}

		ans.clear();

		FOR(i, 0, n - 1) FOR(j, 0, m - 1){
			go(i, j);
		}			

		assert(SZ(ans) <= 3 * n * m);
		cout << SZ(ans) << endl;
		for(auto i: ans){
			for(auto j: i){
				cout << j.X + 1 << ' ' << j.Y + 1 << ' ';
			}
			cout << endl;
		}
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}