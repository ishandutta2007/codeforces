#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[2][100005],b[2][100005];
ll f[262200][2][2];
void built(int i,int l,int r){
	if(r<l)return;
	if(l==r){
		for(int p=0;p<2;p++)for(int q=0;q<2;q++){
			int xa=a[p][l-1],xb=b[p][l-1];
			if(p)xb++;else xa++;
			int ya=a[q][l],yb=b[q][l];
			f[i][p][q]=abs(xa-ya)+abs(xb-yb)+1;
		}
	}else{
		int md=(l+r)>>1;
		built(i<<1,l,md),built(i<<1|1,md+1,r);
		for(int p=0;p<2;p++)for(int q=0;q<2;q++){
			ll tmp=1e18;
			for(int s=0;s<2;s++)
				tmp=min(tmp,f[i<<1][p][s]+f[i<<1|1][s][q]);
			f[i][p][q]=tmp;
		}
	}
}
ll dp[2],ndp[2];
void calc(int i,int l,int r,int a,int b){
	if(r<l||b<a)return;
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		ndp[0]=ndp[1]=1e18;
		for(int p=0;p<2;p++)for(int q=0;q<2;q++)
			ndp[q]=min(ndp[q],dp[p]+f[i][p][q]);
		dp[0]=ndp[0],dp[1]=ndp[1];
		return;
	}
	int md=(l+r)>>1;
	calc(i<<1,l,md,a,b),calc(i<<1|1,md+1,r,a,b);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		for(int j=0;j<2;j++)scanf("%d%d",&a[j][i],&b[j][i]);
	built(1,2,n-1);
	int q;scanf("%d",&q);
	while(q--){
		int xa,xb,ya,yb;
		scanf("%d%d%d%d",&xa,&xb,&ya,&yb);
		if(max(xa,xb)==max(ya,yb))printf("%d\n",abs(xa-ya)+abs(xb-yb));
		else{
			int p=max(xa,xb),q=max(ya,yb);
			if(p>q)swap(p,q),swap(xa,ya),swap(xb,yb);
			for(int i=0;i<2;i++)dp[i]=abs(xa-a[i][p])+abs(xb-b[i][p])+1;
			calc(1,2,n-1,p+1,q-1);
			ll ans=1e18;
			for(int i=0;i<2;i++){
				int Xa=a[i][q-1],Xb=b[i][q-1];
				if(i)Xb++;else Xa++;
				ans=min(ans,dp[i]+abs(Xa-ya)+abs(Xb-yb));
			}
			printf("%lld\n",ans);
		}
	}
}