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
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,l[5005],r[5005],res[5005],f[5005],vis[5005],cnt[5005];
bool check(int x)
{
	int i,j;
	memset(vis,0,sizeof(vis));
	fz1(i,n) f[i]=n;
	fz1(i,n){
		memset(cnt,0,sizeof(cnt));
		fz1(j,n){
			if(!vis[j]){
				cnt[f[j]]++;
			}
		} 
		fz1(j,n){
			cnt[j]+=cnt[j-1]; 
			if(cnt[j]>max(0,j-i+1)) return 0;
		}
		fz(j,i,n) if(j-i+1==cnt[j]) break;
		int tv=j,tc=-1;
		fz1(j,n) if(!vis[j]&&f[j]<=tv&&(tc==-1||r[j]<r[tc])) tc=j;
		vis[res[i]=tc]=1;
		fz1(j,n) if(l[j]<=r[tc]&&l[tc]<=r[j]) f[j]=min(f[j],i+x);
	}
	return 1;
}
int main()
{
	read(n);
	fz1(i,n){
		read(l[i]);
		read(r[i]);
	}
	check(2);
	int l=0,r=n,mid,ans=n;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid;
		}
	}
	check(ans);
	fz1(i,n){
		printf("%d ",res[i]);
	}
	return 0;
}