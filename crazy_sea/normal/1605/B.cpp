#include<cstdio>
#include<vector>
#include<algorithm>
#define N 1010
using namespace std;
int p[N],q[N],l1,l2,n,w,tot,T;
char s[N];
vector<int>ans[N];
bool work()
{
	w=l1=l2=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='1') p[++l1]=i;
	for(int i=n;i;i--)
		if(s[i]=='0') q[++l2]=i;
	while(w<l1&&w<l2&&p[w+1]<q[w+1]) w++;
	if(w==0) return 0;
	tot++;
	for(int i=1;i<=w;i++) ans[tot].push_back(p[i]);
	for(int i=w;i;i--) ans[tot].push_back(q[i]);
	for(int i=1;i<=w;i++) swap(s[p[i]],s[q[i]]);
	return 1;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		tot=0;
		scanf("%d%s",&n,s+1);
		while(work());
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++)
		{
			printf("%d ",ans[i].size());
			for(int j:ans[i]) printf("%d ",j);
			printf("\n");
			ans[i].clear();
		}
	}
}