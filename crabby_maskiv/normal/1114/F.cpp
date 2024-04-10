#include<bits/stdc++.h>
#define get1(p) (s[p].tag1==1?s[p].sum:(s[p].sum*po(s[p].tag1,s[p].r-s[p].l+1)%mod))
#define get2(p) (s[p].num|s[p].tag2)
using namespace std;
typedef long long ll;
const int N=400005;
const ll mod=1e9+7;
int n,m;
int a[N];
ll b[N];
struct sgt{
	int ls,rs,l,r;
	ll tag1,tag2,num,sum;
}s[3*N];
int rt,P;
ll po(ll x,ll k){
	if(!k) return 1;
	ll s=po(x,k>>1);s=s*s%mod;
	if(k&1) return s*x%mod;
	return s;
}
void upd(int p){
	s[p].sum=get1(s[p].ls)*get1(s[p].rs)%mod;
	s[p].num=get2(s[p].ls)|get2(s[p].rs);
}
void pushd(int p){
	s[p].sum=get1(p);
	s[p].num=get2(p);
	s[s[p].ls].tag1=s[s[p].ls].tag1*s[p].tag1%mod;
	s[s[p].rs].tag1=s[s[p].rs].tag1*s[p].tag1%mod;
	s[s[p].ls].tag2|=s[p].tag2;s[s[p].rs].tag2|=s[p].tag2;
	s[p].tag1=1;s[p].tag2=0;
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	s[p].tag1=1;
	if(l==r){
		s[p].num=b[l];
		s[p].sum=a[l];
		return p;
	}
	int mid=(l+r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
vector<int> pri;
void change(int p,int l,int r,int x){
	if(s[p].l==l&&s[p].r==r){
		for(int i=0;i<pri.size();i++){
			if(x%pri[i]==0)
				s[p].tag2|=(1ll<<i);
		}
		s[p].tag1=s[p].tag1*x%mod;
		return;
	}
	pushd(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) change(s[p].ls,l,r,x);
	else if(l>mid) change(s[p].rs,l,r,x);
	else{
		change(s[p].ls,l,mid,x);
		change(s[p].rs,mid+1,r,x);
	}
	upd(p);
}
pair<ll,ll> query(int p,int l,int r){
	if(s[p].l==l&&s[p].r==r){
		return make_pair(get1(p),get2(p));
	}
	pushd(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) return query(s[p].ls,l,r);
	else if(l>mid) return query(s[p].rs,l,r);
	else{
		pair<ll,ll> q1=query(s[p].ls,l,mid),q2=query(s[p].rs,mid+1,r);
		return make_pair(q1.first*q2.first%mod,q1.second|q2.second);
	}
}
ll inv[N];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	inv[1]=1;
	for(i=2;i<=300;i++){
		inv[i]=(-(mod/i)*inv[mod%i]%mod+mod)%mod;
		for(j=2;j*j<=i;j++)
			if(i%j==0) break;
		if(j*j>i) pri.push_back(i);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(j=0;j<pri.size();j++)
			if(a[i]%pri[j]==0) b[i]|=(1ll<<j);
	}
	rt=build(1,n);
	while(m--){
		string s;cin>>s;
		int l,r,x;
		if(s=="TOTIENT"){
			scanf("%d%d",&l,&r);
			pair<ll,ll> q=query(rt,l,r);
			for(i=0;i<pri.size();i++){
				if(q.second&(1ll<<i)){
					q.first=q.first*inv[pri[i]]%mod;
					q.first=q.first*(pri[i]-1)%mod;
				}
			}
			printf("%I64d\n",q.first);
		}
		else{
			scanf("%d%d%d",&l,&r,&x);
			change(rt,l,r,x);
		}
	}
	return 0;
}