#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
#define int long long
const int N=1e2+10;
int k,n;char s[N];
int len[N],dp[N];
signed main(){
	memset(len,0x3f,sizeof len);
	memset(dp,0x3f,sizeof dp);
	read(k);
	scanf("%s",s+1);n=strlen(s+1);
	len[n+1]=-1;
	for(int i=n;i;i--){
		if(s[i]=='0')len[i]=len[i+1]+1;
		else{
			for(int now=0,j=i;j<=n;j++){
				now=now*10+s[j]-'0';
				if(now>=k)break;
				chkmn(len[i],len[j+1]+1);
			}
		}
	}
	dp[n+1]=0;
	for(int i=n;i;i--){
		if(s[i]=='0')dp[i]=dp[i+1];
		else{
			for(int now=0,j=i;j<=n;j++){
				now=now*10+s[j]-'0';
				if(now>=k)break;
				if(len[i]==len[j+1]+1)if(log(now)+len[i]*log(k)<=18*log(10)+1)
					chkmn(dp[i],dp[j+1]+now*(int)(pow(k,len[i])+0.5));
			}
		}
	}
	write(dp[1]);
}