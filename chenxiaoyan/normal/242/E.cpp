#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100000
#define LOGA 20
int n;
bitset<LOGA+1> a[N+1];
struct node{int l,r,no[LOGA+1];bool lz[LOGA+1];}nd[N<<2];
#define l(x) nd[x].l
#define r(x) nd[x].r
#define no(x) nd[x].no
#define lz(x) nd[x].lz
#define len(x) (r(x)-l(x)+1)
void bld(int l=1,int r=n,int p=1){
	int i;
	l(p)=l;r(p)=r;for(i=0;i<=LOGA;i++)lz(p)[i]=false;
	if(l==r){
		for(i=0;i<=LOGA;i++)no(p)[i]=a[l][i];
		return;
	}
	int mid=l+r>>1;
	bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
	for(i=0;i<=LOGA;i++)no(p)[i]=no(p<<1)[i]+no(p<<1|1)[i];
}
void spr(int p){
	for(int i=0;i<=LOGA;i++)if(lz(p)[i]){
		lz(p)[i]=false;
		no(p<<1)[i]=len(p<<1)-no(p<<1)[i];no(p<<1|1)[i]=len(p<<1|1)-no(p<<1|1)[i];
		lz(p<<1)[i]^=1;lz(p<<1|1)[i]^=1;
	}
}
void chg(int l,int r,int v,int p=1){
	int i;
	if(l<=l(p)&&r>=r(p)){
		for(i=0;i<=LOGA;i++)if(v&1<<i)no(p)[i]=len(p)-no(p)[i],lz(p)[i]^=1;
		return;
	}
	spr(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid)chg(l,r,v,p<<1);
	if(r>mid)chg(l,r,v,p<<1|1);
	for(i=0;i<=LOGA;i++)no(p)[i]=no(p<<1)[i]+no(p<<1|1)[i];
}
int ask(int l,int r,int p=1){
	if(l<=l(p)&&r>=r(p)){
		int res=0;
		for(int i=0;i<=LOGA;i++)res+=no(p)[i]<<i;
		return res;
	}
	spr(p);
	int mid=l(p)+r(p)>>1,res=0;
	if(l<=mid)res+=ask(l,r,p<<1);
	if(r>mid)res+=ask(l,r,p<<1|1);
	return res;
}
signed main(){
	int qu;scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%lld",&x);
		for(int j=0;j<=LOGA;j++)a[i][j]=x&1<<j;
	}
	bld();
	scanf("%lld",&qu);
	while(qu--){
		int kd,x,y,z;scanf("%lld%lld%lld",&kd,&x,&y);
		if(kd==1)printf("%lld\n",ask(x,y));
		else scanf("%lld",&z),chg(x,y,z);
	}
	return 0;
}
/*1
5
4 10 3 13 7
8
1 2 4
2 1 3 3
1 2 4
1 3 3
2 2 5 5
1 1 5
2 1 2 10
1 2 3
*/
/*2
6
4 7 4 0 7 3
5
2 2 3 8
1 1 5
2 3 5 1
2 4 5 6
1 2 3
*/