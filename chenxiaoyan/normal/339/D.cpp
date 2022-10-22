#include<bits/stdc++.h>
using namespace std;
const int N=1<<17;
int a[N+1];
struct node{int l,r,v;bool Or;}nd[N<<1];
#define l(x) nd[x].l
#define r(x) nd[x].r
#define v(x) nd[x].v
#define Or(x) nd[x].Or
void bld(int l,int r,int p=1){
	l(p)=l;r(p)=r;
	if(l==r){Or(p)=false;v(p)=a[l];return;}
	int mid=l+r>>1;
	bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
	Or(p)=!Or(p<<1);
	if(Or(p))v(p)=(v(p<<1)|v(p<<1|1));
	else v(p)=(v(p<<1)^v(p<<1|1));
}
void chg(int x,int v,int p=1){
	if(l(p)==r(p)){v(p)=v;return;}
	int mid=l(p)+r(p)>>1;
	chg(x,v,p<<1|(x>mid));
	if(Or(p))v(p)=(v(p<<1)|v(p<<1|1));
	else v(p)=(v(p<<1)^v(p<<1|1));
}
int main(){
	int n,qu;scanf("%d%d",&n,&qu);n=1<<n;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	bld(1,n);
	while(qu--){
		int x,v;scanf("%d%d",&x,&v);
		chg(x,v);printf("%d\n",v(1));
	}
	return 0;
}
/*1
2 4
1 6 3 5
1 4
3 4
1 2
1 2
*/