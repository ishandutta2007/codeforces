#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int main()
{
	int y,b,r;
	cin>>y>>b>>r;
	int ans=0;
	rep(i,y)
	if (i+1<=b && i+2<=r)ans=max(ans,i+i+1+i+2);
	cout<<ans<<endl;
	return 0;
}