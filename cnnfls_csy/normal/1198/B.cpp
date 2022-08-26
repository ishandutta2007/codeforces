#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
using namespace std;
int n,m,i,j,op,x,y,a[200005];
int tag[800005];
void build(int x,int l,int r)
{
	if(l==r){
		tag[x]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(x+x,l,mid);
	build(x+x+1,mid+1,r);
}
void upd(int x,int y)
{
	tag[x]=max(tag[x],y);
}
void pushdo(int x)
{
	if(tag[x]){
		upd(x+x,tag[x]);
		upd(x+x+1,tag[x]);
		tag[x]=0;
	}
}
void update(int x,int l,int r,int y,int c)
{
	if(l==r){
		tag[x]=c;
		return;
	}
	int mid=(l+r)/2;
	pushdo(x);
	if(y<=mid)update(x+x,l,mid,y,c);else update(x+x+1,mid+1,r,y,c);
} 
void query(int x,int l,int r)
{
	if(l==r){
		printf("%d ",tag[x]);
		return;
	}
	pushdo(x);
	int mid=(l+r)/2;
	query(x+x,l,mid);
	query(x+x+1,mid+1,r);
}
int main()
{
	scanf("%d",&n);
	fz1(i,n){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	scanf("%d",&m);
	fz1(i,m){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			update(1,1,n,x,y);
		}
		else{
			scanf("%d",&x);
			upd(1,x);
		} 
	}
	query(1,1,n);
	return 0;
}