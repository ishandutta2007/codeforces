#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50,M=1e6+50;
int n,mn[N],mx[N],fl[N],c[M],cnt;LL ans;
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		for(int j=1,y,la;j<=x;j++){
			scanf("%d",&y);
			if(j==1)mx[i]=y;
			if(j==x)mn[i]=y;
			if(j!=1&&y>la)fl[i]=1;
			la=y;
		}
	}
	for(int i=1;i<=n;i++)
		if(!fl[i])c[mn[i]]++;else cnt++;
	ans=2ll*cnt*n-1ll*cnt*cnt;
	for(int i=1;i<M;i++)c[i]+=c[i-1];
	for(int i=1;i<=n;i++)
		if(!fl[i])ans+=c[mx[i]-1];
	cout<<ans;
	return 0;
}