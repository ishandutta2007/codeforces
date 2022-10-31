#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cstdlib>
#include <stack>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
int n;
int a[500];
int main()
{
	cin>>n;
	for(int i=1;i<=n/2;i++)scanf("%d",&a[i]);
	sort(a+1,a+(n/2)+1);
	int ans1=0,ans2=0;
	for(int i=1;i<=n/2;i++)
		ans1+=abs(2*i-1-a[i]);
	for(int i=1;i<=n/2;i++)
		ans2+=abs(2*i-a[i]);
	cout<<min(ans1,ans2)<<endl;
}