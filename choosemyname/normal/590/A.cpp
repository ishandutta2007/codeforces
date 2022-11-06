#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int num[1000010];
vector<pair<int,int> > v;
int main()
{
	int n,n1;
	cin>>n;
	for(n1=2;n1<=n+1;n1++)
		scanf("%d",&num[n1]);
	num[1]=num[2];
	num[n+2]=num[n+1];
	int sd=0;
	for(n1=2;n1<=n+2;n1++)
		if(num[n1]!=num[n1-1])
		{
			if(sd==0)
				sd=n1-1;
		}
		else
			if(sd!=0)
			{
				v.push_back(make_pair(sd,n1-1));
				sd=0;
			}
	int ans=0;
	for(int i=0;i<v.size();i++)
		ans=max(ans,(v[i].second-v[i].first)/2);
	cout<<ans<<endl;
	for(int i=0;i<v.size();i++)
	{
		int a=v[i].first,b=v[i].second;
	//	cout<<a<<' '<<b<<endl;
		while(a<=b)
		{
			num[a]=num[v[i].first];
			num[b]=num[v[i].second];
			a++;
			b--;
		}
	}
	for(n1=2;n1<=n+1;n1++)
		printf("%d ",num[n1]);
}