#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//
#define read(x) scanf("%d", &x)
#define write(x) printf("%d", x)
#define writeln(x) printf("%d\n", x)
#define wp(x) cout << x.first << ' ' << x.second << '\n';
#define wm(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' '; cout << LN;
#define read2(x, y) scanf("%d %d", &x, &y)
//
#define sqr(x) x*x
#define clr(a, x) memset(a, x, sizeof(a));
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const int P1 = 239017;
const int P2 = 353251;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

int x0, y0, x1, y1;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
set< pair<int, int> > can;
set< pair<int, int> > was;
vec < pair<pair<int, int>, int> > d;

bool ok(pair<int, int> a){
	re (a.XX >= 1 && a.YY >= 1 && a.XX <= 1000000000 && a.YY <= 1000000000);
}

void add(int x, int y, int d1){
	if (ok(mp(x, y)) && !was.count(mp(x, y)) && can.count(mp(x, y))){
		was.insert(mp(x, y));
		d.pb(mp(mp(x, y), d1 + 1));
	}
}

const bool is_testing = 0;
int main()
{
	srand(time(NULL));
	if (is_testing)
	{
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	}
	cin >> x0 >> y0 >> x1 >> y1;
	int n;
	cin >> n;
	forn(i, n){
		int r, a, b;
		cin >> r >> a >> b;
		form(j, a, b)
			can.insert(mp(r, j));
	}
	int uk = 0;
	add(x0, y0, 0);
	while (uk < d.size()){
		pair<pair<int, int>, int> now = d[uk++];
		if (now.XX == mp(x1, y1)){
			cout << now.YY - 1;
			exit(0);
		}
		forn(i, 8)
			add(now.XX.XX + dx[i], now.XX.YY + dy[i], now.YY);
	}
	cout << -1;
	if (is_testing){
		cout << LN << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}