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
const int N=2e3+10;
int t,n,k;bool vis[N];
vector<pair<int,int>>ans;
bool chk(int a,int b,int c,int d){
	return (a<c&&c<b&&b<d)||(c<a&&a<d&&d<b);
}
signed main(){
	read(t);while(t--){
		read(n,k);ans.clear();
		for(int i=1;i<=2*n;i++)vis[i]=0;
		for(int i=1,x,y;i<=k;i++)
			read(x,y),ans.pb(mp(min(x,y),max(x,y))),vis[x]=vis[y]=1;
		vector<int>num;
		for(int i=1;i<=2*n;i++)if(!vis[i])num.pb(i);
		for(int i=0;i<n-k;i++)
			ans.pb(mp(num[i],num[i+n-k]));
		int res=0;
		//printf("%d\n",ans.size());
		//for(int i=0;i<ans.size();i++)
		//	printf(" %d %d\n",ans[i].fi,ans[i].se);
		for(int i=0;i<ans.size();i++)
			for(int j=i+1;j<ans.size();j++)
				res+=chk(ans[i].fi,ans[i].se,ans[j].fi,ans[j].se);
		write(res);putchar('\n');
	}
}