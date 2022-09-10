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

void bad(){
	cout << -1 << endl;
	exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> a(n + 1);
	FOR(i, 1, n + 1) cin >> a[i];
	vector<pair<int, int>> ans;
	vector<int> o, d;
	vector<int> nxt(n + 1, -1);
	vector<char> start(n + 1, 0);
	int last3 = -1;
	
	RFOR(i, n + 1, 1){
		if (a[i]){
			if (a[i] == 1){
				o.PB(i);
				start[i] = 1;
			}else if (a[i] == 2){
				if (SZ(o) == 0){
					bad();
				}

				int ja = o.back();
				o.pop_back();
				d.PB(i);
				nxt[i] = ja;
				start[i] = 1;
				start[ja] = 0;
			}else if (a[i] == 3){
				if (last3 != -1){
					nxt[i] = last3;
					start[last3] = 0;
					start[i] = 1;					
				}else{				
					if (SZ(o) == 0 && SZ(d) == 0){
						bad();
					}

					if (SZ(d) > 0){
						int ja = d.back();
						d.pop_back();
						start[ja] = 0;
						start[i] = 1;
						nxt[i] = ja;
					}else{
						int ja = o.back();
						o.pop_back();
						start[ja] = 0;
						start[i] = 1;
						nxt[i] = ja;
					}
				}

				
				last3 = i;
			}
		}
	}

	int first_ok = 1;
	FOR(i, 1, n + 1){
		if (a[i] && start[i]){
			if (a[i] == 1){
				ans.PB({first_ok, i});
				first_ok++;
			}else if (a[i] == 2){
				ans.PB({first_ok, i});
				ans.PB({first_ok, nxt[i]});
				first_ok++;
			}else{
				vector<int> lol;
				int curr = i;
				while(a[curr] != 1){
					lol.PB(curr);
					curr = nxt[curr];
				}

				lol.PB(curr);
				assert(a[lol.back()] == 1);
				if (a[lol[SZ(lol) - 2]] == 2){
					FOR(j, 0, SZ(lol) - 2){
						ans.PB({first_ok, lol[j]});
						ans.PB({first_ok, lol[j + 1]});
						first_ok++;
					}

					int I = lol[SZ(lol) - 2];
					ans.PB({first_ok, I});
					ans.PB({first_ok, nxt[I]});
					first_ok++;
				}else{
					FOR(j, 0, SZ(lol) - 1){
						ans.PB({first_ok, lol[j]});
						ans.PB({first_ok, lol[j + 1]});
						first_ok++;
					}

					ans.PB({first_ok, lol.back()});
					first_ok++;
				}
			}
		}
	}

	for(auto i: ans){
		if (i.X > n){
			bad();
		}
	}
	
	cout << SZ(ans) << '\n';
	for(auto i: ans){
		cout << i.X << ' ' << i.Y << '\n';
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}