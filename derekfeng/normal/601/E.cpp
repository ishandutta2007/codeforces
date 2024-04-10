#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P=1e7+19,Q=1e9+7;
int n,k,q,ans[300003];
int v[35003],w[35003],l[35003],r[35003],f[1003];
bool qry[30003];
bool tg[1100000];
vector<int>d[1100000];
int pw[1003];
void upd(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		d[i].push_back(x);
		return;
	}
	int md=(l+r)>>1;
	upd(i<<1,l,md,a,b,x),upd(i<<1|1,md+1,r,a,b,x);
}
void init(int i,int l,int r){
	if(l==r)tg[i]=qry[l];
	else{
		int md=(l+r)>>1;
		init(i<<1,l,md),init(i<<1|1,md+1,r);
		tg[i]=tg[i<<1]|tg[i<<1|1];
	}
}
void sol(int i,int l,int r){
	if(!tg[i])return;
	int nf[1003];memcpy(nf,f,(k+2)<<2);
	for(auto x:d[i])
		for(int i=k;i>=w[x];i--)
			f[i]=max(f[i],f[i-w[x]]+v[x]);
	if(l==r){
		int tmp=0;
		for(int j=1;j<=k;j++)
			(tmp+=(ll)f[j]*pw[j-1]%Q)%=Q;
		ans[l]=tmp;
	}else{
		int md=(l+r)>>1;
		sol(i<<1,l,md),sol(i<<1|1,md+1,r);
	}
	memcpy(f,nf,(k+2)<<2);
}
int main(){
	for(int i=0;i<1003;i++)pw[i]=i==0?1:(ll)pw[i-1]*P%Q;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d%d",&v[i],&w[i]),l[i]=1;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			++n,scanf("%d%d",&v[n],&w[n]);
			l[n]=i;
		}
		if(op==2){
			int x;scanf("%d",&x);
			r[x]=i;
		}
		if(op==3)qry[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(!r[i])r[i]=q;
		upd(1,1,q,l[i],r[i],i);
	}
	init(1,1,q);
	sol(1,1,q);
	for(int i=1;i<=q;i++)if(qry[i])printf("%d\n",ans[i]);
}