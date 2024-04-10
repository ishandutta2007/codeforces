#include<bits/stdc++.h>
using namespace std;
int B=450;
int n,m,x[200005],y[200005],t[200005];
int d[803][803],op,k,sum[200005];
void upd(int p,int t,int num,int x,int y){
	t=(t+x)%p;
	while(y--)d[p][t]+=num,t=(t+1)%p;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&op,&k);
		if(op==1){
			t[k]=i;
			if(x[k]+y[k]<=B)upd(x[k]+y[k],i,1,x[k],y[k]);
			else{
				for(int l=i+x[k],r=i+x[k]+y[k];l<=m;l+=x[k]+y[k],r+=x[k]+y[k]){
					sum[l]++;
					if(r<=m)sum[r]--;
				}
			}
		}else{
			if(x[k]+y[k]<=B)upd(x[k]+y[k],t[k],-1,x[k],y[k]);
			else{
				int T=t[k];
				for(int l=T+x[k],r=T+x[k]+y[k];l<=m;l+=x[k]+y[k],r+=x[k]+y[k]){
					sum[l]--;
					if(i<=r&&r<=m)sum[r]++;
				}
				if((i-1-T)%(x[k]+y[k])>x[k])sum[i]--;
			}
		}
		sum[i]+=sum[i-1];
		int ans=sum[i];
		for(int j=1;j<=B;j++)ans+=d[j][i%j];
		printf("%d\n",ans);
	}
}