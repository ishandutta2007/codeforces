#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll k,mok;
	scanf("%I64d%I64d",&mok,&k);
	vector<ll>vec;
	vec.push_back(1);
	for(int i=1;;i++)
	{
		ll zan=0;
		for(int j=i-1;j>=max(0LL,i-k);j--)
		{
			zan+=vec[j];
		}
		if(zan>mok)
		{
			break;
		}
		vec.push_back(zan);
	}
	reverse(vec.begin(),vec.end());
	vector<ll>ans;
	for(int i=0;i<vec.size();i++)
	{
		for(;;)
		{
			if(mok<vec[i])
			{
				break;
			}
			ans.push_back(vec[i]);
			mok-=vec[i];
		}
	}
	if(ans.size()==1)
	{
		ans.push_back(0);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%I64d",ans[i]);
	}
	printf("\n");
}