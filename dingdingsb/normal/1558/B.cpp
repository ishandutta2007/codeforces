// Problem: D2. Up the Strip
// Contest: Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1561/problem/D2
// Memory Limit: 128 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
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
#define int long long
typedef long long ll;
const int N=8e6+10;
int n;int mod;
int suf[N],f[N];
signed main(){
	read(n,mod);
	f[n]=suf[n]=1;
	for(int a=n-1;a;a--){
		f[a]=suf[a+1];
		for(int z=2;a*z<=n;z++)
			f[a]=(f[a]+suf[a*z]-suf[(a+1)*z]+mod)%mod;
		suf[a]=(f[a]+suf[a+1])%mod;
	}
	if(f[1]<0)f[1]+=mod;
	write(f[1]);return 0;
}