// Problem: Cherry
// Contest: Codeforces
// URL: https://m1.codeforces.ml/contest/1554/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
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
const int N=3e5+100;
int t,n;int a[N];
signed main(){
	read(t);
	while(t--){
		read(n);for(int i=1;i<=n;i++)read(a[i]);
		int ans=0;for(int i=1;i<n;i++)ans=max(ans,1ll*a[i]*a[i+1]);
		write(ans);putchar('\n');
	}//ccfn***
}