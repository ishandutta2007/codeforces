#include <bits/stdc++.h>
using namespace std;
typedef double db;
const int N=1e5+5,M=(1<<20)+5;
int n,m,a[N],h[N],b[N],l[N],r[N],z[N],nn;
vector<int>all;
db dat[M],ans;
int lb(int x){
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
void upd(int l,int r,int i,int a,int b,db x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		dat[i]*=x;
		return;
	}
	int md=(l+r)>>1;
	upd(l,md,i<<1,a,b,x),upd(md+1,r,i<<1|1,a,b,x);
}
db qry(int l,int r,int i,int p){
	if(l==r)return dat[i];
	int md=(l+r)>>1;
	if(p<=md)return qry(l,md,i<<1,p)*dat[i];
	return qry(md+1,r,i<<1|1,p)*dat[i];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d%d%d",&a[i],&h[i],&l[i],&r[i]),all.push_back(a[i]-h[i]),all.push_back(a[i]),all.push_back(a[i]+1),all.push_back(a[i]+h[i]+1);
	for(int i=1;i<=m;i++)scanf("%d%d",&b[i],&z[i]),all.push_back(b[i]);
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end()),nn=all.size();
	for(int i=0;i<M;i++)dat[i]=1;
	for(int i=1;i<=n;i++){
		int L,R;
		db mul;
		L=lb(a[i]-h[i]),R=lb(a[i])-1;
		mul=(db)(100-l[i])/100;
		upd(1,nn,1,L,R,mul);
		L=lb(a[i]+1),R=lb(a[i]+h[i]+1)-1;
		mul=(db)(100-r[i])/100;
		upd(1,nn,1,L,R,mul);
	}
	for(int i=1;i<=m;i++)ans+=qry(1,nn,1,lb(b[i]))*z[i];
	printf("%.10lf",ans);
}