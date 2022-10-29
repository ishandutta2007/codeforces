#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
bool isok(ll a,ll b,ll c)
{
	if((a+b+c)%2==1)
	{
		return false;
	}
	ll zan=(a+b+c)/2;
	if(zan-a<1||zan-b<1||zan-c<1)
	{
		return false;
	}
	return true;
}
vector<pii>vec;
ll po(ll a,int b)
{
	ll ret=1;
	for(int i=0;i<b;i++)
	{
		ret*=a;
	}
	return ret;
}
ll ans=0;
void calc(int pt,ll a,ll b,ll c)
{
	if(pt==vec.size())
	{
		if(isok(a,b,c))
		{
			ans++;
		}
		return;
	}
	for(int i=0;i<=vec[pt].second;i++)
	{
		for(int j=0;j<=vec[pt].second;j++)
		{
			if(i+j>vec[pt].second)
			{
				break;
			}
			int k=vec[pt].second-i-j;
			calc(pt+1,a*po(vec[pt].first,i),b*po(vec[pt].first,j),c*po(vec[pt].first,k));
		}
	}
}
void bun(ll a)
{
	for(ll i=2;;i++)
	{
		if(i*i>a)
		{
			break;
		}
		int now=0;
		for(;;)
		{
			if(a%i!=0)
			{
				break;
			}
			now++;
			a/=i;
		}
		if(now!=0)
		{
			vec.push_back(make_pair(i,now));
		}
	}
	if(a!=1)
	{
		vec.push_back(make_pair(a,1));
	}
}
int main()
{
	ll a;
	scanf("%I64d",&a);
	if(a%3!=0)
	{
		printf("0\n");
		return 0;
	}
	a/=3;
	bun(a);
	calc(0,1,1,1);
	printf("%I64d\n",ans);
}