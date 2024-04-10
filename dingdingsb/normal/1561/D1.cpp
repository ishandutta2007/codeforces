// Problem: D1. Up the Strip (simplified version)
// Contest: Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1561/problem/D1
// Memory Limit: 128 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int N=3e5+100;
int n;int mod;
int f[N],sum[N];
signed main(){
	read(n,mod);
	f[1]=sum[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=sum[i-1];
		for(int l=2,r;l<=i;l=r+1){
			r=i/(i/l);
			f[i]=(f[i]+1ll*(r-l+1)*f[i/l]%mod)%mod;
		}
		sum[i]=(sum[i-1]+f[i])%mod;
	}
	write(f[n]);
	return 0;
}