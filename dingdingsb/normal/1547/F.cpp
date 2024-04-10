// Problem: CF1547F Array Stabilization (GCD version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1547F
// Memory Limit: 500 MB
// Time Limit: 4000 ms
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
enum{N=800000+100,M=20};
int t,n,a[N],b[N],f[N][M];
signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)
			read(a[i]),f[i][0]=f[i+n][0]=a[i],b[i]=0;
		bool flag=true;
		for(int i=1;i<n;i++)
			if(a[i]!=a[i+1])
				flag=false;
		if(flag)puts("0");else{
			for(int j=1;j<M;j++)
				for(int i=1;i<=2*n;i++)
					f[i][j]=__gcd(f[i][j-1],i+(1<<j-1)<=2*n?f[i+(1<<j-1)][j-1]:0);
			int now=0;
			for(int j=M-1;~j;j--){
				for(int i=1;i<=n;i++)
					a[i]=__gcd(b[i],f[i+now][j]);
				for(int i=1;i<n;i++)if(a[i]!=a[i+1]){
					now+=(1<<j);
					for(int k=1;k<=n;k++)
						b[k]=a[k];
					break;
				}
			}
			write(now);putchar('\n');
		}
	}
}