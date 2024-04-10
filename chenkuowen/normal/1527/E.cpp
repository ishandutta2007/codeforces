#include<bits/stdc++.h>
using namespace std;
const int N=35005;
int a[N],b[N],lst[N],nxt[N];
struct OP{
	int l,r,ans;
	OP(){ l=1,r=0,ans=0; }
	void move(int x,int y){
		for(;r<y;++r) if(lst[r+1]>=l) ans+=(r+1)-lst[r+1];
		for(;r>y;--r) if(lst[r]>=l) ans-=r-lst[r];
		for(;l<x;++l) if(nxt[l]<=r) ans-=nxt[l]-l;
		for(;l>x;--l) if(nxt[l-1]<=r) ans+=nxt[l-1]-(l-1);
	}
}op;
void solve(int f1[],int l1,int r1,int f2[],int l2,int r2){
	if(l1>r1) return;
	int m1=l1+r1>>1,m2=l2;
	f1[m1]=(int)1e9;
	for(int i=l2;i<=r2&&i+1<=m1;++i){
		op.move(i+1,m1);
		if(f2[i]+op.ans<f1[m1]) 
			f1[m1]=f2[i]+op.ans,m2=i;
	}
//	printf("[%d]",f1[m1]);
	solve(f1,l1,m1-1,f2,l2,m2);
	solve(f1,m1+1,r1,f2,m2,r2);
}
int f[N],g[N];
int main(){
	int n,k; scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) b[i]=0;
	for(int i=1;i<=n;++i) lst[i]=b[a[i]],b[a[i]]=i;
	for(int i=1;i<=n;++i) b[i]=n+1;
	for(int i=n;i>=1;--i) nxt[i]=b[a[i]],b[a[i]]=i;
	for(int i=1;i<=n;++i) f[i]=(int)1e9; f[0]=0;
	for(int t=1;t<=k;++t){
		solve(g,0,n,f,0,n);
		memcpy(f,g,sizeof(int)*(n+1));
	}
	printf("%d\n",f[n]);
	return 0;
}