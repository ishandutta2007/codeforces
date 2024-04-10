#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> v;
int main()
{
	long long x,y,l,r,i,j,ans=0;
	scanf("%I64d%I64d%I64d%I64d",&x,&y,&l,&r);
	v.push_back(l-1);v.push_back(r+1);
	for(i=1;;i*=x)
	{
		for(j=1;;j*=y)
		{
			if(i+j>=l&&i+j<=r)v.push_back(i+j);
			if(j>r/y)break;
		}
		if(i>r/x)break;
	}
	sort(v.begin(),v.end());
	for(i=1;i<v.size();++i)ans=max(ans,v[i]-v[i-1]-1);
	printf("%I64d",ans);
}