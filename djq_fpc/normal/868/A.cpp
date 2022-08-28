#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j;
string st[105],st1;
bool ok1,ok2;
int main()
{
	//ios::sync_with_stdio(0);
	cin>>st1>>n;
	for (i=1;i<=n;i++) cin>>st[i];
	for (i=1;i<=n;i++)
	{
		if (st[i]==st1)
		{
			cout<<"Yes";
			return 0;
		}
		if (st[i][1]==st1[0]) ok1=1;
		if (st[i][0]==st1[1]) ok2=1;
	}
	if (ok1&&ok2) cout<<"Yes"; else cout<<"No";
	return 0;
}