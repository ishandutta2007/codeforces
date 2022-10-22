/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200000;
int n;
bool a[N+1];
vector<int> son[N+1];
int dfn[N+1],mxdfn[N+1],nowdfn,mng[N+1];
void dfs(int x=1){
	dfn[x]=mxdfn[x]=++nowdfn;
	mng[dfn[x]]=x;
	for(int i=0;i<son[x].size();i++){
		int y=son[x][i];
		dfs(y);
		mxdfn[x]=max(mxdfn[x],mxdfn[y]);
	}
}
struct segtree{
	struct node{int l,r,cnt;bool lz;}nd[N<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define cnt(p) nd[p].cnt
	#define lz(p) nd[p].lz
	void sprup(int p){cnt(p)=cnt(p<<1)+cnt(p<<1|1);}
	void bld(int l=1,int r=n,int p=1){
		l(p)=l;r(p)=r;lz(p)=false;
		if(l==r){cnt(p)=a[mng[l]];return;}
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
		sprup(p);
	}
	void init(){bld();}
	void sprdwn(int p){
		if(lz(p)){
			cnt(p<<1)=r(p<<1)-l(p<<1)+1-cnt(p<<1);lz(p<<1)^=1;
			cnt(p<<1|1)=r(p<<1|1)-l(p<<1|1)+1-cnt(p<<1|1);lz(p<<1|1)^=1;
			lz(p)=0;
		}
	}
	void rev(int l,int r,int p=1){
		if(l<=l(p)&&r>=r(p)){cnt(p)=r(p)-l(p)+1-cnt(p);lz(p)^=1;return;}
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		if(l<=mid)rev(l,r,p<<1);
		if(r>mid)rev(l,r,p<<1|1);
		sprup(p);
	}
	int _cnt(int l,int r,int p=1){
		if(l<=l(p)&&r>=r(p))return cnt(p);
		sprdwn(p);
		int mid=l(p)+r(p)>>1,res=0;
		if(l<=mid)res+=_cnt(l,r,p<<1);
		if(r>mid)res+=_cnt(l,r,p<<1|1);
		return res;
	}
}segt;
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		son[x].pb(i);
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs();
	segt.init();
	int qu;
	cin>>qu;
	while(qu--){
		string a;
		int x;
		cin>>a>>x;
		if(a=="get")printf("%d\n",segt._cnt(dfn[x],mxdfn[x]));
		else segt.rev(dfn[x],mxdfn[x]);
	}
	return 0;
}