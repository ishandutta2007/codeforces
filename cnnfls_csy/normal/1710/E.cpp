// http://www.nfls.com.cn:20034/submission/178386
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
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,a[200005],b[200005],sx,sy,l,r,mid,ans;
int row[200005],col[200005];
bool check(int lim)
{
	if(a[sx]+b[sy]<=lim) return 1;int i;
	row[n+1]=0;fd1(i,n){row[i]=row[i+1];while(row[i]<m&&a[i]+b[row[i]+1]<=lim) row[i]++;}
	col[m+1]=0;fd1(i,m){col[i]=col[i+1];while(col[i]<n&&a[col[i]+1]+b[i]<=lim) col[i]++;}
	int rx=0,ry=0,cx,cy=0;
	long long ans=0,cur=0;
	fz1(cx,n){
		cur+=min(row[cx],cy);
		cur-=(m-max(row[cx],cy));
		while(cy<m&&min(col[cy+1],cx)-(n-max(col[cy+1],cx))>=0){
			cur+=min(col[cy+1],cx);
			cur-=(n-max(col[cy+1],cx));
			cy++;
		}
		if(cur>=ans){
			ans=cur;
			rx=cx;ry=cy;
		}
	}
	return !(sx>rx&&sy>ry);
}
int main()
{
	read(n);read(m);fz1(i,n)read(a[i]);fz1(i,m)read(b[i]);
	fz(i,2,n)sx+=(a[i]<a[1]);fz(i,2,m)sy+=(b[i]<b[1]);sx++;sy++;
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	l=a[1]+b[1]-1;r=a[sx]+b[sy]-1;ans=a[sx]+b[sy];
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid;
	}
	printf("%d\n",ans);
	return 0;
}