#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;
int t,n,a[N];

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		if(n==1) puts("1");
		else printf("%d\n",(n+2)/2);
	}
	return 0;
}