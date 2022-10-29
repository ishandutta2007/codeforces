#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int T,n,a,b;

int main()
{
	cin>>T;
	while(T--)
	{
		scanf("%d%d",&a,&b);
		if(a>b*2) printf("%d\n",b);
		else if(a*2<b) printf("%d\n",a);
		else printf("%d\n",(a+b)/3);
	}
	return 0;
}