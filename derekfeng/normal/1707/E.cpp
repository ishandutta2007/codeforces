#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int B=28;
int n,q,a[100004],S,lg[3600],sta[30];
int L[34][100004],R[34][100004];
struct rmq_min{
	int c[100004],pre[100004],suf[100004],st[16][3600],f[100004];
	void init(int *a){
		for(int l=1,i=1;l<n;l+=B,i++){
			int r=min(l+B-1,n-1),msk=0,SZ=0;for(int j=l;j<=r;j++){
				while(SZ&&a[sta[SZ]]>=a[j])msk^=(1<<(sta[SZ]-l)),SZ--;
				sta[++SZ]=j,msk|=(1<<(j-l)),pre[j]=a[sta[1]],f[j]=msk;
			}st[0][i]=pre[r];for(int j=r;j>=l;j--)suf[j]=min(a[j],j<r?suf[j+1]:n+1);
		}
		for(int i=1;i<=lg[S];i++)
			for(int j=1,k=j+(1<<(i-1));j+(1<<i)-1<=S;j++,k++)st[i][j]=min(st[i-1][j],st[i-1][k]);
		for(int i=1;i<n;i++)c[i]=a[i];
	}
	int qry(int l,int r){
		int pl=(l+B-1)/B,pr=(r+B-1)/B;
		if(pl!=pr){int res=min(suf[l],pre[r]);if(pl!=pr-1){
				pl++,pr--;int d=lg[pr-pl];
				res=min(res,min(st[d][pl],st[d][pr-(1<<d)+1]));
			}return res;}int pos=(pl-1)*B+1,Msk=f[r]>>(l-pos);
		return c[l+__builtin_ctz(Msk)];
	}
}rmq0[34];
struct rmq_max{
	int c[100004],pre[100004],suf[100004],st[16][3600],f[100004];
	void init(int *a){
		for(int l=1,i=1;l<n;l+=B,i++){
			int r=min(l+B-1,n-1),msk=0,SZ=0;for(int j=l;j<=r;j++){
				while(SZ&&a[sta[SZ]]<=a[j])msk^=(1<<(sta[SZ]-l)),SZ--;
				sta[++SZ]=j,msk|=(1<<(j-l)),pre[j]=a[sta[1]],f[j]=msk;
			}st[0][i]=pre[r];for(int j=r;j>=l;j--)suf[j]=max(a[j],j<r?suf[j+1]:0);
		}
		for(int i=1;i<=lg[S];i++)
			for(int j=1,k=j+(1<<(i-1));j+(1<<i)-1<=S;j++,k++)st[i][j]=max(st[i-1][j],st[i-1][k]);
		for(int i=1;i<n;i++)c[i]=a[i];
	}
	int qry(int l,int r){
		int pl=(l+B-1)/B,pr=(r+B-1)/B;
		if(pl!=pr){int res=max(suf[l],pre[r]);if(pl!=pr-1){
				pl++,pr--;int d=lg[pr-pl];
				res=max(res,max(st[d][pl],st[d][pr-(1<<d)+1]));
			}return res;}int pos=(pl-1)*B+1,Msk=f[r]>>(l-pos);
		return c[l+__builtin_ctz(Msk)];
	}
}rmq1[34];
int main(){
	scanf("%d%d",&n,&q),S=(n+B-2)/B;
	if(n==1){while(q--)puts("0");return 0;}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=S;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<n;i++)L[0][i]=min(a[i],a[i+1]),R[0][i]=max(a[i],a[i+1]);
	for(int i=0;i<34;i++){
		rmq0[i].init(L[i]),rmq1[i].init(R[i]);
		if(i<33){
			for(int j=1;j<n;j++){
				L[i+1][j]=rmq0[i].qry(L[i][j],R[i][j]-1);
				R[i+1][j]=rmq1[i].qry(L[i][j],R[i][j]-1);
			}
		}
	}
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		if(l==1&&r==n){puts("0");continue;}
		if(l==r){puts("-1");continue;}
		int L=l,R=r;ll ans=0;
		for(int i=33;~i;i--){
			int cL=rmq0[i].qry(L,R-1),cR=rmq1[i].qry(L,R-1);
			if(cL!=1||cR!=n)ans|=1ll<<i,L=cL,R=cR;
		}int pL=rmq0[0].qry(L,R-1),pR=rmq1[0].qry(L,R-1);
		if(pL!=1||pR!=n)puts("-1");else printf("%lld\n",ans+1); 
	}
}