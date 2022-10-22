// Problem: CF1458C Latin Square
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1458C
// Memory Limit: 500 MB
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
const int N=1e3+100,M=1e5+100;
int t,n,a[N][N][3],b[N][N];
int m,id[3],tg[3],p[3];char c[M];
signed main(){
	read(t);while(t--){
		read(n,m);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				read(a[i][j][2]);a[i][j][2]--;
				a[i][j][0]=i;
				a[i][j][1]=j;
			}
		id[0]=0,id[1]=1,id[2]=2;
		tg[0]=tg[1]=tg[2]=0;
		scanf("%s",c+1);
		for(int i=1;i<=m;i++){
			if(c[i]=='R')tg[1]++;
			if(c[i]=='L')tg[1]--;
			if(c[i]=='D')tg[0]++;
			if(c[i]=='U')tg[0]--;
			if(c[i]=='I')swap(tg[1],tg[2]),swap(id[1],id[2]);
			if(c[i]=='C')swap(tg[0],tg[2]),swap(id[0],id[2]);
		}
		for(int i=0;i<3;i++)tg[i]%=n,tg[i]+=n,tg[i]%=n;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){
			for(int k=0;k<3;k++)p[k]=(a[i][j][id[k]]+tg[k])%n;
			b[p[0]][p[1]]=p[2];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				write(b[i][j]+1),pc(' ');
			pc('\n');
		}
		pc('\n');
	}
}