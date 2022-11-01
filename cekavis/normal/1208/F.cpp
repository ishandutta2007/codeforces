#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005, M = 1<<21;
int n, r, ans, a[N], q[M+5], cnt[M], f[M];
bool vis[M];
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=n; i; --i){
		q[r=1]=a[i], vis[a[i]]=1;
		for(int l=1; l<=r; ++l){
			int u=q[l];
			if(++cnt[u]==2) f[u]=i;
			if(cnt[u]>2) continue;
			for(int j=0; j<21; ++j) if((u>>j&1) && !vis[u^(1<<j)])
				vis[q[++r]=u^(1<<j)]=1;
		}
		for(int l=1; l<=r; ++l) vis[q[l]]=0;
	}
	for(int i=1; i<=n-2; ++i){
		int now=0;
		for(int j=20; ~j; --j) if(!(a[i]>>j&1) && f[now|(1<<j)]>i) now|=1<<j;
		ans=max(ans, a[i]+now);
	}
	printf("%d\n", ans);
	return 0;
}