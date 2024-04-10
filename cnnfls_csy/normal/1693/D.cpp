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
/*#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif*/
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
inline void read(long long &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int t,n,m,i,j,a[200005];
long long ans;
int f[200005],g[200005],res[200005];
void solve(int l,int r)
{
	if(l==r){ans++;return;}int mid=(l+r)/2,i,c,j,ti,td,tm,vai,rev;

	fz(i,l,r) f[i]=0x3f3f3f3f,g[i]=-0x3f3f3f3f;

	i=mid+1;vai=1;rev=0;
	while(i<=r&&(i==mid+1||a[i]>a[i-1])) f[i]=-1,i++;
	c=a[i];j=i;ti=a[i-1];td=a[i];
	while(i<=r&&(a[i]<=td||a[i]>=ti)){
		f[i]=min(f[i],c);
		if(a[i]<=td) td=a[i]; else ti=a[i];
		i++;
	}
	if(j-1==mid+1){
		rev=1;
		c=(rev?a[j]:a[j-1]);ti=a[j];td=a[j-1];tm=a[j];j=j+1;
	}
	else{
		c=a[j-1];ti=a[j-2];td=a[j-1];tm=a[j-1];
	}
	if(tm>td) ti=tm;if(tm<ti) td=tm;
	while(j<=r){
		if(vai){
			if(ti>td){
				if(a[j]>=ti) ti=a[j]; else if(a[j]<=td) td=a[j]; else vai=0;
			}
			else{
				if(a[j]>td) ti=a[j]; else if(a[j]<ti) td=a[j]; else if(a[j]<tm) td=tm,tm=a[j]; else if(a[j]>tm) ti=tm,tm=a[j];
			}
		}
		if(vai){
			if(rev) g[j]=max(g[j],c);
			else f[j]=min(f[j],c);
		}
		j++;
	}

	i=mid+1;vai=1;rev=0;
	while(i<=r&&(i==mid+1||a[i]<a[i-1])) g[i]=n+1,i++;
	c=a[i];j=i;td=a[i-1];ti=a[i];
	while(i<=r&&(a[i]<=td||a[i]>=ti)){
		g[i]=max(g[i],c);
		if(a[i]<=td) td=a[i]; else ti=a[i];
		i++;
	}
	if(j-1==mid+1){
		rev=1;
		c=(rev?a[j]:a[j-1]);td=a[j];ti=a[j-1];tm=a[j];j=j+1;
	}
	else{
		c=a[j-1];td=a[j-2];ti=a[j-1];tm=a[j-1];
	}
	if(tm>td) ti=tm;if(tm<ti) td=tm;
	while(j<=r){
		if(vai){
			if(ti>td){
				if(a[j]>=ti) ti=a[j]; else if(a[j]<=td) td=a[j]; else vai=0;
			}
			else{
				if(a[j]>td) ti=a[j]; else if(a[j]<ti) td=a[j]; else if(a[j]<tm) td=tm,tm=a[j]; else if(a[j]>tm) ti=tm,tm=a[j];
			}
		}
		if(vai){
			if(!rev) g[j]=max(g[j],c);
			else f[j]=min(f[j],c);
		}
		j++;
	}

	i=mid;vai=1;rev=0;
	while(i>=l&&(i==mid||a[i]>a[i+1])) f[i]=-1,i--;
	c=a[i];j=i;ti=a[i+1];td=a[i];
	while(i>=l&&(a[i]<=td||a[i]>=ti)){
		f[i]=min(f[i],c);
		if(a[i]<=td) td=a[i]; else ti=a[i];
		i--;
	}
	if(j+1==mid){
		rev=1;
		c=(rev?a[j]:a[j+1]);ti=a[j];td=a[j+1];tm=a[j];j=j-1;
	}
	else{
		c=a[j+1];ti=a[j+2];td=a[j+1];tm=a[j+1];
	}
	if(tm>td) ti=tm;if(tm<ti) td=tm;
	while(j>=l){
		if(vai){
			if(ti>td){
				if(a[j]>=ti) ti=a[j]; else if(a[j]<=td) td=a[j]; else vai=0;
			}
			else{
				if(a[j]>td) ti=a[j]; else if(a[j]<ti) td=a[j]; else if(a[j]<tm) td=tm,tm=a[j]; else if(a[j]>tm) ti=tm,tm=a[j];
			}
		}
		if(vai){
			if(rev) g[j]=max(g[j],c);
			else f[j]=min(f[j],c);
		}
		j--;
	}

	i=mid;vai=1;rev=0;
	while(i>=l&&(i==mid||a[i]<a[i+1])) g[i]=n+1,i--;
	c=a[i];j=i;td=a[i+1];ti=a[i];
	while(i>=l&&(a[i]<=td||a[i]>=ti)){
		g[i]=max(g[i],c);
		if(a[i]<=td) td=a[i]; else ti=a[i];
		i--;
	}
	if(j+1==mid){
		rev=1;
		c=(rev?a[j]:a[j+1]);td=a[j];ti=a[j+1];tm=a[j];j=j-1;
	}
	else{
		c=a[j+1];td=a[j+2];ti=a[j+1];tm=a[j+1];
	}
	if(tm>td) ti=tm;if(tm<ti) td=tm;
	while(j>=l){
		if(vai){
			if(ti>td){
				if(a[j]>=ti) ti=a[j]; else if(a[j]<=td) td=a[j]; else vai=0;
			}
			else{
				if(a[j]>td) ti=a[j]; else if(a[j]<ti) td=a[j]; else if(a[j]<tm) td=tm,tm=a[j]; else if(a[j]>tm) ti=tm,tm=a[j];
			}
		}
		if(vai){
			if(!rev) g[j]=max(g[j],c);
			else f[j]=min(f[j],c);
		}
		j--;
	}

	j=l;
	fz(i,mid+1,r){
		while(j<=mid){
			bool flg=0;
			if(a[mid]<a[mid+1]&&g[j]>=f[i]) flg=1;
			if(a[mid]>a[mid+1]&&f[j]<=g[i]) flg=1;
			if(f[i]<=a[mid]&&f[j]<=a[mid+1]) flg=1;
			if(g[i]>=a[mid]&&g[j]>=a[mid+1]) flg=1;
			if(!flg) j++; else break;
		}
		if(j>mid) break;
		res[i]=min(res[i],j);
//		cerr<<j<<' '<<i<<endl;
		ans+=(mid-j+1);
	}

	solve(l,mid);solve(mid+1,r);
}
void solve()
{
	read(n);fz1(i,n)read(a[i]),res[i]=n+1;
	solve(1,n);printf("%lld\n",ans);
//	fz1(i,n) cerr<<res[i]<<' '<<i<<endl;
}
int main()
{
	t=1;//read(t);
	while(t--){
		solve();
	}
	return 0;
}