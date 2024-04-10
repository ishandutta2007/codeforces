#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=300000;
int n;
int a[N+1],b[N+1];
int pos[N+1];
struct segtree{
	struct node{int l,r,mn_dif,lz;}nd[N<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define mn_dif(p) nd[p].mn_dif
	#define lz(p) nd[p].lz
	void bld(int l=1,int r=n,int p=1){
		l(p)=l;r(p)=r;mn_dif(p)=inf;lz(p)=0;
		if(l==r)return;
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
	}
	void init(){bld();}
	void sprup(int p){mn_dif(p)=min(mn_dif(p<<1),mn_dif(p<<1|1));}
	void sprdwn(int p){
		if(lz(p)){
			mn_dif(p<<1)+=lz(p);mn_dif(p<<1|1)+=lz(p);
			lz(p<<1)+=lz(p);lz(p<<1|1)+=lz(p);
			lz(p)=0;
		}
	}
	void on(int x,int p=1){
		if(l(p)==r(p)){mn_dif(p)=lz(p);return;}
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		on(x,p<<1|(x>mid));
		sprup(p);
	}
	void add(int l,int r,int v,int p=1){
		if(l<=l(p)&&r>=r(p)){mn_dif(p)+=v;lz(p)+=v;return;}
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		if(l<=mid)add(l,r,v,p<<1);
		if(r>mid)add(l,r,v,p<<1|1);
		sprup(p);
	}
	int _mn_dif(){return mn_dif(1);}
}segt;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],pos[a[i]]=i;
	for(int i=1;i<=n;i++)cin>>b[i];
	int now=n;
	cout<<now<<" ";
	segt.init();
	segt.on(pos[n]);
	segt.add(1,pos[n],-1);
	for(int i=1;i<n;i++){
		segt.add(1,b[i],1);
		while(segt._mn_dif()>=0){
			now--;
			segt.on(pos[now]);
			segt.add(1,pos[now],-1);
		}
		cout<<now<<" ";
	}
	return 0;
}