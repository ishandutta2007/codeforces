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

int n, k;
bool was[10];
ll ans = 0;

void ok(vec<int> &q){
	for (int i = 1; i < q.size(); i++) {
		forn(i, 9)
			was[i] = 0;
		int uk = i;
		while(1){
			if (uk < i)
				break;
			if (was[uk])
				re;
			was[uk] = 1;
			uk = q[uk] - 1;
		}
	}
	ans++;
}

void gen(vec<int> &q){
	if (q.size() == k){
		ok(q);
	} else {
		form(i, 1, k){
			q.push_back(i);
			gen(q);
			q.pop_back();
		}
	}
}

ll bin(ll a, ll k){
	if (k == 1)
		re a;
	if (k % 2 == 0){
		ll b = bin(a, k / 2);
		re (b * b) % MOD;
	} else {
		re (a * bin(a, k - 1)) % MOD;
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
	cin >> n >> k;
	vec<int> q;
	gen(q);
	if (n - k == 0)
		cout << ans;
	else {
		//(n-k)^(n-k)
		ans = (ans * bin(n - k, n - k)) % MOD;
		cout << ans;
	}
}