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

const int N = 1 << 10;
int n, m;
bool a[N][N];
bool na[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

inline bool inRange(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void go(){
	
	FOR(i, 0, n) FOR(j, 0, m){
		int cnt = 0;		
		FOR(k, 0, 4){
			int x = i + dx[k], y = j + dy[k];
			if (inRange(x, y) && a[x][y] != a[i][j]){
				cnt++;
			}
		}
		
		if (cnt){
			na[i][j] = !a[i][j];
		}else{
			na[i][j] = a[i][j];
		}
	}
	
	FOR(i, 0, n) FOR(j, 0, m) a[i][j] = na[i][j];
}

void print(){
	FOR(i, 0, n){
		FOR(j, 0, m) cout << a[i][j];
		cout << endl;
	}
	cout << endl;
}

bool ok[N][N];
int d[N][N];

void bfs(){
	FILL(d, -1);
	queue<PII> q;
	FOR(i, 0, n) FOR(j, 0, m) if (ok[i][j]){
		d[i][j] = 0;
		q.push({i, j});
	}
	
	while(!q.empty()){
		int x = q.front().X, y = q.front().Y;
		q.pop();
		
		FOR(k, 0, 4){
			int i = x + dx[k], j = y + dy[k];
			if (inRange(i, j) && d[i][j] == -1){
				d[i][j] = d[x][y] + 1;
				q.push({i, j});
			}
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int q;
	cin >> n >> m >> q;
	FOR(i, 0, n) 
	{
		string s;cin >> s;
		FOR(j, 0, m) a[i][j] = s[j] == '1';
	}
	
	bool WAS = false;
	FOR(i, 0, n) FOR(j, 0, m){
		FOR(k, 0, 4){
			int x = i + dx[k], y = j + dy[k];
			if (inRange(x, y) && a[x][y] == a[i][j]){
				ok[i][j] = true;
				WAS = true;
			}
		}
	}
	
	if (!WAS){
		while(q--){
			int x, y;
			LL p;
			cin >> x >> y >> p;
			--x; --y;
			cout << a[x][y] << '\n';
		}
		
		return 0;
	}
	
	bfs();	
	
	while(q--)
	{
		int x, y;
		LL p;
		cin >> x >> y >> p;
		--x; --y;
		
		if (p <= d[x][y]){
			cout << a[x][y] << '\n';			
		}else{
			if ((p - d[x][y]) & 1){
				cout << !a[x][y] << '\n';
			}else{
				cout << a[x][y] << '\n';
			}
		}		
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}