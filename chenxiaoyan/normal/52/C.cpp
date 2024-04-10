#include<bits/stdc++.h>
using namespace std;
#define N 200000
#define ll long long
ll a[N+1];
struct node{int l,r;ll mn,lz;}nd[4*N];
#define l(x) nd[x].l
#define r(x) nd[x].r
#define mn(x) nd[x].mn
#define lz(x) nd[x].lz
void bld(int p,int l,int r){
	l(p)=l;r(p)=r;lz(p)=0;
	if(l==r){mn(p)=a[l];return;}
	int mid=l+r>>1;
	bld(p<<1,l,mid);bld(p<<1|1,mid+1,r);
	mn(p)=min(mn(p<<1),mn(p<<1|1));
}
void spr(int p){
	if(lz(p)){
		int x=lz(p);lz(p)=0;
		mn(p<<1)+=x;mn(p<<1|1)+=x;
		lz(p<<1)+=x;lz(p<<1|1)+=x;
	}
}
void chg(int p,int l,int r,int v){
	if(l<=l(p)&&r>=r(p)){mn(p)+=v;lz(p)+=v;return;}
	spr(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid)chg(p<<1,l,r,v);if(r>mid)chg(p<<1|1,l,r,v);
	mn(p)=min(mn(p<<1),mn(p<<1|1));
}
node ask(int p,int l,int r){
	if(l<=l(p)&&r>=r(p))return nd[p];
	spr(p);
	int mid=l(p)+r(p)>>1;
	if(r<=mid)return ask(p<<1,l,r);
	if(l>mid)return ask(p<<1|1,l,r);
	node a=ask(p<<1,l,r),b=ask(p<<1|1,l,r),c;
	c.mn=min(a.mn,b.mn);
	return c;
}
int main(){
	int n,qu,i;scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%lld",a+i);
	bld(1,1,n);
	scanf("%d\n",&qu);
	while(qu--){
		char s[100];gets(s);
		int sp=0,len=strlen(s),l,r,v;
		for(i=0;i<len;i++)sp+=s[i]==' ';
		if(sp==1){
			sscanf(s,"%d%d",&l,&r);l++;r++;
			printf("%lld\n",l<=r?ask(1,l,r).mn:min(ask(1,l,n).mn,ask(1,1,r).mn));
		}
		else{
			sscanf(s,"%d%d%d",&l,&r,&v);l++;r++;
			if(l<=r)chg(1,l,r,v);
			else chg(1,l,n,v),chg(1,1,r,v);
		}
	}
	return 0;
}
/*1
4
1 2 3 4
4
3 0
3 0 -1
0 1
2 1
*/