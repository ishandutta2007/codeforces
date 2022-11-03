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
const int l = 20;

str s1, s2;
int pref[200007], pos1[200007], suf[200007], pos2[200007];
vec<int> d[1007];


const bool is_testing = 0;
int main()
{
	srand(time(NULL));
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> s1 >> s2;
	if (s1.size() < s2.size())
		cout << "No", exit(0);
	if (s2[(int)s2.size() - 1] != s1[(int)s1.size() - 1])
			cout << "No", exit(0);
	//
	forn(i, s2.size())
		d[s2[i]].pb(i);
	//
	pref[0] = 0;
	pos1[0] = 0;
	for (int i = 1; i < s1.size(); i++){
		int ma = min(pref[i - 1] + 1, (int)s2.size() - 1);
		if (d[s1[i]].size() == 0)
			cout << "No", exit(0);
		int l = -1, r = d[s1[i]].size();
		while (l + 1 < r){
			int m = (l + r) / 2;
			if (d[s1[i]][m] <= ma)
				l = m;
			else
				r = m;
		}
		if (d[s1[i]][l] > ma)
			cout << "No", exit(0);
		pos1[i] = d[s1[i]][l];
		pref[i] = max(pref[i - 1], pos1[i]);
	}
	suf[(int)s1.size() - 1] = (int)s2.size() - 1;
	pos2[(int)s1.size() - 1] = (int)s2.size() - 1;
	for (int i = (int)s1.size() - 2; i >= 0; i--){
		int mi = max(0, suf[i + 1] - 1);
		//if (d[s1[i]][j] >= mi){
		if (d[s1[i]].size() == 0)
			cout << "No", exit(0);
		int l = -1, r = d[s1[i]].size();
		while (l + 1 < r){
			int m = (l + r) / 2;
			if (d[s1[i]][m] < mi)
				l = m;
			else
				r = m;
		}
		if (d[s1[i]][r] < mi)
			cout << "No", exit(0);
		pos2[i] = d[s1[i]][r];
		suf[i] = min(suf[i + 1], pos2[i]);
	}
	forn(i, s1.size()){
		bool f = 0;
		int pos = pos1[i];
		int poss = pos2[i];
		if (pos >= poss)
			f = 1;
		if (!f)
			cout << "No", exit(0);
	}
	cout << "Yes";
}