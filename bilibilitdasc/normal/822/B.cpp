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
int n,m;
string s,t;
string l;
vector<int> res;
vector<int> cres;
void chk(int a)
{
	cres.clear();
	l=t.substr(a,n);
	for(int i=0;i<n;i++)
	{
		if(l[i]!=s[i])
		{
			cres.push_back(i+1);
		}
	}
	if(cres.size()<res.size())
	{
		res=cres;
	}
}
int main()
{
	cin>>n>>m>>s>>t;
	for(int i=0;i<=n;i++) res.push_back(0);
	for(int i=0;i<=m-n;i++)
	{
		chk(i);
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i];
		if(i==res.size()-1)
		cout<<endl;
		else
		cout<<' ';
	}
	return 0;
}
/*
3 5
abc
xaybz

4 10
abcd
ebceabazcd

*/