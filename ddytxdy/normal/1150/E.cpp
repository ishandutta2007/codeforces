#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mymax(x,y) (x>y?x:y)
#define mymin(x,y) (x<y?x:y)
using namespace std;
const int N=2e5+50;
int n,q,x,y,num[N];char c[N];
struct node{
	int l,r,maxn,minn,sum,d1,d2,d3;
	void New(){
		if(c[l]=='(')sum=maxn=minn=1,d2=d3=-1,d1=0;
		else sum=maxn=minn=-1,d2=d3=1,d1=0;
	}
	void print(){
		printf("[%d,%d]=={%d %d %d %d %d %d}\n",l,r,maxn,minn,sum,d1,d2,d3);
	}
}t[N*4];
node merge(node a,node b){
	node ret;
	ret.l=a.l;ret.r=b.r;
	ret.maxn=mymax(a.maxn,a.sum+b.maxn);
	ret.minn=mymin(a.minn,a.sum+b.minn);
	ret.sum=a.sum+b.sum;
	ret.d1=mymax(mymax(a.d1,b.d1),mymax(a.d2+a.sum+b.maxn,a.maxn+b.d3-a.sum));
	ret.d2=mymax(mymax(a.d2,b.d2-a.sum),a.maxn-2*(a.sum+b.minn));
	ret.d3=mymax(mymax(a.d3,b.d3-a.sum),-2*a.minn+b.maxn+a.sum);
	return ret;
}
void build(int x,int l,int r){
	t[x].l=l;t[x].r=r;
	if(l==r){num[l]=x;t[x].New();return;}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	t[x]=merge(t[x<<1],t[x<<1|1]);
}
//void change(int x){
//	x>>=1;
//	while(x){
//		t[x]=merge(t[x<<1],t[x<<1|1]);
//		x>>=1;
//	}
//}
void change(int x,int p1,int p2){
	if((p1>t[x].r||p1<t[x].l)&&(p2>t[x].r||p2<t[x].l))return;
	if(t[x].l==t[x].r){
		t[x].New();//printf("%d ",t[x].l);
		return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(p1<=mid||p2<=mid)change(x<<1,p1,p2);
	if(p1>mid||p2>mid)change(x<<1|1,p1,p2);
	t[x]=merge(t[x<<1],t[x<<1|1]);
}
int main(){
	scanf("%d%d%s",&n,&q,c+1);
	n=2*(n-1);
	build(1,1,n);
	printf("%d\n",t[1].d1);
	while(q--){
		scanf("%d%d",&x,&y);
		if(c[x]!=c[y]){
			swap(c[x],c[y]);
			//t[num[x]].New();
			//t[num[y]].New();
			change(1,x,y);//change(num[y]);
		}
		printf("%d\n",t[1].d1);
	}
	return 0;
}