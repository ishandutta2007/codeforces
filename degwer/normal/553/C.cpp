#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define SIZE 100000
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	void init()
	{
		for(int i=0;i<SIZE;i++)
		{
			par[i]=i;
			ran[i]=0;
			ren[i]=1;
		}
	}
	int find(int a)
	{
		if(a==par[a])return a;
		else return par[a]=find(par[a]);
	}
	void unite(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(a==b)return;
		if(ran[a]>ran[b])
		{
			par[b]=a;
			ren[a]+=ren[b];
		}
		else
		{
			par[a]=b;
			ren[b]+=ren[a];
		}
		if(ran[a]==ran[b])ran[b]++;
	}
};
unionfind uf;
vector<int>pat[100000];
typedef long long ll;
ll mod=1000000007;
vector<int>zp[100000];
int col[100000];
bool isok=true;
void dfs(int node,int c)
{
	if(c!=col[node]&&col[node]!=0)
	{
		isok=false;
	}
	if(col[node]!=0)return;
	col[node]=c;
	for(int i=0;i<zp[node].size();i++)dfs(zp[node][i],-c);
}
int main()
{
	int num,way;
	scanf("%d%d",&num,&way);
	uf.init();
	for(int i=0;i<way;i++)
	{
		int za,zb,zc;
		scanf("%d%d%d",&za,&zb,&zc);
		za--;
		zb--;
		if(zc==1)uf.unite(za,zb);
		else
		{
			pat[za].push_back(zb);
			pat[zb].push_back(za);
		}
	}
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<pat[i].size();j++)
		{
			if(uf.find(i)==uf.find(pat[i][j]))
			{
				printf("0\n");
				return 0;
			}
			zp[uf.find(pat[i][j])].push_back(uf.find(i));
			zp[uf.find(i)].push_back(uf.find(pat[i][j]));
		}
	}
	int cnt=0;
	for(int i=0;i<num;i++)
	{
		if(uf.find(i)==i&&col[i]==0)
		{
			cnt++;
			dfs(i,1);
		}
	}
	if(!isok)
	{
		printf("0\n");
		return 0;
	}
	ll r=1;
	for(int i=0;i<cnt-1;i++)r=(r*2)%mod;
	printf("%I64d\n",r);
}