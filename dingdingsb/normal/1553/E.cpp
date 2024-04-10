// Problem: CF1553E Permutation Shift
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1553E
// Memory Limit: 250 MB
// Time Limit: 3000 ms
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
const int N=3e5+100;
int t,n,m;int cnt[N],p[N];
int g[N];bool vis[N];
void dfs(int u){
	vis[u]=1;
	if(!vis[g[u]])dfs(g[u]);
}
void solve(){
	read(n,m);
	for(int i=0;i<n;i++)cnt[i]=0;
	for(int i=1,x;i<=n;i++){
		read(x);
		p[x]=i;
		cnt[(i-x+n)%n]++;
	}
	vector<int>ans;
	for(int k=0;k<n;k++){
		if(cnt[k]<n-2*m)continue;
		for(int i=1;i<=n;i++)vis[i]=0;;
		for(int i=1;i<=n;i++){
			int pos=(i+k-1)%n+1;
			g[pos]=p[i];
		}
		int now=n;
		for(int i=1;i<=n;i++)
			if(!vis[i])dfs(i),now--;
		if(now<=m)ans.pb(k);
	}
	write(ans.size());putchar(' ');
	for(auto x:ans)write(x),putchar(' ');putchar('\n');
}
signed main(){
	read(t);while(t--)solve();
}