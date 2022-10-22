#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int o=5e5+10;const long long inf=1e18;
int n,q,L[o],R[o],K[o];long long a[3][o],ans=-inf,mx[o*4],mxdp[o*4],mxf[o*4],dp[o];vector<int> vec[o];
inline void update(int id){
	mxdp[id]=max(mxdp[id<<1],mxdp[(id<<1)|1]);mxf[id]=max(mxf[id<<1],mxf[(id<<1)|1]);
	mx[id]=max(max(mx[id<<1],mx[(id<<1)|1]),mxdp[id<<1]+mxf[(id<<1)|1]);
}
inline void build(int id,int l,int r){
	if(l==r){mx[id]=(mxdp[id]=a[0][l]-a[1][l-1])+(mxf[id]=a[1][l]+a[2][l]);return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
	update(id);
}
void modify(int id,int pos,long long val,int l=1,int r=n){
	if(l==r){mxdp[id]=max(mxdp[id],val);return;}
	int md=l+r>>1;
	if(pos<=md) modify(id<<1,pos,val,l,md);
	else modify((id<<1)|1,pos,val,md+1,r);
	update(id);
}
long long querydp(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return mxdp[id];
	int md=l+r>>1;
	return max(ql<=md?querydp(id<<1,ql,qr,l,md):-inf,md<qr?querydp((id<<1)|1,ql,qr,md+1,r):-inf);
}
pair<pair<long long,long long>,long long> query(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return make_pair(make_pair(mxdp[id],mxf[id]),mx[id]);
	int md=l+r>>1;
	if(qr<=md) return query(id<<1,ql,qr,l,md);
	if(md<ql) return query((id<<1)|1,ql,qr,md+1,r);
	pair<pair<long long,long long>,long long> ls=query(id<<1,ql,qr,l,md),rs=query((id<<1)|1,ql,qr,md+1,r);
	return make_pair(make_pair(max(ls.first.first,rs.first.first),max(ls.first.second,rs.first.second)),
	max(max(ls.second,rs.second),ls.first.first+rs.first.second));
}
int main(){
	scanf("%d%d",&n,&q);dp[0]=-inf;
	for(int i=0;i<3;++i) for(int j=1;j<=n;++j) scanf("%lld",&a[i][j]);
	for(int i=1;i<=n;dp[i++]=-inf) a[0][i]+=a[0][i-1],a[1][i]+=a[1][i-1];
	for(int i=n;i;--i) a[2][i]+=a[2][i+1];
	build(1,1,n);
	for(int i=1;i<=q;++i) scanf("%d%d%d",&L[i],&R[i],&K[i]),vec[R[i]].push_back(i);
	for(int i=1;i<=n;modify(1,i,dp[i]),++i) for(int j=vec[i].size();j--;)
		dp[i]=max(dp[i],max(querydp(1,L[vec[i][j]],i),dp[L[vec[i][j]]-1])-K[vec[i][j]]);
	for(int i=1;i<=q;++i) ans=max(ans,max(query(1,L[i],R[i]).second,dp[L[i]-1]+query(1,L[i],R[i]).first.second)-K[i]);
	printf("%lld",ans);
	return 0;
}