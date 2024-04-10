#include<bits/stdc++.h>
using namespace std;
#define N 100000
int n,a[N+1],b[N+1];
struct node{int l,r,sta,stb;}nd[N<<2];
#define l(x) nd[x].l
#define r(x) nd[x].r
#define sta(x) nd[x].sta
#define stb(x) nd[x].stb
void bld(int l=1,int r=n,int p=1){
//	printf("[%d,%d]:%d\n",l,r,p);
	l(p)=l;r(p)=r;sta(p)=0;
	if(l==r){stb(p)=l;return;}
	int mid=l+r>>1;
	bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
}
void spr(int p){
	if(sta(p)){
		int sta=sta(p),stb=stb(p);sta(p)=0;
		sta(p<<1)=sta(p<<1|1)=sta,stb(p<<1)=stb(p<<1|1)=stb;
	}
}
void chg(int l,int r,int sta,int stb,int p=1){
	if(l<=l(p)&&r>=r(p)){sta(p)=sta;stb(p)=stb;return;}
	spr(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid)chg(l,r,sta,stb,p<<1);
	if(r>mid)chg(l,r,sta,stb,p<<1|1);
}
int ask(int x,int p=1){
	if(l(p)==r(p))return sta(p)+l(p)-stb(p);
	spr(p);
	int mid=l(p)+r(p)>>1;
	return ask(x,p<<1|(x>mid));
}
int main(){
	int qu,i;scanf("%d%d",&n,&qu);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)scanf("%d",b+i);
	bld();
	while(qu--){
		int kind,x,y,z;scanf("%d",&kind);
		if(kind==1)scanf("%d%d%d",&x,&y,&z),chg(y,y+z-1,x,y);
		else{
			scanf("%d",&x);
			int ans=ask(x);
			printf("%d\n",ans?a[ans]:b[x]);
		}
	}
	return 0;
}
/*1
5 10
1 2 0 -1 3
3 1 5 -2 0
2 5
1 3 3 3
2 5
2 4
2 1
1 2 1 4
2 1
2 4
1 4 2 1
2 2
*/