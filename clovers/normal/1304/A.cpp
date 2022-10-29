#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=100010;

int x,y,a,b,t;

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if((y-x)%(a+b)==0)
		{
			printf("%d\n",(y-x)/(a+b));
		}
		else puts("-1");
	}
	return 0;
}