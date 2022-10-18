#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, tc, cl[maxn], cc, dfn[maxn], low[maxn], cnt, dg[maxn];
vector<_> g[maxn];
_p a[maxn], b[maxn];
stack<_> st;
bitset<maxn> v;

void paint(_ x);
void tarjan(_ x);
int main() {
	
	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) {
			scanf("%lld", &a[i].first);
			a[i].second = i;
		}
		for(_ i = 1; i <= n; ++i) {
			scanf("%lld", &b[i].first);
			b[i].second = i;
		}
		sort(a+1, a+1+n);
		sort(b+1, b+1+n);
		for(_ i = 1; i <= n; ++i) {
			g[i].clear();
			dfn[i] = low[i] = dg[i] = 0;
			v.reset(i);
		}
		for(_ i = n; i >= 2; --i) {
			g[a[i].second].push_back(a[i-1].second);
			g[b[i].second].push_back(b[i-1].second);
		}
		cnt = cc = 0;
		for(_ i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);
		for(_ i = 1; i <= n; ++i) for(_ j : g[i]) if(cl[i] != cl[j]) ++dg[cl[j]];
		_ r = 0, t = 0;
		for(_ i = 1; i <= cc; ++i) if(!dg[i]) {
			++r;
			t = i;
		}
		for(_ i = 1; i <= n; ++i) printf("%lld",  (_)(cl[i] == t));
		putchar(10);
	}
	
	return 0;
}

void tarjan(_ x) {
	low[x] = dfn[x] = ++cnt;
	st.push(x);
	v.set(x);
	for(_ i : g[x]) {
		if(!dfn[i]) {
			tarjan(i);
			low[x] = min(low[x], low[i]);
		} ef(v[i]) low[x] = min(low[x], dfn[i]);
	}
	if(low[x] == dfn[x]) {
		++cc;
		for(; st.top() != x; ) paint(st.top());
		paint(x);
	}
	return;
}

void paint(_ x) {
	st.pop();
	v.reset(x);
	cl[x] = cc;
	return;
}