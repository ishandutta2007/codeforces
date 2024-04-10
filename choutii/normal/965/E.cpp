#include <bits/stdc++.h>

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

const int MaxN = 201234;

int n, ans, ch[MaxN][26], t[MaxN], cnt; char s[MaxN];

void add(char *s) {
	int n = strlen(s + 1), p = 0; ans += n;
	for (int i = 1; i <= n; i++) {
		int &q = ch[p][s[i] - 'a']; if(!q) q = ++cnt; p = q;
	}
	t[p] = 1;
}

multiset <int> f[MaxN]; 
void dfs(int x) {
	for (int c = 0; c < 26; c++) {
		if(!ch[x][c]) continue;
		dfs(ch[x][c]);
		for (auto i : f[ch[x][c]])
			f[x].insert(i + 1);
	}
	if(t[x]) f[x].insert(0);
	else {
		if(x) {
			ans -= *f[x].rbegin();
			f[x].erase(f[x].find(*f[x].rbegin())); f[x].insert(0);
		}
	}
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		add(s);
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}