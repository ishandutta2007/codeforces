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
long long ans;
int n,m,i,j,k,c1,c2,cnt,rt,s[10005];
struct chui
{
	int x,h,op;
}a[10005];
struct shui
{
	int h,l,r;
}b[5005];
void add(int x,int y)
{
	x+=5001;int i;
	for(i=x;i<=10001;i+=(i&-i)){
		s[i]+=y;
	}
}
int qry(int x)
{
	x+=5001;
	int sum=0,i;
	for(i=x;i;i-=(i&-i)){
		sum+=s[i];
	}
	return sum;
}
bool cmp1(chui x,chui y)
{
	if(x.h==y.h)return x.op>y.op;
	return x.h<y.h;
}
bool cmp2(shui x,shui y)
{
	return x.h<y.h;
}
long long co2(int x)
{
	return 1ll*x*(x-1)/2;
}
void ins(int x)
{
	add(x,1);
}
void del(int x)
{
	int t=qry(x)-qry(x-1);
	if(t) add(x,-1);
}
int query(int l,int r)
{
	if(l>r)return 0;
	return qry(r)-qry(l-1);
}
int main()
{
	scanf("%d",&n);
	fz1(i,n){
		int x,y,xx,yy;
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		if(x>xx)swap(x,xx);
		if(y>yy)swap(y,yy);
		if(x==xx){
			a[++c1]=(chui){x,y,1};
			a[++c1]=(chui){x,yy,-1};
		}
		else{
			b[++c2]=(shui){y,x,xx};
		}
	}
	sort(a+1,a+c1+1,cmp1);
	sort(b+1,b+c2+1,cmp2);
	fz1(i,c2){
		memset(s,0,sizeof(s));
		j=k=1;
		while(j<=c1&&k<=c2){
			if(j<=c1&&(k>c2||a[j].h<b[k].h||(a[j].h==b[k].h&&a[j].op==1))){
				if(a[j].op==1){
					if(a[j].h<=b[i].h) ins(a[j].x);
				}
				else del(a[j].x);
				j++;
			}
			else{
				if(b[k].h>b[i].h){
					ans+=co2(query(max(b[i].l,b[k].l),min(b[i].r,b[k].r)));
				}
				k++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}