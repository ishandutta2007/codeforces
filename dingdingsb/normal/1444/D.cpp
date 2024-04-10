// Problem: CF1444D Rectangular Polyline
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1444D
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
const int N=1e3+100;
int t,n,m;
int suma,sumb;
int a[N],b[N];
bitset<N*N>dp[N];
vector<int>x[2],y[2];
bool chk(){
	if(n!=m||(suma&1)||(sumb&1))return false;
	
	for(int i=1;i<=n;i++)dp[i]=dp[i-1]|(dp[i-1]<<a[i]);
	if(!dp[n][suma/2])return false;
	x[0].clear();x[1].clear();
	int needa=suma/2;
	for(int i=n;i;i--){
		if(needa>=a[i]&&dp[i-1][needa-a[i]])needa-=a[i],x[0].pb(a[i]);
		else x[1].pb(a[i]);
	}
	
	for(int i=1;i<=n;i++)dp[i]=dp[i-1]|(dp[i-1]<<b[i]);
	if(!dp[n][sumb/2])return false;
	y[0].clear();y[1].clear();
	int needb=sumb/2;
	for(int i=n;i;i--){
		if(needb>=b[i]&&dp[i-1][needb-b[i]])needb-=b[i],y[0].pb(b[i]);
		else y[1].pb(b[i]);
	}
	
	return true;
}
signed main(){
	dp[0][0]=1;
	read(t);
	while(t--){
		read(n);suma=0;for(int i=1;i<=n;i++)read(a[i]),suma+=a[i];
		read(m);sumb=0;for(int i=1;i<=m;i++)read(b[i]),sumb+=b[i];
		if(chk()){
			puts("Yes");
			if(x[0].size()>x[1].size())swap(x[0],x[1]);
			if(y[0].size()<y[1].size())swap(y[0],y[1]);
			sort(x[0].begin(),x[0].end());reverse(x[0].begin(),x[0].end());
			sort(x[1].begin(),x[1].end());reverse(x[1].begin(),x[1].end());
			sort(y[0].begin(),y[0].end());
			sort(y[1].begin(),y[1].end());
	
			//for(auto kk:x[0])printf("%d ",kk);puts("");
			//for(auto kk:x[1])printf("%d ",kk);puts("");
			//for(auto kk:y[0])printf("%d ",kk);puts("");
			//for(auto kk:y[1])printf("%d ",kk);puts("");
			int nowx=0,nowy=0;
			for(int i=0;i<x[0].size();i++){
				nowx+=x[0][i];
				write(nowx),pc(' '),write(nowy),pc('\n');
				nowy+=y[0][i];
				write(nowx),pc(' '),write(nowy),pc('\n');
			}
			for(int i=x[0].size();i<y[0].size();i++){
				nowx-=x[1][i-x[0].size()];
				write(nowx),pc(' '),write(nowy),pc('\n');
				nowy+=y[0][i];
				write(nowx),pc(' '),write(nowy),pc('\n');
			}
			for(int i=y[0].size()-x[0].size();i<x[1].size();i++){
				nowx-=x[1][i];
				write(nowx),pc(' '),write(nowy),pc('\n');
				nowy-=y[1][i-(y[0].size()-x[0].size())];
				write(nowx),pc(' '),write(nowy),pc('\n');
			}
		}else puts("No");
	}
}