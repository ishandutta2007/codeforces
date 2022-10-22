#include<bits/stdc++.h>
using namespace std;
int n,a[15005];
int f[15005],g[15005];
int nf[15005],ng[15005];
int bit1[15005],bit2[15005];
void upd1(int i,int x){
	for(;i;i-=i&-i)bit1[i]=min(bit1[i],x);
}
int qry1(int i){
	int ans=n+1;
	for(;i<=n;i+=i&-i)ans=min(ans,bit1[i]);
	return ans;
}
void upd2(int i,int x){
	for(;i<=n;i+=i&-i)bit2[i]=max(bit2[i],x);
}
int qry2(int i){
	int ans=0;
	for(;i;i-=i&-i)ans=max(ans,bit2[i]);
	return ans;
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)f[i]=n+1,g[i]=0;
	f[n]=g[n]=a[n];
	int ans=0;
	for(int t=1;;t++){
		bool ok=0;
		for(int i=1;i<=n;i++)ok|=(f[i]<=n||g[i]>=1);
		if(!ok){
			ans=t-1;
			break;
		}
		fill(bit1,bit1+n+1,n+1);
		fill(bit2,bit2+n+1,0);
		for(int i=n;i;i--){
			if(i+1<=n)upd1(a[i+1],f[i+1]);
			if(i+t<=n)upd1(g[i+t],a[i+t]);
			nf[i]=qry1(a[i]);
			if(i+1<=n)upd2(a[i+1],g[i+1]);
			if(i+t<=n)upd2(f[i+t],a[i+t]);
			ng[i]=qry2(a[i]);
		}
		memcpy(f,nf,(n+2)<<2);
		memcpy(g,ng,(n+2)<<2);
	}
	for(int i=1;i<=n;i++)f[i]=g[i]=a[i];
	for(int t=2;;t++){
		bool ok=0;
		for(int i=1;i<=n;i++)ok|=(f[i]<=n||g[i]>=1);
		if(!ok){
			ans=max(ans,t-2);
			break;
		}
		fill(bit1,bit1+n+1,n+1);
		fill(bit2,bit2+n+1,0);
		for(int i=n;i;i--){
			if(i+1<=n)upd1(a[i+1],f[i+1]);
			if(i+t<=n)upd1(g[i+t],a[i+t]);
			nf[i]=qry1(a[i]);
			if(i+1<=n)upd2(a[i+1],g[i+1]);
			if(i+t<=n)upd2(f[i+t],a[i+t]);
			ng[i]=qry2(a[i]);
		}
		memcpy(f,nf,(n+2)<<2);
		memcpy(g,ng,(n+2)<<2);
	}
	printf("%d\n",ans);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}