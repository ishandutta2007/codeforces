#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
typedef pair<int,int> PII;
int vote[maxn][maxn];
int sum[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&vote[i][j]);
			sum[j]+=vote[i][j];
		}
	}
	vector<int> ans;
	for(int i=1;i<n;i++)
	{
		vector<PII> delta;
		for(int j=1;j<=m;j++)
			delta.push_back(make_pair(vote[j][n]-vote[j][i],j));
		sort(delta.begin(),delta.end(),greater<PII>());
		vector<int> curans;
		int cur=sum[i],tar=sum[n];
		int p=0;
		while(cur<tar)
		{
			int id=delta[p].second;
			cur-=vote[id][i];
			tar-=vote[id][n];
			p++;
			curans.push_back(id);
		}
	//	cout<<i<<":"<<curans.size()<<endl;
		if(i==1||curans.size()<ans.size()) ans=curans;
	}
	printf("%d\n",(int)ans.size());
	for(auto u:ans)
		printf("%d ",u);
	puts("");
}