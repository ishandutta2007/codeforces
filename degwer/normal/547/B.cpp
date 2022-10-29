#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 200001
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
typedef pair<int,int>pii;
int ans[200001];
int main()
{
	int num;
	scanf("%d",&num);
	uf.init();
	vector<int>v;
	int maxi=0;
	for(int i=0;i<num;i++)
	{
		int z;
		scanf("%d",&z);
		v.push_back(z);
		maxi=max(maxi,z);
	}
	vector<pii>vec;
	for(int i=0;i<num-1;i++)
	{
		vec.push_back(make_pair(min(v[i],v[i+1]),i));
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	ans[1]=maxi;
	for(int i=0;i<num-1;i++)
	{
		uf.unite(vec[i].second,vec[i].second+1);
		ans[uf.ren[uf.find(vec[i].second)]]=max(ans[uf.ren[uf.find(vec[i].second)]],vec[i].first);
	}
	for(int i=num;i>=1;i--)
	{
		ans[i-1]=max(ans[i],ans[i-1]);
	}
	for(int i=1;i<=num;i++)
	{
		if(i!=1)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
}