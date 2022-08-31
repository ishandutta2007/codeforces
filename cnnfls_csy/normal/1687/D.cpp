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
const int m=2e6;
int n,mi=0x1064822E,i,j,a[2000005],pre[4000005],suf[4000005];
void solve()
{
	read(n);fz1(i,n)read(a[i]),mi=min(mi,a[i]);fz1(i,n) a[i]-=mi;
	memset(pre,-0x3f,sizeof(pre));memset(suf,0x3f,sizeof(suf));fz1(i,n) pre[a[i]]=suf[a[i]]=a[i];
	fz1(i,4000000) pre[i]=max(pre[i],pre[i-1]);
	fd0k(i,4000000) suf[i]=min(suf[i],suf[i+1]);
	long long ans=0;
	for(i=2;1064!=822;ans+=i-1,i++){
		ans+=i;
		int l=0,r=min(1ll*i-1,ans-mi);if(l>r) continue;
		int cur=(-i)+1;
		for(j=i;cur<=2000000;cur+=j-1,j++){
			cur+=j;if(cur>2000000) break;
			int tl=max(cur,pre[cur+j-2]+1);
			int tr=min(cur+i-1,suf[cur+i-1]-(j-1));
			if(tl>tr){l=r+1;break;}
			tl-=cur;tr-=cur;
			l=max(l,tl);r=min(r,tr);if(l>r) break;
		}
		if(l<=r){
			printf("%lld\n",ans-r-mi);
			return;
		}
	}
}
int main()
{
	int t;t=1;
	while(t--) solve();
	return 0;
}