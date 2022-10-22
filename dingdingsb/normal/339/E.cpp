#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,a[N];
int l[N],r[N];
void dfs(int now){
	bool flag=1;
	for(int i=1;i<=n;i++)
		flag&=(i==a[i]);
	if(flag){
		printf("%d\n",now);
		for(int i=now;i>=1;i--)
			printf("%d %d\n",l[i],r[i]);
		exit(0);
	}
	if(now<=2){
		int w[80],cnt=0;
		for(int i=1;i<=n;i++)
			if(abs(a[i]-a[i-1])!=1||abs(a[i]-a[i+1])!=1)
				w[++cnt]=i;
		for(int i=1;i<=cnt;i++)
			for(int j=i+1;j<=cnt;j++){
				reverse(&a[w[i]],&a[w[j]]+1);
				l[now+1]=w[i],r[now+1]=w[j];
				dfs(now+1);
				reverse(&a[w[i]],&a[w[j]]+1);
			}
	}
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[n+1]=n+1;
	dfs(0);
}