#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
bool calc(vector<ll>vh,vector<ll>vd,ll med)
{
	int nowpt=0;
	for(int i=0;i<vh.size();i++)
	{
		ll pls=0LL;
		if(vd[nowpt]+med<vh[i])
		{
			return false;
		}
		if(vd[nowpt]<vh[i])
		{
			pls=max(pls,med-(vh[i]-vd[nowpt])*2);
			pls=max(pls,(med-(vh[i]-vd[nowpt]))/2);
		}
		else
		{
			pls=med;
		}
		for(;;)
		{
			if(nowpt==vd.size())
			{
				return true;
			}
			if(vd[nowpt]>vh[i]+pls)
			{
				break;
			}
			nowpt++;
		}
	}
	return false;
}
int main()
{
	int numh,numd;
	scanf("%d%d",&numh,&numd);
	vector<ll>vech,vecd;
	for(int i=0;i<numh;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vech.push_back(zan);
	}
	for(int i=0;i<numd;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vecd.push_back(zan);
	}
	ll beg=0,end=1000000000000LL;
	for(;;)
	{
		ll med=(beg+end)/2;
		if(calc(vech,vecd,med))
		{
			end=med;
		}
		else
		{
			beg=med+1;
		}
		if(beg==end)
		{
			printf("%I64d\n",beg);
			break;
		}
	}
}