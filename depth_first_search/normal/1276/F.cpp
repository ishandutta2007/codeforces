#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 100000
#define LN 18
#define LL long long
using namespace std;
int n;char s[N+5];LL t,h[N+5];vector<int> w[N+5];set<int> S,g[N+5];
struct SuffixArray
{
	int SA[N+5],H[N+5],rk[N+5],p[N+5],tt[N+5],Lg[N+5],Mn[N+5][LN+1];
	void Sort(int S)
	{
		int i;for(i=1;i<=S;++i) tt[i]=0;for(i=1;i<=n;++i) ++tt[rk[i]];
		for(i=1;i<=S;++i) tt[i]+=tt[i-1];for(i=n;i;--i) SA[tt[rk[p[i]]]--]=p[i];
	}
	void Get()
	{
		int i,S='z';for(i=1;i<=n;++i) rk[p[i]=i]=s[i];Sort(S);
		int c=0;for(int k=1;c^n;k<<=1,S=c)
		{
			for(c=0,i=1;i<=k;++i) p[++c]=n-k+i;for(i=1;i<=n;++i) SA[i]>k&&(p[++c]=SA[i]-k);
			for(Sort(S),i=1;i<=n;++i) p[i]=rk[i];for(rk[SA[1]]=c=1,i=2;i<=n;++i) (p[SA[i-1]]^p[SA[i]]||p[SA[i-1]+k]^p[SA[i]+k])&&++c,rk[SA[i]]=c;
		}
		int j,k=0;for(i=1;i<=n;++i) rk[SA[i]]=i;for(i=1;i<=n;++i) if(k&&--k,rk[i]>1) {j=SA[rk[i]-1];while(s[i+k]==s[j+k]) ++k;H[rk[i]]=k;}
		for(Lg[0]=-1,i=1;i<=n;++i) Lg[i]=Lg[i>>1]+1,Mn[i][0]=H[i];
		for(j=1;(1<<j)<=n;++j) for(i=1;i+(1<<j)-1<=n;++i) Mn[i][j]=min(Mn[i][j-1],Mn[i+(1<<j-1)][j-1]);
	}
	int operator () (int l,int r) {int k=Lg[r-l+1];return min(Mn[l][k],Mn[r-(1<<k)+1][k]);}
}SA,PA;
int f[N+5];int fa(int x) {return f[x]?f[x]=fa(f[x]):x;}
void Mg(int x,int y)
{
	if(g[x].size()<g[y].size()) swap(g[x],g[y]),swap(h[x],h[y]);
	t-=h[x]+h[y];int p,q;set<int>::iterator it;for(auto k:g[y])
	{
		q=(it=g[x].upper_bound(k))!=g[x].end()?*it:-1,p=(it=g[x].lower_bound(k))!=g[x].begin()?*--it:-1;
		h[x]+=n-SA.SA[k]+1,~p&&~q&&(h[x]+=SA(p+1,q)),~p&&(h[x]-=SA(p+1,k)),~q&&(h[x]-=SA(k+1,q)),g[x].insert(k);
	}
	t+=h[x],f[y]=x,g[y].clear(),S.erase(y);
}
void Add(int x)
{
	int k=PA.rk[n-x+1];if(x+2<=n) g[k].insert(SA.rk[x+2]),t+=(h[k]=n-(x+2)+1);
	set<int>::iterator it;S.insert(k);
	if((it=S.upper_bound(k))!=S.end()) {int o=PA(k+1,*it);if(o>=x) Mg(k,*it);else w[o].push_back(*it);}
	if((it=S.lower_bound(k))!=S.begin()) {--it;int o=PA(*it+1,k);if(o>=x) Mg(*it,k);else w[o].push_back(k);}
}
int main()
{
	scanf("%s",s+1),n=strlen(s+1),SA.Get(),reverse(s+1,s+n+1),PA.Get();
	int i;LL ans=1LL*n*(n+1)/2+1;for(i=1;i<=n;++i) ans-=SA.H[i];
	ans+=1LL*n*(n-1)/2+1;for(i=1;i<=n;++i) SA.SA[i]^1&&(ans-=SA.SA[i-1]^1?SA.H[i]:min(SA.H[i],SA.H[i-1]));
	for(i=n-1;i;--i) {for(auto x:w[i]) !f[x]&&(Mg(*--S.lower_bound(x),x),0);Add(i),ans+=t+S.size();}return printf("%lld\n",ans),0;
}