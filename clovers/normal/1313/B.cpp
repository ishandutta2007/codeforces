#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int n,x,y,t;

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&y);
		printf("%d %d\n",min(n,max(1,x+y-n+1)),min(n,x+y-1));
	}
	return 0;
}