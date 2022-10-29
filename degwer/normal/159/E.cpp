#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	long long cube;
	scanf("%I64d",&cube);
	vector<pair<long long,vector<pair<long long,long long> > > >vec;
	vector<pair<long long,long long> >damy;
	vector<pair<long long,long long> >damy2;
	vector<long long>damy3;
	vector<pair<long long,long long> >damy4;
	for(int j=1;j<=cube+1;j++)
	{
		damy2.push_back(make_pair(2000000000,2000000000));
	}
	vector<pair<pair<long long,long long>,long long> >veczan;
	vector<long long>veccolor;
	for(int i=1;i<=cube;i++)
	{
		long long zcol,high;
		scanf("%I64d%I64d",&zcol,&high);
		veczan.push_back(make_pair(make_pair(zcol,high),i));
	}
	sort(veczan.begin(),veczan.end());
	int nowcolor=-1;
	for(int u=1;u<=veczan.size();u++)
	{
		if(veczan[u-1].first.first!=nowcolor)
		{
			vec.push_back(make_pair(veczan[u-1].first.first,damy));
			nowcolor=veczan[u-1].first.first;
		}
		vec[vec.size()-1].second.push_back(make_pair(veczan[u-1].first.second,veczan[u-1].second));
	}



	long long maxcos=0;
	for(int k=1;k<=vec.size();k++)
	{
		sort(vec[k-1].second.begin(),vec[k-1].second.end());
		reverse(vec[k-1].second.begin(),vec[k-1].second.end());
		if(maxcos<vec[k-1].second.size())
		{
			maxcos=vec[k-1].second.size();
		}
	}
	sort(vec.begin(),vec.end());
	vector<vector<pair<long long,long long> > >veckos;
	for(long long n=1;n<=maxcos;n++)
	{
		veckos.push_back(damy4);
	}
	for(int l=1;l<=vec.size();l++)
	{
		long long nowrui=0;
		for(int m=1;m<=vec[l-1].second.size();m++)
		{
			nowrui+=vec[l-1].second[m-1].first;
			veckos[m-1].push_back(make_pair(nowrui,vec[l-1].first));
		}
	}
	for(int o=1;o<=maxcos;o++)
	{
		sort(veckos[o-1].begin(),veckos[o-1].end());
		reverse(veckos[o-1].begin(),veckos[o-1].end());
	}
	long long maxhigh=0;
	pair<long long,long long>bigger;
	pair<long long,long long>smaller;
	for(int p=1;p<=maxcos-1;p++)
	{
		if(veckos[p-1][0].second!=veckos[p][0].second)
		{
			if(maxhigh<veckos[p-1][0].first+veckos[p][0].first)
			{
				maxhigh=veckos[p-1][0].first+veckos[p][0].first;
				bigger=veckos[p][0];
				smaller=veckos[p-1][0];
			}
		}
		else
		{
			if(veckos[p-1].size()!=1)
			{
				if(maxhigh<veckos[p-1][1].first+veckos[p][0].first)
				{
					maxhigh=veckos[p-1][1].first+veckos[p][0].first;
					bigger=veckos[p][0];
					smaller=veckos[p-1][1];
				}
			}
			if(veckos[p].size()!=1)
			{
				if(maxhigh<veckos[p][1].first+veckos[p-1][0].first)
				{
					maxhigh=veckos[p][1].first+veckos[p-1][0].first;
					smaller=veckos[p-1][0];
					bigger=veckos[p][1];
				}
			}
		}
	}
	for(int q=1;q<=maxcos;q++)
	{
		if(veckos[q-1].size()!=1)
		{
			if(maxhigh<veckos[q-1][0].first+veckos[q-1][1].first)
			{
				maxhigh=veckos[q-1][0].first+veckos[q-1][1].first;
				bigger=veckos[q-1][0];
				smaller=veckos[q-1][1];
			}
		}
	}
	vector<long long>bignums;
	long long bigsum=0;
	vector<long long>smallnums;
	long long smallsum=0;
	long long biglow=lower_bound(vec.begin(),vec.end(),make_pair(bigger.second,damy))-vec.begin();
	long long smalllow=lower_bound(vec.begin(),vec.end(),make_pair(smaller.second,damy))-vec.begin();
	for(int r=0;;r++)
	{
		bigsum+=vec[biglow].second[r].first;
		bignums.push_back(vec[biglow].second[r].second);
		if(bigsum==bigger.first)
		{
			break;
		}
	}
	for(int r=0;;r++)
	{
		smallsum+=vec[smalllow].second[r].first;
		smallnums.push_back(vec[smalllow].second[r].second);
		if(smallsum==smaller.first)
		{
			break;
		}
	}
	printf("%I64d\n",maxhigh);
	vector<long long>returns;
	for(int s=1;s<=smallnums.size();s++)
	{
		returns.push_back(bignums[s-1]);
		returns.push_back(smallnums[s-1]);
	}
	if(bignums.size()>smallnums.size())
	{
		returns.push_back(bignums[bignums.size()-1]);
	}
	printf("%d\n",returns.size());
	for(int t=1;t<=returns.size();t++)
	{
		printf("%I64d",returns[t-1]);
		if(t!=returns.size())
		{
			printf(" ");
		}
	}
	printf("\n");
}