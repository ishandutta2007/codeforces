// Problem: B. Groups
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1598/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
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
const int N=1e3+100;
int t,n,fl[N][10];
signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=5;j++)
				read(fl[i][j]);
		for(int i=1;i<=5;i++)
			for(int j=i+1;j<=5;j++){
				int I=0,J=0;bool flag=true;
				for(int k=1;k<=n;k++){
					if(!fl[k][i]&&!fl[k][j]){
						flag=false;
					}
					else if(fl[k][i]&&fl[k][j]);
					else if(fl[k][i])I++;
					else J++;
				}
				if(flag&&I<=n/2&&J<=n/2){
					puts("YES");
					goto loop;
				}
			}
		puts("NO");
		loop:;
	}
}