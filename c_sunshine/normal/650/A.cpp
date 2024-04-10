#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
long long ans;
int n;
pair<int,int> p[200005];
map<int,int> X,Y;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].first,&p[i].second);
		ans+=X[p[i].first]++;
		ans+=Y[p[i].second]++;
	}
	sort(p+1,p+n+1);
	for(int i=1,j=1;i<=n;i=j)
	{
		for(;j<=n&&p[j]==p[i];j++);
		ans-=(long long)(j-i)*(j-i-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}