#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
str s,ans;
bool v;
void kill()
{
	prt("Error occurred");
	exit(0);
}
void dfs()
{
	if(cin>>s)
	{
		ans+=s;
		if(s=="pair")//pair<thing_1,thing_2>
		{
			ans+="<";
			dfs();//thing_1
			ans+=",";
			dfs();//thiing_2
			ans+=">";
		}
	}
	else
	{
		kill();
	}
}
int main()
{
	cin>>s;
	dfs();
	if(cin>>s)
	kill();
	prt(ans);
	return 0;
}