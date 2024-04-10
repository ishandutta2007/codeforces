// Problem: CF1592F1 Alice and Recoloring 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1592F1
// Memory Limit: 250 MB
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
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=500+10;
int n,m;
char s[N][N];
int a[N][N],b[N][N];
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='B')
				a[i][j]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			b[i][j]=a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1];
	int cnt=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		if(b[i][j])cnt++;
	for(int i=1;i<n;i++)for(int j=1;j<m;j++)
		if(b[i][j]&&b[i][m]&&b[n][j]&&b[n][m])
			return write(cnt-1),0;
	write(cnt);
}