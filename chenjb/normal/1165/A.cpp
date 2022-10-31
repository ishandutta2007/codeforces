#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
char s[210000];
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	scanf("%s",s+1);
	int ans=0;
	for(int i=n-x+1;i<=n;i++)
		if (i==n-y && s[i]!='1')ans++;
		else if (i!=n-y && s[i]!='0')ans++;
	cout<<ans<<endl;
}