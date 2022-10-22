#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int n,T,siz[N],p[N],a[N],b[N];
vector<int>v[N];
bool cmp(int x,int y){return siz[x]<siz[y];}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),v[a[i]].push_back(i);
		for(int i=1;i<=n;i++) siz[i]=v[i].size(),p[i]=i;
		sort(p+1,p+n+1,cmp);
		for(int k=1,j=1;k<=n;k++)
		{
			while(j<=n&&siz[p[j]]<k) j++;
			if(j>n) break;
			for(int i=j+1;i<=n;i++)
				b[v[p[i]].back()]=p[i-1];
			b[v[p[j]].back()]=p[n];
			for(int i=j;i<=n;i++) v[p[i]].pop_back();
		}
		for(int i=1;i<=n;i++) printf("%d ",b[i]);
		printf("\n");
		for(int i=1;i<=n;i++) v[i].clear();
	}
}