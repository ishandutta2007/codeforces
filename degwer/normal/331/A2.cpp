#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<ll,vector<int> >pat;
ll rui[300001];
int main()
{
	int num;
	scanf("%d",&num);
	vector<ll>vec;
	rui[0]=0;
	for(int i=0;i<num;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vec.push_back(zan);
		pat[zan].push_back(i);
		rui[i+1]=max(rui[i],rui[i]+zan);
	}
	map<ll,vector<int> >::iterator it=pat.begin();
	ll maxi=-1000000000000000000LL;
	int l,r;
	for(;;)
	{
		if(it==pat.end())
		{
			break;
		}
		sort((*it).second.begin(),(*it).second.end());
		if((*it).second.size()>=2)
		{
			if(maxi<rui[(*it).second[(*it).second.size()-1]-1+1]-rui[(*it).second[0]+1]+(*it).first*2)
			{
				maxi=rui[(*it).second[(*it).second.size()-1]-1+1]-rui[(*it).second[0]+1]+(*it).first*2;
				l=(*it).second[0];
				r=(*it).second[(*it).second.size()-1];
			}
		}
		it++;
	}
	printf("%I64d ",maxi);
	vector<int>ans;
	for(int i=0;i<l;i++)
	{
		ans.push_back(i);
	}
	for(int i=l+1;i<=r-1;i++)
	{
		if(vec[i]<0)
		{
			ans.push_back(i);
		}
	}
	for(int i=r+1;i<vec.size();i++)
	{
		ans.push_back(i);
	}
	printf("%d\n",int(ans.size()));
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",ans[i]+1);
	}
	printf("\n");
}