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
char s[100050];
void solve()
{
	scanf("%s",s);
	int len=strlen(s);
	vector<int> ans[2];
	int r=0,ind=0;
	while(ind<len)
	{
		if(s[ind]==':'&&s[ind+1]==':')
		r++;
		while(s[ind]==':')
		ind++;
		if(ind>=len) break;
		int num;
		sscanf(s+ind,"%x",&num);
		ans[r].pb(num);
		while(ind<len&&s[ind]!=':')
		ind++;
	}
	int num=8-ans[0].size()-ans[1].size();
	rep(i,num) ans[0].pb(0);
	rep(i,ans[1].size()) ans[0].pb(ans[1][i]);
	rep(i,8)
	{
		if(i) printf(":");
		printf("%04x",ans[0][i]);
	}
	printf("\n");
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	solve();
}
/**
not and or bitand bitor xor int long short signed unsigned float double using
char struct static class this return auto union enum extern register void volatile 
break sizeof asm bool catch const_cast delete dynamic_cast explicit export friend 
reinterpret_cast static_cast template throw try typeid typename virtual namespace 
typedef const constexpr true false if else mutable new operator private protected
for while do case goto default continue wchar_t switch inline static_assert public
/*
*/
/**
try again
virtual reality
do sth
best friend
this switch is not true 
have a break
now continue
return home
double kill
long long ago
in public or private
/*
*/