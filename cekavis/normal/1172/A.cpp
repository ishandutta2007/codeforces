#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int n, ans, a[N], b[N];
int main() {
	scanf("%d", &n);
	for(int i=1, x; i<=n; ++i) scanf("%d", &x);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), b[a[i]]=i;
	for(int i=b[1]; i<=n; ++i) if(a[i]!=i-b[1]+1) goto nxt;
	for(int i=1; i<b[1]; ++i) if(a[i] && i>=a[i]-a[n]) goto nxt;
	return printf("%d", n-a[n]), 0;
	nxt:;
	for(int i=1; i<=n; ++i) if(b[i]) ans=max(ans, b[i]-i+1);
	return printf("%d", ans+n), 0;
}