#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int use[250][250];
int ans[1000000];
int main()
{
	int bin,num;
	scanf("%d%d",&bin,&num);
	fill(ans,ans+bin,1);
	vector<pair<int,int> >vec;
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		vec.push_back(make_pair(za,zb));
	}
	for(int l=0;l<250;l++)
	{
		for(int m=0;m<250;m++)
		{
			use[l][m]=0;
			if(l==m)
			{
				use[l][m]=1;
			}
		}
	}
	for(int j=0;j<num;j++)
	{
		for(int k=0;k<num;k++)
		{
			if(use[j][k]!=0)
			{
				continue;
			}
			use[j][k]=1;
			use[k][j]=1;
			vector<int>fuga;
			fuga.push_back(j);
			fuga.push_back(k);
			int ret=0;
			for(int m=0;m<num;m++)
			{
				ll hoge1=vec[k].first-vec[j].first;
				hoge1*=vec[m].second-vec[k].second;
				ll hoge2=vec[k].second-vec[j].second;
				hoge2*=vec[m].first-vec[k].first;
				if(hoge1==hoge2)
				{
					ret++;
					fuga.push_back(m);
					for(int o=0;o<fuga.size();o++)
					{
						use[fuga[o]][m]=1;
						use[m][fuga[o]]=1;
					}
				}
			}
			ll hoge3=vec[k].first-vec[j].first;
			ll hoge4=vec[k].second-vec[j].second;
			if(hoge4==0)
			{
				continue;
			}
			ll hoge5=hoge3;
			hoge5*=vec[k].second;
			if(hoge5%hoge4==0)
			{
				hoge5/=hoge4;
				ll hoge6=vec[k].first;
				hoge6-=hoge5;
				if(hoge6>=1&&hoge6<=bin)
				{
					ans[hoge6-1]=max(ans[hoge6-1],ret);
				}
			}
		}
	}
	int sum=0;
	for(int p=0;p<bin;p++)
	{
		if(p<bin)
		{
			sum+=ans[p];
		}
	}
	printf("%d\n",sum);
}