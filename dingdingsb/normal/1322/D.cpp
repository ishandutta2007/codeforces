// Problem: CF1322D Reality Show
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1322D
// Memory Limit: 500 MB
// Time Limit: 2000 ms
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
const int N=4010;
int n,m;
int l[N],s[N],c[N];
int f[N][N];
signed main(){
	read(n,m);
	m+=n;
	for(int i=1;i<=n;i++)read(l[n-i+1]);
	for(int i=1;i<=n;i++)read(s[n-i+1]);
	for(int i=1;i<=m;i++)read(c[i]);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			f[i][j]=-0x3f3f3f3f;
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j;j--)
			chkmx(f[l[i]][j],f[l[i]][j-1]+c[l[i]]-s[i]);
		for(int j=l[i];j<=m;j++)
			for(int k=0;k<=n>>j-l[i];k++)
				chkmx(f[j+1][k/2],f[j][k]+k/2*c[j+1]);
	}
	write(f[m][0]);
}