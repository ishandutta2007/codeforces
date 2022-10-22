// Problem: D1. Divan and Kostomuksha (easy version)
// Contest: Codeforces - Codeforces Round #757 (Div. 2)
// URL: https://codeforces.com/contest/1614/problem/D1
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e5+100,M=5e6+10;
int n,dp[M];
int cnt[M];

signed main(){
	read(n);
	for(int i=1;i<=n;i++){
		int x;read(x);
		for(int i=1;i*i<=x;i++)if(x%i==0){
			cnt[i]++;
			if(i!=x/i)cnt[x/i]++;
		}
	}
	for(int i=M-5;i;i--){
		dp[i]=cnt[i]*i;
		for(int j=i*2;j<M-5;j+=i)
			chkmx(dp[i],dp[j]+(cnt[i]-cnt[j])*i);
	}
	
	int ans=0;
	for(int i=1;i<M;i++)if(cnt[i]==n)chkmx(ans,dp[i]);
	write(ans);
	return 0;
	cout<<"c*fnmsl";
}