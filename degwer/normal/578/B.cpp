#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll rui1[200001],rui2[200001];
int main()
{
	int num,kai;
	ll tim;
	scanf("%d%d%I64d",&num,&kai,&tim);
	vector<ll>vec;
	for(int i=0;i<num;i++)
	{
		int z;
		scanf("%d",&z);
		vec.push_back(z);
	}
	for(int i=0;i<num;i++)rui1[i+1]=rui1[i]|vec[i];
	for(int i=num-1;i>=0;i--)rui2[i]=rui2[i+1]|vec[i];
	ll maxi=0;
	for(int i=0;i<num;i++)
	{
		ll t=vec[i];
		for(int j=0;j<kai;j++)t*=tim;
		maxi=max(maxi,t|rui1[i]|rui2[i+1]);
	}
	printf("%I64d\n",maxi);
}