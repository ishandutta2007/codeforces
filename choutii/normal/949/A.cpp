#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 201234;

int n, x[MaxN]; char s[MaxN];

vector <int> ans[MaxN], ed[2];
 
int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	if(s[1] == '1') 
		return puts("-1"), 0;
	ans[1].pb(1); ed[0].pb(1); int cnt = 1;
	
	for (int i = 2; i <= n; i++) {
		if(s[i] == '0') {
			if(SZ(ed[1])) {
				int to = ed[1].back(); ed[1].pop_back();
				ans[to].pb(i); ed[0].pb(to);
			} else {
				++cnt; ans[cnt].pb(i); ed[0].pb(cnt);
			}
		} else {
			if(!SZ(ed[0]))
				return puts("-1"), 0;
			int to = ed[0].back(); ed[0].pop_back();
			ans[to].pb(i); ed[1].pb(to);
		}
	}
	for (int i = 1; i <= cnt; i++)
		if(s[ans[i].back()] == '1')
			return puts("-1"), 0;
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++) {
		printf("%d ", SZ(ans[i]));
		for (auto x : ans[i])
			printf("%d ", x);
		puts("");
	}
	return 0;
}