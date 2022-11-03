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

int n;
int a[100007];
bool prime[100007];
int pos[100007];
vec < pair<int, int> > ans;
vec <int> pr;

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n;
	forn(i, n)
		cin >> a[i];
	prime[1] = true;
	form(i, 2, 100001){
		if (prime[i] == false){
			pr.pb(i);
			for(ll j = (ll)2 * i; j <= 100001; j += (ll)i)
					prime[j] = true;
		}
	}
	forn(i, n)
	    pos[a[i]] = i;
    cout << LN;
	form(i, 1, n){
		while(pos[i] != i - 1){
			int rast = pos[i] - (i - 1) + 1;
			vec <int> :: iterator it1 = lower_bound(all(pr), rast);
			int my_rast;
			if (*it1 == rast)
			    my_rast = *it1;
			else
			    my_rast = *(--it1);
			int new_pos = pos[i] - my_rast + 1;
			ans.pb(mp(new_pos, pos[i]));
			swap(pos[i], pos[a[new_pos]]);
			swap(a[pos[a[new_pos]]], a[new_pos]);
		}
	}

	cout << ans.size() << LN;
	forn(i, ans.size())
		cout << ans[i].XX + 1 << ' ' << ans[i].YY + 1 << LN;
}