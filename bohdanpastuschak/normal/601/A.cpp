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

int n, m;
const int N = 407;
int a[N][N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	FOR(i, 0, n) FOR(j, 0, i) a[i][j] = a[j][i] = 1;
	while(m--){
		int x, y;
		cin >> x >> y;
		--x; --y;
		a[x][y] = a[y][x] = 2;
	}

	if (a[0][n - 1] == 1){
		FOR(i, 0, n) FOR(j, 0, i){
			a[i][j] = a[j][i] = 3 - a[i][j];
		}		
	}

	vector<int> d(n, -1);
	d[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		FOR(i, 0, n) if (a[v][i] == 1 && d[i] == -1){
			d[i] = d[v] + 1;
			q.push(i);
		}
	}
	
	cout << d[n - 1] << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}