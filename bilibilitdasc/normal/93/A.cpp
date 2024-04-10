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
int n,m;
bool isf(int a)
{
	return (a-1)%m==0;
}
bool isl(int a)
{
	return a%m==0||a==n;
}
int geth(int a)
{
	return (a-1)/m;
}
int main()
{
	int a,b;
	cin>>n>>m>>a>>b;
	if(isf(a)&&isl(b))
	{
		cout<<1<<endl;
		return 0;
	}
	if(geth(a)==geth(b))
	{
		cout<<1<<endl;
		return 0;
	}
	if(isf(a)||isl(b)||geth(b)-geth(a)==1)
	{
		cout<<2<<endl;
		return 0;
	}
	if((a-1)%m==(b-1)%m+1)
	{
		cout<<2<<endl;
		return 0;
	}
	cout<<3<<endl;
	return 0;
}
/*
11 4 3 9

20 5 2 20

7 4 1 7

9 4 1 7

20 4 2 19

*/