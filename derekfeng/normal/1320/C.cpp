#include<bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second 
const int M=1e6,n_=(1<<20);
const ll INF=1e10;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
int n,m,p,X,Y,C;
vector<int>swd[1000004],arm[1000004];
vector<pii>midian[1000004];
void pushin(vector<int>&v,int x){
	if(v.empty())v.push_back(x);
	else if(v[0]>x)v[0]=x;
}
ll smlst(vector<int>&v){
	if(v.empty())return INF;
	return v[0];
}
ll dat[2098000],ans=-INF,ret[2098000];
void add(int l,int r,int id,int a,int b,ll x){
	if(b<l || r<a) return;
	if(a<=l && r<=b){
		dat[id]+=x,ret[id]+=x;
		return;
	}
	add(l,(l+r)/2,id*2,a,b,x),add((l+r+1)/2,r,id*2+1,a,b,x);
	dat[id]=max(dat[id*2],dat[id*2+1])+ret[id];
}
int main(){
	read(n),read(m),read(p);
	for(int i=1;i<=n;i++)
		read(X),read(C),pushin(swd[X],C);
	for(int i=1;i<=m;i++)
		read(X),read(C),pushin(arm[X],C);
	for(int i=1;i<=p;i++)
		read(X),read(Y),read(C),midian[X].push_back(mkp(Y,C));
	ll now=INF;
	add(1,n_,1,1,n_,-INF);
	for(int i=M;i>=1;i--){
		now=min(now,smlst(arm[i]));
		add(1,n_,1,i,i,INF-now);
	}
	for(int i=1;i<=M;i++){
		for(int j=0;j<midian[i-1].size();j++){
			pii W=midian[i-1][j];
			add(1,n_,1,W.fi+1,n_,W.se);
		}
		now=smlst(swd[i]);
		if(now>1e9)continue;
		ans=max(ans,dat[1]-now);
	}
	cout<<ans;
}