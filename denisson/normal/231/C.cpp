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

int n, k;
int a[100007];
ll sum[100007];
pair<int, int> ans = mp(0, 0);

ll get(int l, int r){
	if (l == 0)
		re sum[r];
	re sum[r] - sum[l - 1];
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
	cin >> n >> k;
	forn(i, n)
		read(a[i]);
	sort(a, a + n);
	sum[0] = a[0];
	form(i, 1, n - 1)
		sum[i] = sum[i - 1] + a[i];
	forn(i, n){
		int l = -1, r = i;
		while (l + 1 < r){
			int m = (l + r) / 2;
			if ((ll)(i - m + 1) * a[i] - get(m, i) <= k)
				r = m;
			else
				l = m;
		}
		if (ans.YY < i - r + 1){
			ans.YY = i - r + 1;
			ans.XX = a[i];
		} else if(ans.YY == i - r + 1){
			ans.XX = min(ans.XX, a[i]);
		}
	}
	cout << ans.YY << ' ' << ans.XX;
}