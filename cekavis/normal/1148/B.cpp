#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int n, m, ta, tb, k, ans, a[N], b[N];
int main() {
	scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), a[i]+=ta;
	for(int i=1; i<=m; ++i) scanf("%d", b+i);
	if(k>=n || k>=m) return puts("-1"), 0;
	for(int i=0; i<=k; ++i){
		int j=lower_bound(b+1, b+m+1, a[i+1])-b;
		if(i+m-j+1<=k) return puts("-1"), 0;
		ans=max(ans, b[j+k-i]);
	}
	return printf("%d", ans+tb), 0;
}