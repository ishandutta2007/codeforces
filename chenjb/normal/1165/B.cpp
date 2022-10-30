#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
int n;
int a[210000];
int main()
{
	cin>>n;
	rep(i,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	rep(i,n)if (a[i]>=ans+1)ans++;
	cout<<ans<<endl;
}