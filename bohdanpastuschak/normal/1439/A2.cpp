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

vector<vector<PII>> ans;
void go(int i, int j, vector<string>& s){
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
		go(i, j, s);
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
		go(i, j, s);
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
		go(i, j, s);
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
		go(i, j, s);
		return;
	}
}

vector<vector<PII>> solve_brute(int n, int m, const vector<string>& s){
	vector<PII> vec;
	FOR(i, 0, n - 1) FOR(j, 0, m - 1) vec.PB({i, j});

	FOR(it, 0, 1000){
		shuffle(ALL(vec), rng);
		auto t = s;
		ans.clear();
		for(auto [i, j]: vec){
			go(i, j, t);
		}

		if (SZ(ans) <= n * m){
			return ans;
		}
	}
	vector<pair<PII, int>> kek;
	FOR(i, 0, n - 1) FOR(j, 0, m - 1) FOR(x, 0, 4) kek.PB({{i, j}, x});
	FOR(it, 0, 100000){
		shuffle(ALL(kek), rng);
		auto t = s;
		ans.clear();
		for(auto i: kek){
			int x = i.X.X, y = i.X.Y;
			vector<PII> A;
			FOR(xx, 0, 2) FOR(yy, 0, 2) if ((xx * 2 + yy) != i.Y){
				t[x + xx][y + yy] ^= 1;
				A.PB({x + xx, y + yy});
			}

			ans.PB(A);
			bool ok = 1;
			FOR(ii, 0, n) FOR(j, 0, m) ok &= t[ii][j] == 0;
			if (ok) break;
			
			if (SZ(ans) > n * m) break;
		}

		if (SZ(ans) <= n * m){
			return ans;
		}
	}

	return {};
}

vector<vector<PII>> mp[4][4][1 << 9];

void check(int n, int m){
	FOR(mask, 0, 1 << (n * m)){
		vector<string> s(n);
		FOR(i, 0, n){
			s[i] = string(m, 0);
			FOR(j, 0, m){
				if (mask & (1 << (i * m + j))){
					s[i][j] = 1;
				}
			}
		}
			
		mp[n][m][mask] = solve_brute(n, m, s);
		if (SZ(mp[n][m][mask]) == 0){
			cerr << "HUJ" << endl;
		}
	}
}

inline int calc(vector<string>& s){
	int Ans = 0;
	FOR(i, 0, SZ(s)) FOR(j, 0, SZ(s[0])){
		if (s[i][j] == 1){
			Ans += 1 << (i * SZ(s[0]) + j);
		}
	}

	return Ans;
}

void make(vector<PII>& x, vector<string>& s){
	for(auto i: x){
		s[i.X][i.Y] ^= 1;
	}
}	

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	check(2, 2);
	check(2, 3);
	check(3, 2);
	check(3, 3);

    
	int tc; cin >> tc;
	while(tc--){
		int n, m; cin >> n >> m;
		vector<string> s(n);
		FOR(i, 0, n){
			cin >> s[i];			
			for(auto& j: s[i]) j -= '0';
		}

		auto t = s;

		vector<vector<PII>> Ans;

		for(int i = 0; i + 2 <= n; i += 2){
			for(int j = 0; j + 2 <= m; j += 2){
				int n1 = 2 + (i + 3 == n);
				int n2 = 2 + (j + 3 == m);

				//cout << i << ' ' << j << ' ' << n1 << ' ' << n2 << endl;
				vector<string> kek(n1);
				FOR(x, 0, n1){
					kek[x] = string(n2, 0);
					FOR(y, 0, n2){
						kek[x][y] = s[i + x][j + y];
					}
				}

				auto res = mp[n1][n2][calc(kek)];
				for(auto& vec: res){
					for(auto& lol: vec){
						lol.X += i;
						lol.Y += j;
					}
					
					Ans.PB(vec);
				}
			}
		}

		
		cout << SZ(Ans) << endl;
		for(auto i: Ans){
			for(auto j: i){
				cout << j.X + 1 << ' ' << j.Y + 1 << ' ';
			}
			cout << endl;
		}

		for(auto i: Ans){
			make(i, t);
		}

		assert(SZ(Ans) <= n * m);
		for(auto i: t) for(auto j: i) assert(j == 0);
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}