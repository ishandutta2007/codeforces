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

str s;
int pos[100007];
int ans = -1, uk = 0;
stack < pair<char, int> > st;

const bool is_testing = 0;
int main()
{
	srand(time(NULL));
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> s;
	forn(i, s.size() + 1)
		pos[i] = -1;
	forn(i, s.size()){
		if (s[i] == '(' || s[i] == '['){
			st.push(mp(s[i], i));
		} else {
			if (st.size() > 0){
				if (st.top().XX == '(' && s[i] == ')' || 
					st.top().XX == '[' && s[i] == ']'){
					pos[st.top().YY] = i;
					pos[i] = st.top().YY;
					st.pop();
				}
				else
					while (st.size() > 0)
						st.pop();
			}
		}
	}
	int now = 0, start = -1;
	forn(i, s.size() + 1){
		if (pos[i] == -1){
			if (start != -1){
				if (now >= ans & now != 0)
					ans = now, uk = start;
			}
			now = 0;
			start = -1;
		} else {
			if (start == -1){
				start = i;
			} 
			if (s[i] == '[')
				now++;
		}
	}
	if (ans == -1) 
		cout << 0, exit(0);
	cout << ans << LN;
	while(pos[uk] != -1)
		cout << s[uk], uk++;
}