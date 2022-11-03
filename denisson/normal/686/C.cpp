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

int n, m, len, len1, len2;
ll ans = 0;

vec <int> get(int a){
	vec <int> ans;

	while (1){
		if (a < 7){
			ans.pb(a);
			break;
		}
		ans.pb(a % 7);
		a = a / 7;
	}
	reverse(all(ans));
	re ans;
}

int num(vec<int> q){
	int step = 1;
	int ans = 0;
	for (int i = (int)q.size() - 1; i >= 0; i--){
		ans += step * q[i];
		step *= 7;
	}
	re ans;
}

void go(vec<int> q){
	vec<int> q1, q2;
	for (int i = 0; i < len1; i++)
		q1.pb(q[i]);
	for (int i = len1; i < q.size(); i++)
		q2.pb(q[i]);
	int l1 = num(q1);
	int l2 = num(q2);
	if (l1 <= n && l2 <= m){
		ans++;
		/*forn(i, q.size())
			cout << q[i];
		cout << LN;*/
	}
}

void gen(vec<int> &q, str &s){
	if (q.size() == len){
		go(q);
	} else {
		forn(i, 7)
			if (s[i] == '0'){
				s[i] = '1';
				q.push_back(i);
				gen(q, s);
				s[i] = '0';
				q.pop_back();
			}
	}
}

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n >> m;
	n--; m--;
	vec<int> q1 = get(n);
	vec<int> q2 = get(m);
	len = q1.size() + q2.size();
	len1 = q1.size();
	len2 = q2.size();
	if (len > 7)
		cout << 0, exit(0);
	vec<int> q;
	str s = "00000000000";
	gen(q, s);
	cout << ans;
}