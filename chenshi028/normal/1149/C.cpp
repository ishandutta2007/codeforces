#include<cstdio>
using namespace std;
inline int Max(int a,int b){return a>b?a:b;}
const int o=2e5+10;
int n,q;char s[o];
struct segmenttree{int l,r,rb,lb,mx,f1,f2,f3,f4;}nod[o*5];
#define ls id<<1
#define rs (id<<1)|1
inline void update(int id){
	nod[id].rb=nod[ls].rb+Max(0,nod[rs].rb-nod[ls].lb);
	nod[id].lb=nod[rs].lb+Max(0,nod[ls].lb-nod[rs].rb);
	nod[id].mx=Max(Max(nod[ls].mx,nod[rs].mx),Max(nod[ls].f1+nod[rs].f4,nod[ls].f2+nod[rs].f3));
	nod[id].f1=Max(nod[rs].f1,Max(nod[ls].f1-nod[rs].rb+nod[rs].lb,nod[ls].f2+nod[rs].rb+nod[rs].lb));
	nod[id].f2=Max(nod[rs].f2,nod[ls].f2+nod[rs].rb-nod[rs].lb);
	nod[id].f3=Max(nod[ls].f3,Max(nod[rs].f3+nod[ls].rb-nod[ls].lb,nod[rs].f4+nod[ls].rb+nod[ls].lb));
	nod[id].f4=Max(nod[ls].f4,nod[rs].f4+nod[ls].lb-nod[ls].rb);
}
void build(int id,int l,int r){
	nod[id].l=l;nod[id].r=r;
	if(l==r){
		nod[id].mx=nod[id].f1=nod[id].f3=1;
		if(s[l]=='(') nod[id].lb=nod[id].f4=1;else nod[id].rb=nod[id].f2=1;
		return;
	}
	int md=l+r>>1;
	build(ls,l,md);build(rs,md+1,r);
	update(id);
}
void modify(int id,int pos,char c){
	if(nod[id].l==nod[id].r){
		nod[id].mx=nod[id].f1=nod[id].f3=1;
		if(c=='(') nod[id].lb=nod[id].f4=1,nod[id].rb=nod[id].f2=0;
		else nod[id].rb=nod[id].f2=1,nod[id].lb=nod[id].f4=0;
		return;
	}
	if(pos<=(nod[id].l+nod[id].r>>1)) modify(ls,pos,c);
	else modify(rs,pos,c);
	update(id);
}
int main(){
	scanf("%d%d%s",&n,&q,s+1);n=2*n-2;
	build(1,1,n);printf("%d\n",nod[1].mx);
	for(int x,y,z;q--;printf("%d\n",nod[1].mx))
		scanf("%d%d",&x,&y),modify(1,x,s[y]),modify(1,y,s[x]),z=s[x],s[x]=s[y],s[y]=z;
	return 0;
}