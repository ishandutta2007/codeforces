#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<ll,ll>ma;
int main()
{
	ll mod,mok,num;
	scanf("%I64d%I64d%I64d",&mod,&mok,&num);
	vector<ll>vec;
	for(int i=0;i<num;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vec.push_back(zan);
	}
	ll ret=0;
	ll now=0;
	for(int i=vec.size()-1;i>=0;i--)
	{
		ma[now]++;
		now+=vec[i];
		now%=(mod-1);
		ret+=ma[(now-mok+mod-1)%(mod-1)];
	}
	if(mok==mod-1||mok==0)
	{
		ll hoge=0;
		ll fuga=0;
		for(int i=0;i<num;i++)
		{
			if(vec[i]==0)
			{
				hoge++;
			}
			else
			{
				fuga+=(hoge+1)*hoge/2;
				hoge=0;
			}
		}
		fuga+=(hoge+1)*hoge/2;
		if(mok==mod-1)
		{
			ret-=fuga;
		}
		else
		{
			ret=fuga;
		}
	}
	printf("%I64d\n",ret);
}