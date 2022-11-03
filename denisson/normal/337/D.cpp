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

int n, m, d, ans = 0;
vec <int> g[100007];
bool bad[100007];
int d1[100007], d2[100007];
pair<int, int> pod[100007];

void sd(pair<int, int> &a, int b){
	if (a.XX == -INF){
		a.XX = b;
	} else {
		if (a.YY == -INF){
			a.YY = b;
			if (a.YY > a.XX)
				swap(a.YY, a.XX);
		} else {
			if (a.XX < b){
				a.YY = a.XX;
				a.XX = b;
			} else {
				a.YY = max(a.YY, b);
			}
		}
	}
}

int dfs(int v, int pred){
	pod[v] = mp(-INF, -INF);
	forn(i, g[v].size()){
		int to = g[v][i];
		if (to != pred){
			int q = dfs(to, v);
			sd(pod[v], q);
		}
	}
	if (pod[v].XX != -INF)
		pod[v].XX++;
	if (pod[v].YY != -INF)
		pod[v].YY++;
	if (bad[v])
		sd(pod[v], 0);
	if (pod[v].XX != -INF)
		d1[v] = pod[v].XX;
	else
		d1[v] = -INF;
	re d1[v];
}

void dfs2(int v, int pred){
	if (pred != -1){
		d2[v] = -INF;
		if (d2[pred] != -INF)
			d2[v] = d2[pred] + 1;
		if (d1[v] + 1 == pod[pred].XX){
			if (pod[pred].YY != -INF){
				d2[v] = max(d2[v], pod[pred].YY+ 1);
			}
		} else {
			if (pod[pred].XX != -INF){
				d2[v] = max(d2[v], pod[pred].XX + 1);
			}
		}
	}
	forn(i, g[v].size()){
		int to = g[v][i];
		if (to != pred){
			dfs2(to, v);
		}
	}
}

const bool is_testing = 0;
int main()
{
	srand(3252);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n >> m >> d;
	forn(i, m){
		int x;
		scanf("%d", &x);
		bad[--x] = 1;
	}
	forn(i, n - 1){
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	d2[0] = -INF;
	dfs2(0, -1);
	forn(i, n)
		if (d1[i] <= d && d2[i] <= d)
			ans++;
	//forn(i, n)
	//	cout << i + 1 << ' ' << d1[i] << ' ' << d2[i] << LN;
		//cout << i + 1 << ' ' << pod[i].XX << ' ' << pod[i].YY << LN;
	cout << ans;
}