#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
int dat[1158576][41],l[300004],r[300004],cnt[1158576],a[20],b[20],n_,cur,n,m;
bool vis[300004];
ll ans=0;
void upd(int l,int r,int id,int a,int b){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		cnt[id]++;
		return;
	}
	upd(l,(l+r)/2,id*2+1,a,b),upd((l+r)/2+1,r,id*2+2,a,b);
}
ll inv[600004],num[600004];
void init(){ 
	inv[1]=1;
	for (int i=2;i<=6e5;i++)
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD; 
	inv[0]=num[0]=1;
	for(int i=1;i<=6e5;i++)
		num[i]=num[i-1]*i%MOD,inv[i]=inv[i-1]*inv[i]%MOD;
}
ll C(int A,int B){
	return num[A]*inv[A-B]%MOD*inv[B]%MOD;
}
void built(int l,int r,int id){
	cur+=cnt[id];
	if(l==r){
		if(cur>=l)for(int i=0;i<=min(40,l);i++)dat[id][i]=C(cur-i,l-i);
	}else{
		built(l,(l+r)/2,id*2+1),built((l+r)/2+1,r,id*2+2); 
		for(int i=0;i<41;i++)dat[id][i]=(dat[id*2+1][i]+dat[id*2+2][i])%MOD;
	}
	cur-=cnt[id];
}
int got(int l,int r,int id,int a,int b,int x){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b){
		return dat[id][x];
	}
	return (got(l,(l+r)/2,id*2+1,a,b,x)+got((l+r)/2+1,r,id*2+2,a,b,x))%MOD;
}
int main(){
	init();
	cin>>n>>m;n_=1;
	while(n_<n)n_<<=1;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
		upd(1,n_,0,l[i],r[i]);
	}
	for(int i=0;i<m;i++)cin>>a[i]>>b[i];
	built(1,n_,0);
	for(int i=0;i<(1<<m);i++){
		int L=1,R=3e5;
		int cnt1=0;
		for(int j=0;j<m;j++)if((1<<j)&i){
			if(!vis[a[j]]){
				vis[a[j]]=1,cnt1++;
				L=max(L,l[a[j]]),R=min(R,r[a[j]]);
			}
			if(!vis[b[j]]){
				vis[b[j]]=1,cnt1++;
				L=max(L,l[b[j]]),R=min(R,r[b[j]]);
			}
		}
		if(__builtin_popcount(i)%2==0)ans=(ans+got(1,n_,0,L,R,cnt1))%MOD;
		else ans=(ans-got(1,n_,0,L,R,cnt1)+MOD)%MOD;
		for(int j=0;j<m;j++)vis[a[j]]=0,vis[b[j]]=0;
	}
	cout<<ans<<"\n";
}