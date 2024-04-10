// Problem: B. Omkar and Heavenly Tree
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/B
// Memory Limit: 256 MB
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
const int N=1e5+100;
int t,n,m,a[N],b[N],c[N];bool vis[N];
signed main(){
	read(t);
	while(t--){
		read(n,m);
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=m;i++)read(a[i],b[i],c[i]),vis[b[i]]=1;
		int x=0;for(int i=1;i<=n;i++)if(!vis[i])x=i;
		for(int i=1;i<=n;i++)if(i!=x)printf("%d %d\n",x,i);
	}
}