#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int myp(int x,int t){
	int ans=1;
	for(;t;x=(ll)x*x%M,t>>=1)if(t&1)ans=(ll)ans*x%M;
	return ans;
}
int inv[200005],fac[200005],ans;
void init(){
	fac[0]=1;
	for(int i=1;i<200005;i++)fac[i]=(ll)fac[i-1]*i%M;
	inv[200004]=myp(fac[200004],M-2);
	for(int i=200004;i;i--)inv[i-1]=(ll)inv[i]*i%M;
}
int n,m,s[200004],t[200004],h=1;
int cnt[200004],bit[200004];
void upd(int i,int x){
	for(;i<=2e5;i+=i&-i)(bit[i]+=x)%=M;
}
int qry(int i){
	int r=0;
	for(;i;i-=i&-i)(r+=bit[i])%=M;
	return r;
}
int getd(int x){
	if(x==0)return 0;
	return (ll)fac[x]*inv[x-1]%M;
}
void del(int c){
	if(cnt[c]==0){printf("%d",ans);exit(0);}
	int mul=getd(cnt[c]);h=(ll)h*mul%M;
	upd(c,M-mul),cnt[c]--;
	if(cnt[c]>0)mul=getd(cnt[c]),upd(c,mul);
}
void calc(int i,int c){
	(ans+=(ll)fac[n-i]*h%M*qry(c-1)%M)%=M;
}
int main(){
	init(),scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]),cnt[s[i]]++;
	for(int i=1;i<=m;i++)scanf("%d",&t[i]);
	h=1;
	for(int i=1;i<=2e5;i++)if(cnt[i]){
		upd(i,getd(cnt[i]));
		h=(ll)h*inv[cnt[i]]%M;
	}
	for(int i=1;i<=n&&i<=m;i++){
		if(i>1)del(t[i-1]);
		calc(i,t[i]);
	}
	if(n<m)del(t[n]),(ans+=1)%=M;
	printf("%d",ans);
}