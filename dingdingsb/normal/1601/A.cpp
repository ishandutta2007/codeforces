// Problem: A. Array Elimination
// Contest: Codeforces - Codeforces Round #751 (Div. 1)
// URL: https://codeforces.com/contest/1601/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
const int N=2e5+100,B=31;
int t,n,a[N];
int cnt[B];
signed main(){
	read(t);
	while(t--){
		read(n);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			read(a[i]);
			for(int j=0;j<B;j++)
				if(a[i]>>j&1)
					cnt[j]++;
		}
		for(int k=1;k<=n;k++){
			for(int j=0;j<B;j++)
				if(cnt[j]%k)goto loop;
			write(k);pc(' ');
			loop:;
		}
		pc('\n');
	}
}