#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400005;
int n,m;
struct sgt{
	int ls,rs,l,r;
	ll sum,tag;
}s[6*N];
int rtl,rtr,P;
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	s[p].sum=s[p].tag=s[p].ls=s[p].rs=0;
	if(l==r) return p;
	int mid=(s[p].l+s[p].r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	return p;
}
inline int get(int p){
	return s[p].sum+s[p].tag*(s[p].r-s[p].l+1);
}
inline void upd(int p){
	s[p].sum=get(s[p].ls)+get(s[p].rs);
}
inline void pushd(int p){
	if(!s[p].tag) return;
	s[s[p].ls].tag+=s[p].tag;
	s[s[p].rs].tag+=s[p].tag;
	s[p].sum=get(p);
	s[p].tag=0;
}
void chg(int p,int l,int r,int x){
	if(s[p].l==l&&s[p].r==r){
		s[p].tag+=x;
		return;
	}
	pushd(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) chg(s[p].ls,l,r,x);
	else if(l>mid) chg(s[p].rs,l,r,x);
	else{
		chg(s[p].ls,l,mid,x);
		chg(s[p].rs,mid+1,r,x);
	}
	upd(p);
}
ll qry(int p,int l,int r){
	if(s[p].l==l&&s[p].r==r)
		return get(p);
	pushd(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) return qry(s[p].ls,l,r);
	else if(l>mid) return qry(s[p].rs,l,r);
	else return qry(s[p].ls,l,mid)+qry(s[p].rs,mid+1,r);
}
vector<pair<int,int> > vl[N],vr[N];
ll sa[N],ea[N],sb[N],eb[N];
int len;
ll x[N];
void solve(){
	int i,j,k;
	for(i=1;i<=len;i++){
		vl[i].clear();
		vr[i].clear();
	}
	P=0;
	rtl=build(1,len);
	rtr=build(1,len);
	for(i=1;i<=n;i++){
		vl[sa[i]].push_back({sb[i],eb[i]});
		vr[ea[i]].push_back({sb[i],eb[i]});
		chg(rtr,sb[i],eb[i],1);
	}
	for(i=1;i<=len;i++){
		for(auto p:vl[i])
			chg(rtr,p.first,p.second,-1);
		for(auto p:vr[i]){
			if(qry(rtr,p.first,p.second)){
				cout<<"NO";
				exit(0);
			}
			chg(rtl,p.first,p.second,1);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>sa[i]>>ea[i]>>sb[i]>>eb[i];
		x[++len]=sa[i];
		x[++len]=ea[i];
		x[++len]=sb[i];
		x[++len]=eb[i];
	}
	sort(x+1,x+len+1);
	for(i=1;i<=n;i++){
		sa[i]=lower_bound(x+1,x+len+1,sa[i])-x;
		ea[i]=lower_bound(x+1,x+len+1,ea[i])-x;
		sb[i]=lower_bound(x+1,x+len+1,sb[i])-x;
		eb[i]=lower_bound(x+1,x+len+1,eb[i])-x;
	}
	solve();
	for(i=1;i<=n;i++){
		swap(sa[i],sb[i]);
		swap(ea[i],eb[i]);
	}
	solve();
	cout<<"YES";
	return 0;
}