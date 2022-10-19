#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n;
bool ip(int a)
{
	if(a==2||a==3) return 1;
	if(a==1) return 0;
	int t=a%6;
	if(t!=1&&t!=5) return 0;
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	//printf("%d\n",n); 
	if(ip(n))
	{
		printf("1\n%d\n",n);
	}
	else if(ip(n-2))
	{
		printf("2\n%d %d\n",2,n-2);
	}
	else if(n>3&&ip(n-4))
	{
		printf("3\n%d %d %d\n",2,2,n-4);
	}
	else
	{
		int i;
		for(i=n;!ip(i);i--);
		int e=n-i;
		for(int j=e;j>1;j--)
		{
			if(ip(j)&&ip(e-j))
			{
				printf("3\n%d %d %d\n",i,j,e-j);
				return 0;
			}
		}
	}
	return 0;
}