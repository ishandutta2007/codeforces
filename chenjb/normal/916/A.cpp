#include <bits/stdc++.h>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
using namespace std;
bool check(int a,int b)
{
	if (a % 10 == 7 || a/10==7 || b % 10==7 || b/10==7)return 1;
	return 0;
}
int main()
{
	int hh,mm;
	int x;
	cin>>x;
	cin>>hh>>mm;
	int ans=0;
	while (1)
	{
		if (check(hh,mm))break;
		mm-=x;
		ans++;
		if (mm<0){ hh--; mm+=60; }
		if (hh<0)hh=23;
	}
	cout<<ans<<endl;
}