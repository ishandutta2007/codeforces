#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const int mod=1e9+9;
const int sq=383008016;
const int isq=276601605;
const int A=691504013;
const int B=308495997;
int n,m;
int poa[N],pob[N];
struct sgt{
	int l,r,ls,rs;
	int tag1,tag2,sum1,sum2;
}s[3*N];
int P,rt;
int a[N];
inline int get1(int p){
	return (s[p].sum1+ll(poa[s[p].r-s[p].l+1]-1)*A%mod*s[p].tag1)%mod;
}
inline int get2(int p){
	return (s[p].sum2+ll(pob[s[p].r-s[p].l+1]-1)*B%mod*s[p].tag2)%mod;
}
inline void pushd(int p){
	int len=s[s[p].ls].r-s[s[p].ls].l+1;
	s[s[p].rs].tag1=(s[s[p].rs].tag1+poa[len]*ll(s[p].tag1))%mod;
	s[s[p].rs].tag2=(s[s[p].rs].tag2+pob[len]*ll(s[p].tag2))%mod;
	s[s[p].ls].tag1=(s[s[p].ls].tag1+s[p].tag1)%mod;
	s[s[p].ls].tag2=(s[s[p].ls].tag2+s[p].tag2)%mod;
	s[p].sum1=get1(p);
	s[p].sum2=get2(p);
	s[p].tag1=s[p].tag2=0;
}
inline void upd(int p){
	s[p].sum1=(get1(s[p].ls)+get1(s[p].rs))%mod;
	s[p].sum2=(get2(s[p].ls)+get2(s[p].rs))%mod;
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	if(l==r){
		s[p].sum1=a[l];
		return p;
	}
	int mid=(l+r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
void chg(int p,int l,int r,int x1,int x2){
	if(s[p].l==l&&s[p].r==r){
		s[p].tag1=(s[p].tag1+x1)%mod;
		s[p].tag2=(s[p].tag2+x2)%mod;
		return;
	}
	pushd(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) chg(s[p].ls,l,r,x1,x2);
	else if(l>mid) chg(s[p].rs,l,r,x1,x2);
	else{
		chg(s[p].ls,l,mid,x1,x2);
		x1=ll(x1)*poa[mid-l+1]%mod;
		x2=ll(x2)*pob[mid-l+1]%mod;
		chg(s[p].rs,mid+1,r,x1,x2);
	}
	upd(p);
}
int qry(int p,int l,int r){
	if(s[p].l==l&&s[p].r==r){
		return (get1(p)-get2(p)+mod)%mod;
	}
	pushd(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) return qry(s[p].ls,l,r);
	else if(l>mid) return qry(s[p].rs,l,r);
	else return (qry(s[p].ls,l,mid)+qry(s[p].rs,mid+1,r))%mod;
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	poa[0]=pob[0]=1;
	for(i=1;i<N;i++){
		poa[i]=poa[i-1]*ll(A)%mod;
		pob[i]=pob[i-1]*ll(B)%mod;
	}
	rt=build(1,n);
	int op,x,y;
	while(m--){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
			chg(rt,x,y,isq*ll(A)%mod,isq*ll(B)%mod);
		else printf("%d\n",qry(rt,x,y));
	//	for(i=1;i<=n;i++) cout<<qry(rt,i,i)<<" ";
	//	cout<<endl;
	}
	return 0;
}