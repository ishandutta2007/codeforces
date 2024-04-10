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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, K;
	cin >> n >> m >> K;
	vector<vector<int>> d(n, vector<int>(m, -1));
	queue<PII> q;
	while(K--){
		int x, y;
		cin >> x >> y;
		--x; --y;
		d[x][y] = 0;
		q.push({x, y});
	}

	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	auto ok = [&](int x, int y){
		return x >= 0 && x < n && y >= 0 && y < m;
	};
	
	while(!q.empty()){
		int x = q.front().X;
		int y = q.front().Y;
		q.pop();

		FOR(k, 0, 4){
			int i = x + dx[k];
			int j = y + dy[k];
			if (!ok(i, j) || d[i][j] != -1) continue;
			d[i][j] = d[x][y] + 1;
			q.push({i, j});
		}
	}

	int mx = -1;
	PII ans;

	FOR(i, 0, n) FOR(j, 0, m) if (d[i][j] > mx){
		mx = d[i][j];
		ans = {i, j};
	}

	cout << ans.X + 1 << ' ' << ans.Y + 1 << endl;
		
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}