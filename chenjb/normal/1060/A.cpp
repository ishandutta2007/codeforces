
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
using namespace std;
int n;
char s[200];
int a[300];
int main()
{
	cin>>n;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[s[i]-'0']++;
	int ans=0;
	for(int i=1;i<=a[8];i++)
	{
		if (i*10<=n-i)ans=i;
	}
	cout<<ans<<endl;
	return 0;
}