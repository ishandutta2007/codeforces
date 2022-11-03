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
#define write(x) printf("%d", &x)
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
const ll MOD = 1e9 + 7;

int n, m, k;
int a[100007], b[100007];
vec < pair<int ,int> > q1, q2;

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n >> m >> k;
	forn(i, n)
		cin >> a[i];
	forn(i, m)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	forn(i, n){
		if (q1.size() == 0)
			q1.pb(mp(a[i], 1));
		else{
			if (q1.back().XX == a[i])
				q1.back().YY++;
			else
				q1.pb(mp(a[i], 1));
		}
	}
	
	forn(i, m){
		if (q2.size() == 0)
			q2.pb(mp(b[i], 1));
		else{
			if (q2.back().XX == b[i])
				q2.back().YY++;
			else
				q2.pb(mp(b[i], 1));
		}
	}

	reverse(all(q1));
	reverse(all(q2));
	vec < pair< pair<int, int>, int > > t;
	forn(i, q1.size())
		t.pb(mp(mp(q1[i].XX, -1), q1[i].YY));
	forn(i, q2.size())
		t.pb(mp(mp(q2[i].XX, 1), q2[i].YY));
	sort(all(t));
	reverse(all(t));
	int bal = 0;
	forn(i, t.size()){
		int type = t[i].XX.YY;
		int kol = t[i].YY;
		bal -= kol * type;
		if (bal > 0)
			cout << "YES", exit(0);
	}
	cout << "NO";
}