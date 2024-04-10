#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
int n;
int a[110];
int main()
{
	cin>>n;
	rep(i,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i+=2)ans+=abs(a[i+1]-a[i]);
	cout<<ans<<endl;
}