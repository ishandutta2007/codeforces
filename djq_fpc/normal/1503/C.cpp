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
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j;
struct ii
{
	int a,c,id;
}a[100005];
long long dp[100005],suf[100005],ans;
int qx[100005],ql,qr;
bool cmp(ii x,ii y)
{
	return x.a<y.a;
}
int main()
{
	read(n);
	fz1(i,n){
		read(a[i].a);
		read(a[i].c);
		ans+=a[i].c;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	suf[n+1]=0x3f3f3f3f3f3f3f3fll;
	ql=1;
	fd1(i,n){
		if(i!=n){
			dp[i]=0x3f3f3f3f3f3f3f3fll;
			int l=i+1,r=n+1,mid,s=i;
			while(l<r){
				mid=(l+r)/2;
				if(a[i].a+a[i].c>=a[mid].a){
					s=mid;l=mid+1;
				}
				else r=mid;
			}
			dp[i]=min(dp[i],suf[s+1]-a[i].a-a[i].c);
			l=ql-1;r=qr;s=qr+1;
			while(l<r){
				mid=(l+r+1)/2;
				if(a[qx[mid]].a<=a[i].a+a[i].c){
					s=mid;r=mid-1;
				}
				else l=mid;
			}
			if(s<=qr) dp[i]=min(dp[i],dp[qx[s]]);
		}
		suf[i]=min(suf[i+1],dp[i]+a[i].a);
		while(ql<=qr&&dp[qx[qr]]>=dp[i]){
			qr--;
		}
		qx[++qr]=i;
	}
	cout<<ans+dp[1]<<endl;
	return 0;
}