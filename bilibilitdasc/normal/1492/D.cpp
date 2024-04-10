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
int main()
{
	int a,b,k;
	scanf("%d%d%d",&a,&b,&k);
	if(k==0)
	{
		printf("Yes\n");
		for(int i=0;i<b;i++)
		{
			printf("1");
		}
		for(int i=0;i<a;i++)
		{
			printf("0");
		}
		printf("\n");
		for(int i=0;i<b;i++)
		{
			printf("1");
		}
		for(int i=0;i<a;i++)
		{
			printf("0");
		}
		printf("\n");
		return 0;
	}
	if(a+b-2<k)
	{
		printf("No\n");
		return 0;
	}
	if(a==0)
	{
		printf("No\n");
		return 0;
	}
	if(b==1)
	{
		printf("No\n");
		return 0;
	}
	a-=1;
	b-=2;
	int aa=a;
	int bb=b;
	int s=a+b;
	printf("Yes\n");
	printf("11");
	for(int i=0;i<k-1;i++)
	{
		if(a>0)
		{
			cout<<"0";
			a--;
		}
		else
		{
			cout<<"1";
			b--;
		}
	}
	printf("0");
	for(int i=k-1;i<s;i++)
	{
		if(a>0)
		{
			cout<<"0";
			a--;
		}
		else
		{
			cout<<"1";
			b--;
		}
	}
	printf("\n");
	printf("10");
	for(int i=0;i<k-1;i++)
	{
		if(aa>0)
		{
			cout<<"0";
			aa--;
		}
		else
		{
			cout<<"1";
			bb--;
		}
	}
	printf("1");
	for(int i=k-1;i<s;i++)
	{
		if(aa>0)
		{
			cout<<"0";
			aa--;
		}
		else
		{
			cout<<"1";
			bb--;
		}
	}
	printf("\n");
	return 0;
}