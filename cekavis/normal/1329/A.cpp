#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, m, a[N], ans[N];
ll s[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; ++i) scanf("%d", a+i);
	for(int i=m; i; --i) s[i]=s[i+1]+a[i];
	a[0]=1;
	for(int i=1; i<=m; ++i){
		ans[i]=max(ans[i-1]+1ll, n-s[i]+1);
		if(ans[i]-ans[i-1]>a[i-1] || ans[i]>n-a[i]+1) return puts("-1"), 0;
	}
	for(int i=1; i<=m; ++i) printf("%d%c", ans[i], " \n"[i==m]);
	return 0;
}