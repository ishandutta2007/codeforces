#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
string l,f;
int t[27][200001],cnts[27],ans,n,m;
bool flag;
int main()
{
	scanf("%d",&n);
	cin>>l;
	for(int i=0;i<n;++i)
	{
		t[l[i]-'a'][++cnts[l[i]-'a']]=i+1;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		cin>>f;
		ans=0;
		for(int j=0;j<27;++j)
		{
			cnts[j]=0;
		}
		for(int j=0;j<f.length();++j)
		{
			++cnts[f[j]-'a'];
		}
		for(int j=0;j<26;++j)
		{
			ans=max(ans,t[j][cnts[j]]);
		}
		printf("%d\n",ans);
	}
	return 0;
}