#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int a[1000005],sa[1000005],b[1000005],sb[1000005],n,m,i,j,l,r,mid,ans;
inline int id(int x,int y)
{
	return (x-1)*m+y;
}
inline int querya(int lx,int ly,int rx,int ry)
{
	int ans=sa[id(rx,ry)];
	if(lx>1) ans-=sa[id(lx-1,ry)];
	if(ly>1) ans-=sa[id(rx,ly-1)];
	if(lx>1&&ly>1) ans+=sa[id(lx-1,ly-1)];
	return ans;
}
inline int queryb(int lx,int ly,int rx,int ry)
{
	int ans=sb[id(rx,ry)];
	if(lx>1) ans-=sb[id(lx-1,ry)];
	if(ly>1) ans-=sb[id(rx,ly-1)];
	if(lx>1&&ly>1) ans+=sb[id(lx-1,ly-1)];
	return ans;
}
bool check(int x)
{
	int i,j;
	fz1(i,n)fz1(j,m){
		b[id(i,j)]=0;
		if(a[id(i,j)]){
			int lx=i-x,rx=i+x,ly=j-x,ry=j+x;
			if(lx<1||rx>n||ly<1||ry>m)continue;
			if(querya(lx,ly,rx,ry)==(x*2+1)*(x*2+1)){
				b[id(i,j)]=1;
			}
		}
	}
	fz1(i,n){
		fz1(j,m){
			sb[id(i,j)]=b[id(i,j)];
			if(i>1) sb[id(i,j)]+=sb[id(i-1,j)];
			if(j>1) sb[id(i,j)]+=sb[id(i,j-1)];
			if(i>1&&j>1) sb[id(i,j)]-=sb[id(i-1,j-1)];
		}
	}
	fz1(i,n)fz1(j,m){
		int lx=i-x,rx=i+x,ly=j-x,ry=j+x;
		lx=max(lx,1);rx=min(rx,n);
		ly=max(ly,1);ry=min(ry,m);
		int t=queryb(lx,ly,rx,ry); 
		if((t>0)!=(a[id(i,j)]==1)){
			return 0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,n){
		scanf(" ");
		fz1(j,m){
			char c;
			scanf("%c",&c);
			if(c=='X') a[id(i,j)]=1;
		}
	}
	fz1(i,n){
		fz1(j,m){
			sa[id(i,j)]=a[id(i,j)];
			if(i>1) sa[id(i,j)]+=sa[id(i-1,j)];
			if(j>1) sa[id(i,j)]+=sa[id(i,j-1)];
			if(i>1&&j>1) sa[id(i,j)]-=sa[id(i-1,j-1)];
		}
	}
	l=0;r=min(n,m)+1;ans=0;
	while(l<r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid;
	}
	cout<<ans<<endl;
	check(ans);
	fz1(i,n){
		fz1(j,m){
			putchar(b[id(i,j)]?'X':'.');
		}
		puts("");
	}
	return 0;
}