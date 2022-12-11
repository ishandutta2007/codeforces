#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define MN 10000
char s[MN+9];
int f[MN+9][3];
vector<string> ans;
map<string,int> mp;
int main()
{
	int n,i,j,k;
	scanf("%s",s+1);n=strlen(s+1);
	f[n+1][1]=1;
	for(i=n;i>5;--i)for(j=1;j<=2;++j)for(k=1;k<=2;++k)
		if(string(s+i,s+i+j+1)!=string(s+i+j+1,s+i+j+1+k+1))f[i][j]|=f[i+j+1][k];
	for(i=1;i<=n;++i)for(j=1;j<=2;++j)if(f[i][j])
		mp[string(s+i,s+i+j+1)]++?0:(ans.push_back(string(s+i,s+i+j+1)),0);
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();++i)cout<<ans[i]<<endl;
}