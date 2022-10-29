#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int num;
	scanf("%d",&num);
	for(int p=0;p<num;p++)
	{
		ll a,b;
		scanf("%I64d%I64d",&a,&b);
		vector<ll>vec;
		for(int i=0;i<=60;i++)
		{
			vec.push_back(a%2);
			a/=2;
		}
		reverse(vec.begin(),vec.end());
		for(int i=60;i>=0;i--)
		{
			int now=0;
			ll ret=0;
			for(int j=0;j<=60;j++)
			{
				ret*=2;
				if(vec[j]==1||i-(61-j)==now)
				{
					now++;
					ret++;
				}
			}
			if(ret<=b)
			{
				printf("%I64d\n",ret);
				break;
			}
		}
	}
}