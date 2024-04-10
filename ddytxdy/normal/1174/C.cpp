#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,a[N],now;bool vis[N];
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		if(vis[i])continue;
		a[i]=++now;
		for(LL j=1ll*i*i;j<=n;j+=i)if(!vis[j]){
			vis[j]=1;a[j]=now;
		}
	}
	for(int i=2;i<=n;i++)printf("%d ",a[i]);
	return 0;
}