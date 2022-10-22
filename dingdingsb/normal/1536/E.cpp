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
const int mod=1000000007;
int t,n,m;char s[N];
signed main(){
	ios::sync_with_stdio(false);
	cin>>t;while(t--){
		cin>>n>>m;
		int cnt=0,ans=1;
		for(int i=1;i<=n;i++){
			cin>>s+1;
			for(int j=1;j<=m;j++)
				if(s[j]=='#')
					ans=ans*2%mod,cnt++;
		}
		ans=(ans-(cnt==n*m)+mod)%mod;
		write(ans);putchar('\n');
	}
}