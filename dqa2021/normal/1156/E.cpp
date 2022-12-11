#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll ans;

int n,w[200010],pos[200010];
int bin[200010];
struct Edge{  //init
	int to,nxt;
}edge[200010];
int cnt,last[200010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int tot[200010];
#define mid (l+r>>1)
void solve(int l,int r)
{
	if (l==r) return;
	solve(l,mid); solve(mid+1,r);
	int rpos=mid,lmax=-0x7fffffff;
	for (int i=mid;i>=l;i--)
	{
		lmax=max(lmax,w[i]);
		while (rpos<r&&w[rpos+1]<=lmax) rpos++;
		if (lmax-w[i]>0&&pos[lmax-w[i]]>mid&&pos[lmax-w[i]]<=rpos) ans++;
		if (rpos<r) addedge(rpos+1,i);
	}
	int rmax=-0x7fffffff;
	for (int i=mid+1;i<=r;i++)
	{
		rmax=max(rmax,w[i]);
		bin[i]=rmax-w[i];
	}
	for (int i=r;i>mid;i--)
	{
		if (bin[i]>0) tot[bin[i]]++;
		for (int j=last[i];j;j=edge[j].nxt)
			ans+=tot[w[edge[j].to]];
	}
	cnt=0;
	for (int i=r;i>mid;i--)
	{
		if (bin[i]>0) tot[bin[i]]--;
		last[i]=0;
	}
}
#undef mid
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",w+i),pos[w[i]]=i;
	solve(1,n);
	printf("%I64d\n",ans);
	return 0;
}