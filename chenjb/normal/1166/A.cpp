#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int a[50];
int main()
{
	int n;
	char s[200];
	cin>>n;
	rep(i,n)
	{
		scanf("%s",s);
		a[s[0]-'a']++;
	}
	long long ans=0;
	for(int i=0;i<26;i++)
	{
		int l=a[i]/2;
		int r=a[i]-l;
		ans=ans+l*(l-1)/2+r*(r-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}