#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 4005
int a[N],n,m;
int val[N],f[N][N],vis[N];
signed main()
{
	cin>>n>>m; for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		f[i][i]=a[i];
		for(int j=i+1;j<=n;j++) f[i][j]=min(f[i][j-1],a[j]);
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int maxn=-INF,maxid=0;
		for(int j=1;j<=n;j++) if(!vis[j])
		{
			int w=val[j]*2+(m-1)*a[j];
			if(w>maxn) maxn=w,maxid=j;
		}
		vis[maxid]=1; ans+=maxn;
		for(int i=1;i<maxid;i++) val[i]-=f[i][maxid];
		for(int i=maxid+1;i<=n;i++) val[i]-=f[maxid][i];
	}
	cout<<ans<<endl;
	return 0;
}