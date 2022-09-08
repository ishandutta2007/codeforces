#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;
const int max_n = 102222, inf = 1000111222;

int n;
char buf[max_n];
string s, rs;

int solve(const string &s) {
	int res = 1, cur = 1;
	for (int i = s.length() - 2; i >= 0; --i) {
		if (s[i] != s[i + 1]) {
			++cur;
			cur = min(cur, n);
		} else {
			cur = 1;
		}
		if (i < s.length()) {
			res = max(res, cur);
		}
	}
	return res;
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	ios::sync_with_stdio(false); cin.tie(0);
	scanf("%s", buf);
	s = buf;
	rs = s;
	n = s.length();
	reverse(rs.begin(), rs.end());
	s += s;
	rs += rs;
	printf("%d\n", min(solve(s), solve(rs)));
	return 0;
}