#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define vit vector<int>::iterator
#define sit set<pr>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int V=1<<21,N=30;
int cnt[V],G[N],st[N],dp[V],fa[N];
int getfa(int u){ return fa[u]==u?u:fa[u]=getfa(fa[u]); }
int main(){
	int T; scanf("%d",&T);
	rep(s,1,(1<<20)-1) cnt[s]=cnt[s&(s-1)]+1;
	while (T--){
		int n; static char a[1000000],b[1000000];
		scanf("%d%s%s",&n,a,b);
		rep(i,1,20) G[i]=st[i]=0,fa[i]=i;
		rep(s,1,(1<<20)-1) dp[s]=false;
		rep0(i,n){
			int u=a[i]-'a'+1,v=b[i]-'a'+1;
			G[u]|=1<<v-1,fa[getfa(u)]=getfa(v);
		}
		rep(i,1,20) st[getfa(i)]|=1<<i-1;
		rep(i,1,20) dp[1<<i-1]=1;
		rep(s,1,(1<<20)-1){
			if (!dp[s]) continue;
			rep(i,1,20)
				if (!(s>>i-1&1)&&(G[i]&s)==0)
					dp[s|(1<<i-1)]=true;
		}
		int ans=0;
		rep(i,1,20)
			if (fa[i]==i){
				int mx=0;
				for (int s=st[i];s;s=(s-1)&st[i])
					if (dp[s]) mx=max(mx,cnt[s]);
				ans+=2*cnt[st[i]]-1-mx;
			}
		printf("%d\n",ans);
	}
	return 0;
}