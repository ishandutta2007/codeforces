// Problem: CF1547E Air Conditioners
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1547E
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
#define int long long
typedef long long ll;
const int N=3e5+100;
const int inf=0x3f3f3f3f3f3f3f3fll;
int T,n,m,f[N],a[N],t[N];
int pre[N],suf[N];
int ans[N];
signed main(){
	read(T);
	while(T--){
		read(n,m);
		for(int i=0;i<=n+1;i++)
			f[i]=pre[i]=suf[i]=ans[i]=inf;
		for(int i=1;i<=m;i++)read(a[i]);
		for(int i=1;i<=m;i++)read(t[i]);
		while(m){
			chkmn(f[a[m]],t[m]);
			m--;
		}
		for(int i=1;i<=n;i++)
			pre[i]=min(pre[i-1],f[i]-i),chkmn(ans[i],pre[i]+i);
		for(int i=n;i;i--)
			suf[i]=min(suf[i+1],f[i]+i),chkmn(ans[i],suf[i]-i);
		for(int i=1;i<=n;i++)
			write(ans[i]),putchar(' ');
		putchar('\n');
	}
}