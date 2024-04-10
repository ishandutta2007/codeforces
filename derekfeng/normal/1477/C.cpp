#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x[5003],y[5003],now;
bool vis[5003];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	printf("%d ",1);vis[1]=1;now=1;
	for(int i=1;i<n;i++){
		ll dis=0;int pos;
		for(int j=1;j<=n;j++)if(!vis[j]&&dis<1ll*(x[now]-x[j])*(x[now]-x[j])+1ll*(y[now]-y[j])*(y[now]-y[j]))
			dis=1ll*(x[now]-x[j])*(x[now]-x[j])+1ll*(y[now]-y[j])*(y[now]-y[j]),pos=j;
		printf("%d ",pos),now=pos,vis[now]=1;
	}
}