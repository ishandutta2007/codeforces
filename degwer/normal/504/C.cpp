#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int dat[100000];
int da[100000],db[100000];
int dd[100000];
int get(vector<int>vec)
{
	for(int i=0;i<vec.size();i++)dd[i]=0;
	for(int i=0;i<vec.size();i++)dd[vec[i]]--;
	int cnt=0;
	for(int i=0;i<vec.size();i++)if(dd[i]<0)cnt++;
	for(int i=0;i<vec.size();i++)
	{
		dd[vec[i]]+=2;
		if(dd[vec[i]]==0||dd[vec[i]]==1)cnt--;
		if(cnt==0)return vec.size()-i-1;
	}
}
int main()
{
	ll num;
	scanf("%I64d",&num);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		zan--;
		vec.push_back(zan);
		dat[zan]++;
	}
	int cp=0;
	for(int i=0;i<num;i++)cp+=dat[i]%2;
	if(cp>1)
	{
		printf("0\n");
		return 0;
	}
	ll bp=0;
	for(int i=0;i<num;i++)
	{
		if(vec[i]==vec[num-i-1])bp=i+1;
		else break;
	}
	if(bp==num)
	{
		printf("%I64d\n",num*(num+1)/2);
		return 0;
	}
	for(int i=bp;i<num/2;i++)
	{
		da[vec[i]]++;
		db[vec[num-i-1]]++;
	}
	bool f=true;
	for(int i=0;i<num;i++)
	{
		if(da[i]!=db[i])f=false;
	}
	if(f)
	{
		ll ep=num/2;
		for(int i=num/2-1;i>=0;i--)
		{
			if(vec[i]==vec[num-i-1])ep--;
			else break;
		}
		printf("%I64d\n",(bp+1)*(num-ep+1)*2-(bp+1)*(bp+1));
		return 0;
	}
	ll rrm=get(vec);
	reverse(vec.begin(),vec.end());
	ll lrm=get(vec);
	printf("%I64d\n",(bp+1)*(rrm+1)+(bp+1)*(lrm+1)-(bp+1)*(bp+1));
}