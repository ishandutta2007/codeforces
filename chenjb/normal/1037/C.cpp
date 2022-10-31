#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int n;
char a[1100000];
char b[1100000];
int main()
{
	cin>>n;
	scanf("%s",a+1);
	scanf("%s",b+1);
	int ans=0;
	for(int i=1;i<n;i++)
	{
		if (a[i]!=b[i]&&a[i+1]!=b[i+1]&&a[i]==b[i+1]&&a[i+1]==b[i]){ ans++; swap(a[i],a[i+1]);}
	}
	for(int i=1;i<=n;i++)
		if (a[i]!=b[i])ans++;
	cout<<ans<<endl;
	return 0;
}