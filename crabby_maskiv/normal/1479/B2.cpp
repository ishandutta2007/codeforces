#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;
struct sgt{
	int l,r,ls,rs;
	int mn,tag;
}s[N*3];
int rt,P;
inline void pushd(int p){
	if(!s[p].tag) return;
	if(s[p].ls) s[s[p].ls].tag+=s[p].tag;
	if(s[p].rs) s[s[p].rs].tag+=s[p].tag;
	s[p].mn+=s[p].tag;
	s[p].tag=0;
}
inline void upd(int p){
	s[p].mn=min(s[s[p].ls].mn,s[s[p].rs].mn);
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;s[p].mn=n+1;
	if(l==r) return p;
	int mid=l+r>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
void chg(int p,int pos,int x){
	pushd(p);
	if(s[p].l==s[p].r){
		s[p].mn=min(s[p].mn,x);
		return;
	}
	int mid=s[p].l+s[p].r>>1;
	if(pos<=mid){
		chg(s[p].ls,pos,x);
		pushd(s[p].rs);
	}
	else{
		chg(s[p].rs,pos,x);
		pushd(s[p].ls);
	}
	upd(p);
}
int qry(int p,int l,int r){
	pushd(p);
	if(s[p].l==l&&s[p].r==r)
		return s[p].mn;
	int mid=s[p].l+s[p].r>>1;
	if(r<=mid) return qry(s[p].ls,l,r);
	else if(l>mid) return qry(s[p].rs,l,r);
	else return min(qry(s[p].ls,l,mid),qry(s[p].rs,mid+1,r));
}
void print(int p){
	pushd(p);
	if(s[p].l==s[p].r){
		cout<<s[p].mn<<" ";
		return;
	}
	print(s[p].ls);
	print(s[p].rs);
}
int a[N];
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	rt=build(0,n+1);
	chg(rt,0,1);
	for(i=2;i<=n;i++){
		int w=min(min(qry(rt,0,a[i]-1),qry(rt,a[i]+1,n+1))+1,qry(rt,a[i],a[i]));
	//	cout<<w<<endl;
		s[rt].tag+=(a[i]!=a[i-1]);
		chg(rt,a[i-1],w);
	//	print(rt);cout<<endl;
	}
	pushd(rt);
	cout<<s[rt].mn;
	return 0;
}