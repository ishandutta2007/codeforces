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
int t;
void solve()
{
	string s;
	cin>>s;
	int s0=0;
	for(int i=0;i<s.size();i++) if(s[i]=='0') s0++;
	for(int i=0;i<=s0;i++)
	{
		bool temp=1;
		vector<int> v;
		v.clear();
		int tmp=i;
		for(int j=0;j<s.size();j++)
		{
			if(tmp!=0&&s[j]=='1') v.push_back(j);
			else if(tmp!=0&&s[j]=='0') tmp--;
			else if(tmp==0&&s[j]=='0') v.push_back(j);
		}
		for(int i=1;i<v.size();i++)
		{
			if(v[i]-v[i-1]==1) 
			{
				temp=0;
				break;
			}
		}
		if(temp)
		{
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
5
10101011011
0000
11111
110
1100
*/