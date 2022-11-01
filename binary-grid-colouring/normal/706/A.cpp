#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int x,y,n;
	int tx,ty,v;
	cin>>x>>y>>n;
	double ans = 100010;
	for(int i=1;i<=n;i++)
	{
		cin>>tx>>ty>>v;
		ans = min(ans,sqrt(pow(x-tx,2)+pow(y-ty,2))/v);
	}
	printf("%.10f\n",ans);
	return 0;
 }