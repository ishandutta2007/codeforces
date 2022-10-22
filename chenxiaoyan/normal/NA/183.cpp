#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 50000
#define pb push_back
char s[N+10];
vector<int> ord;
int oc[N+1],cc[N+1],o[N+1];
inline bool cmp(int x,int y){return oc[x]-cc[x]>oc[y]-cc[y];}
struct node{int l,r,lz,mn;}nd[N*4];
#define l(x) nd[x].l
#define r(x) nd[x].r
#define lz(x) nd[x].lz
#define mn(x) nd[x].mn
void bld(int p,int l,int r){
	l(p)=l;r(p)=r;
	if(l==r){mn(p)=o[l];return;}
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
signed main(){
	int n,bal=0,cost=0,i;scanf("%s",s+1);n=strlen(s+1);
	if(n&1)return !printf("-1");
	for(i=1;i<=n;i++){
		if(s[i]=='?'){
			ord.pb(i);s[i]='(';
			scanf("%lld%lld",oc+i,cc+i);cost+=oc[i];
		}
		int delta=s[i]==')'?-1:1;
		o[i]=o[i-1]+delta;bal+=delta;
		if(bal<0)return !printf("-1");
	}
	bld(1,1,n);
	sort(ord.begin(),ord.end(),cmp);
	for(i=0;i<ord.size()&&bal;i++){
		int x=ord[i];
		if(ask(1,x,n).mn>=2){
			chg(1,x,n,-2);
			s[x]=')';
			cost-=oc[x];cost+=cc[x];
			bal-=2;
		}
	}
	printf(bal?"-1":"%lld\n%s",cost,s+1);
	return 0;
}
/*1
(??)
1 2
2 8
*/