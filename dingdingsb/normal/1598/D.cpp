// Problem: D. Training Session
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1598/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=2e5+100;
int t,n,x[N],y[N];vector<int>b[N],a[N];
int C2(int n){
	return n*(n-1)/2;
}
int C3(int n){
	return n*(n-1)*(n-2)/6;
}
signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)b[i].clear(),a[i].clear();
		for(int i=1;i<=n;i++)
			read(x[i],y[i]),b[x[i]].pb(y[i]),a[y[i]].pb(x[i]);
		int ans=C3(n);
		for(int i=1;i<=n;i++)ans-=C3(b[i].size());
		for(int i=1;i<=n;i++)ans-=C2(b[i].size())*(n-b[i].size());
		for(int i=1;i<=n;i++)ans-=C3(a[i].size());
		for(int i=1;i<=n;i++)ans-=C2(a[i].size())*(n-a[i].size());
		for(int i=1;i<=n;i++)
			if(b[x[i]].size()>1&&a[y[i]].size()>1)
				ans+=1ll*(b[x[i]].size()-1)*(a[y[i]].size()-1);
		ans=-ans;
		int f[2]={0,0};
		for(int i=1;i<=n;i++)
			ans+=f[1]*a[i].size(),
			f[1]+=f[0]*a[i].size(),
			f[0]+=a[i].size();
		f[0]=0;f[1]=0;
		for(int i=1;i<=n;i++)
			ans+=f[1]*b[i].size(),
			f[1]+=f[0]*b[i].size(),
			f[0]+=b[i].size();
		
		write(ans);putchar('\n');
	}
}