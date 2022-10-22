// Problem: A. Windblume Ode
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e2+100,M=100*200+100;
int t,n,a[N];
bool isp(int i){
	for(int j=2;j*j<=i;j++)if(i%j==0)return false;
	return true;
}
signed main(){
	read(t);
	while(t--){
		read(n);int sum=0;
		for(int i=1;i<=n;i++)read(a[i]),sum+=a[i];
		if(!isp(sum)){
			write(n);pc('\n');
			for(int i=1;i<=n;i++)write(i),pc(' ');
			pc('\n');
		}else{
			write(n-1);pc('\n');
			//
			int x=0;
			for(int i=1;i<=n;i++)if(a[i]%2)x=i;
			for(int i=1;i<=n;i++)if(i!=x)write(i),pc(' ');
			pc('\n');
		}
	}
}