#include<cstdio>
#include<vector>
using namespace std;
const int N=2e5+10;
bool p;
int n,a[N],s[N],b[N],T;
vector<int>v[N];
bool okok(int x,int y)
{
	return s[y]&&a[y]==x;
}
void work(int x)
{
	int k=s[x];
	v[a[x]].pop_back();
	if(v[a[x]].size()) s[v[a[x]].back()]+=k;
	else if(k) p=1;
}
bool chk()
{
	p=0;
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=n;i;i--) v[a[i]].push_back(i),s[i]=1;
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=n&&!p&&!okok(b[i],j)) work(j++);
		if(j>n||p) return 0;
		s[j]--;
	}
	return 1;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		printf("%s\n",chk()?"Yes":"No");
	}
}