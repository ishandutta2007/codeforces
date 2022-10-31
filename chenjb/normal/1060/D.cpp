
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
long long l[210000],r[210000];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld%lld",&l[i],&r[i]);
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	long long ans=n;
	for(int i=1;i<=n;i++)ans+=max(l[i],r[i]);
	cout<<ans<<endl;
}