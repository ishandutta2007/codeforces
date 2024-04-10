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
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
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
int n,m,i,j,t,pre[500005],cnt[1000005],cnt2[1000005];
string st;
int main()
{
	scanf("%d",&t);
	while(t--){
		rdst(st,500005)
		n=st.size();
		st=" "+st;
		fz1(i,n)pre[i]=0;
		fz0g(i,n+n) cnt[i]=cnt2[i]=0;
		pre[0]=n;
		int rem1=0,mx=n;
		fz1(i,n){
			pre[i]=pre[i-1]+(st[i]=='1'?1:-1);
			if(st[i]=='0')cnt[pre[i-1]]++;else cnt2[pre[i-1]]++;
			rem1+=(st[i]=='1');
			mx=max(mx,pre[i]);
		}
		int t=n;
		fz1(i,n){
			while(mx>=0&&!cnt[mx])mx--;
			if((t>=mx||cnt2[t-1])&&cnt[t]){
				cnt[t]--;
				t--;putchar('0');
			}
			else{
				cnt2[t]--;
				t++;putchar('1');
			}
		}
		puts("");
	}
	return 0;
}