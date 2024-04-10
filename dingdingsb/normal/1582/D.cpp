// Problem: D. Vupsen, Pupsen and 0
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/D
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
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e5+100;
int t,n,a[N];
int b[N];
signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)
			read(a[i]);
		if(n%2==0){
			for(int i=1;i<=n;i+=2)
				write(a[i+1]),pc(' '),write(-a[i]),pc(' ');
		}
		else{
			for(int i=1;i<=n;i+=2){
				if(i+2!=n){
					write(a[i+1]),pc(' '),write(-a[i]),pc(' ');
				}else{
					if(a[i]!=a[i+1]){
						write(-a[i+2]);pc(' ');
						write(a[i+2]);pc(' ');
						write(a[i]-a[i+1]);pc(' ');
					}else if(a[i]!=a[i+2]){
						write(-a[i+1]);pc(' ');
						write(a[i]-a[i+2]);pc(' ');
						write(a[i+1]);pc(' ');
					}else if(a[i+1]!=a[i+2]){
						write(a[i+1]-a[i+2]);pc(' ');
						write(-a[i]);pc(' ');
						write(a[i]);pc(' ');
					}else write(2),pc(' '),write(-1),pc(' '),write(-1);
					break;
				}
			}
		}
		pc('\n');
	}
}