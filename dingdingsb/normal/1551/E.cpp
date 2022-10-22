#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=2100;
int t,n,k,a[N],dp[N];
signed main(){
	read(t);
	while(t--){
		read(n,k);
		for(int i=1;i<=n;i++)read(a[i]);
		memset(dp,-0x3f,sizeof dp);
		dp[0]=0;
		for(int i=1;i<=n;i++)
			for(int j=n;j;j--)
				chkmx(dp[j],dp[j-1]+(a[i]==j));
		for(int i=n;i>=1;i--)if(dp[i]>=k){
			write(n-i);putchar('\n');
			goto loop;
		}
		puts("-1");loop:;
	}
}