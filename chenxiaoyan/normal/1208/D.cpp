/*








 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=200000;
int n;
int a[N+1];
struct segtree{
	struct node{int l,r,mn,lz;}nd[N<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define mn(p) nd[p].mn
	#define lz(p) nd[p].lz
	void sprup(int p){mn(p)=min(mn(p<<1),mn(p<<1|1));}
	void bld(int l=1,int r=n,int p=1){
		l(p)=l;r(p)=r;lz(p)=0;
		if(l==r){mn(p)=a[l];return;}
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
		sprup(p);
	}
	void init(){bld();}
	void sprdwn(int p){
		if(lz(p)){
			int x=lz(p);
			lz(p)=0;
			mn(p<<1)+=x;mn(p<<1|1)+=x;
			lz(p<<1)+=x;lz(p<<1|1)+=x;
		}
	}
	void add(int l,int r,int v,int p=1){
		if(l<=l(p)&&r>=r(p)){mn(p)+=v;lz(p)+=v;return;}
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		if(l<=mid)add(l,r,v,p<<1);
		if(r>mid)add(l,r,v,p<<1|1);
		sprup(p);
	}
	int las0(){
		int p=1;
		while(l(p)<r(p)){
			sprdwn(p);
			p<<=1;
			if(mn(p|1)==0)p|=1;
		}
		return l(p);
	}
}segt;
int ans[N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	segt.init();
	for(int i=1;i<=n;i++){
		int las0=segt.las0();
//		cout<<las0<<"\n";
		ans[las0]=i;
		segt.add(las0+1,n,-i);
		segt.add(las0,las0,inf);
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}