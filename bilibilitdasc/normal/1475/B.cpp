#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
int n;
int a;
void solve(int num)
{
	if(num/2020>=num%2020)
	prt("YES");
	else
	prt("NO");
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	while(n--)
	{
		cin>>a;
		solve(a);
	}
	return 0;
}