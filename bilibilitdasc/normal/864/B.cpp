#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n;
string s;
string cur;
int ans;
set<char> a;
int getans()
{
	a.clear();
	for(int i=0;i<cur.size();i++)
	{
		a.insert(cur[i]);
	}
	return a.size();
}
int main()
{
	cin>>n>>s;
	n++;
	s+='A'; 
	for(int i=0;i<n;i++)
	{
		if(isupper(s[i]))
		{
			ans=max(ans,getans());
			cur="";
		}
		else
		{
			cur+=s[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
11
aaaaBaabAbA

12
zACaAbbaazzC

3
ABC

5
aabcc

10
aaaazAabcd

*/