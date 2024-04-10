#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <stack>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
int n;
int a[210000];
int main()
{
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++){ scanf("%d",&a[i]);  mx=max(mx,a[i]); }
	for(int top=mx;top<=mx+10;top++)
	{
		int t[2]={0,0};
		rep(i,n)if ((top-a[i])%2)t[i%2]++;
		if (t[0]==t[1])
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}