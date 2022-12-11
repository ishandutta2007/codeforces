#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<iostream>
#define pb push_back
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;
const ll INF=1e18;

int n,k,s[3010];
vector<ll> c[3010];
ll ans;
ll f[15][3010]/*,g[15][3010]*/;
void solve(int l,int r,int d){
	ll *F=f[d],*G=f[d+1];
	if (l==r){
		for (int i=0;i<=k;i++)
			if (F[i]!=-INF&&k-i<=s[l]){
				ll H=i==k?0:c[l][k-i-1];
				ans=max(ans,F[i]+H);
			}
		return;
	}
	int mid=l+r>>1;
	for (int i=0;i<=k;i++) G[i]=F[i];
	for (int i=mid+1;i<=r;i++){
		ll V=s[i],W=c[i][s[i]-1];
		for (int j=k;j>=V;j--)
			if (G[j-V]!=-INF)
				G[j]=max(G[j],G[j-V]+W);
	}
	solve(l,mid,d+1);
	for (int i=0;i<=k;i++) G[i]=F[i];
	for (int i=l;i<=mid;i++){
		ll V=s[i],W=c[i][s[i]-1];
		for (int j=k;j>=V;j--)
			if (G[j-V]!=-INF)
				G[j]=max(G[j],G[j-V]+W);
	}
	solve(mid+1,r,d+1);
}
int main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++){
		c[i].resize(s[i]=read());
		for (int j=0;j<s[i];j++) c[i][j]=read();
		for (int j=1;j<s[i];j++) c[i][j]+=c[i][j-1];
	}
	f[0][0]=0; for (int i=1;i<=k;i++) f[0][i]=-INF;
	solve(1,n,0);
	cout<<ans<<endl;
	return 0;
}