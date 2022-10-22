#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 200010
using namespace std;
int w,x,len[N],T,n,m,a[N],b[N];
vector<int>v[N];
int query()
{
	w=0,x=0;
	while(len[w]) x=max(x,v[w][len[w]-1]),w++;
	return w;
}
bool check(){return len[0];}
void work()
{
	for(int i=0;i<w;i++)
		while(len[i]&&v[i][len[i]-1]<=x) len[i]--;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		m=x=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=n;i;i--) v[a[i]].push_back(i);
		for(int i=0;i<=n;i++) len[i]=v[i].size();
		while(check()) b[++m]=query(),work();
		for(int i=1;i<=n;i++)
			while(len[i])
			{
				len[i]--;
				if(v[i][len[i]]>x) b[++m]=0;
			}
		printf("%d\n",m);
		for(int i=1;i<=m;i++) printf("%d ",b[i]);
		printf("\n");
		for(int i=0;i<=n;i++) v[i].clear(),len[i]=0;
	}
}