#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int n,s;

int main()
{
	scanf("%d%d",&n,&s);
	if(n*2>s) 
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1;i<=n-1;i++) printf("1 ");
	printf("%d\n",s-n+1);
	printf("%d\n",s/2);
	return 0;
}