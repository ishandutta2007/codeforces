#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int T,n,m;
int f[N],b[N];
bool vis[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);int mn=m;
		for(int i=1;i<=m;i++)vis[i]=0,b[i]=0;
		for(int i=1,x;i<=n;i++){
			scanf("%d",&x);
			vis[x]=1,mn=min(mn,x);
		}
		for(int i=1;i<=m;i++){
			f[i]=i;
			if(vis[i])b[i]++;
		}
		int ans=m,res=m;
		for(int i=m;i;i--){
			if(i>1&&i<=10000){
				for(int j=i;i*j<=m;j++){
					if(vis[i*j])b[f[i*j]]--;
					f[i*j]=min(f[i*j],max(f[j],i));
					if(vis[i*j])b[f[i*j]]++;
				}
			}
			while(!b[ans])ans--;
			if(i<=mn)res=min(res,ans-i);
		}
		printf("%d\n",res);
	}
}