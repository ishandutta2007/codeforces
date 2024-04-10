#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E6+8;

_ n, a[maxn], c[maxn], s, r, mx, b[maxn];
stack<_p> st;

int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &c[i]);
	for(_ i = 1; i <= n; ++i) if(c[i] > c[mx]) mx = i;
	_ cnt = 0;
	for(_ i = mx; i <= n; ++i) a[++cnt] = c[i];
	for(_ i = 1; i <= mx-1; ++i) a[++cnt] = c[i];
	a[++n] = c[mx];
	a[0] = a[n+1] = 1E11;
	st.push(make_pair(0LL, 1LL));
	for(_ i = 1; i <= n; ++i) {
		_ t = 0;
		for(; a[st.top().first] <= a[i]; st.pop()) {
			if(a[st.top().first] == a[i]) t += st.top().second;
		}
		b[i] = st.top().first;
		if(st.top().first) ++s;
		if(i != n) s += t;
		st.push(make_pair(i, t+1));
	}
	for(; !st.empty(); ) st.pop();
	st.push(make_pair(n+1, 1LL));
	for(_ i = n; i >= 1; --i) {
		_ t = 0;
		for(; a[st.top().first] <= a[i]; st.pop()) {
			if(a[st.top().first] == a[i]) t += st.top().second;
		}
//		printf("stack %lld %lld %lld\n", i, st.top().first, st.size());
		if(st.top().first != n+1) ++s;
		if(b[i] == 1 && st.top().first == n) --s;
		st.push(make_pair(i, t+1));
	}
	printf("%lld\n", s);
	
	return 0;
}