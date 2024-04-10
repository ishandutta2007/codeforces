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
int t,a,b;
void solve()
{
	int ans=1000;
	int plus=0;
	cin>>a>>b;
	if(b==1)
	{
		b++;
		plus=1;
	}
	for(int k=0;k<100;k++)
	{
		int aa=a;
		int nowans=k;
		int newb=b+k;
		while(aa&&nowans<100)
		{
			nowans++;
			aa/=newb;
		}
		if(ans>nowans)
		ans=nowans;
	}
	cout<<ans+plus<<endl;
}
int main()
{
	cin>>t;
	while(t--) solve();
	return 0;
}