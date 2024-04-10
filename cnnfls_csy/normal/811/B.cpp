#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#define sqr(x) (x)*(x)
#define fast ios::sync_with_stdio(false);
using namespace std;
int n,m,x,y,z,j,i,p[100005],now[100005],s;
string st;
int main()
{
	fast;
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>p[i];
	for (j=1;j<=m;j++)
	{
		cin>>x>>y>>z;
		s=0;
		for (i=x;i<=y;i++) if (p[i]<p[z]) s++;
		//cerr<<s<<endl;
		if (s+x==z) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}