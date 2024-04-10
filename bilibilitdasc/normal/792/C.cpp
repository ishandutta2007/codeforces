#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
string s;
string ans;
string ans2;
int n;
int tot;
bool flag;
vector<int> find2;
void rev(string& t)
{
//	cout<<flag<<endl;
	rep(i,t.size())
	{
	//	cout<<i<<":'"<<t[i]<<"'"<<endl;
	//	cout<<i<<","<<t[i]%3<<endl;
		if(t[i]%3==1)
		{
		//	cout<<"true1"<<endl;
		//	cout<<t[i];
			t[i]+=flag;
		//	cout<<"->"<<t[i]<<endl;
		}
		else if(t[i]%3==2)
		{
		//	cout<<"true2"<<endl;
		//	cout<<t[i];
			t[i]-=flag;
		//	cout<<"->"<<t[i]<<endl;
		}
	//	cout<<i<<":'"<<t[i]<<"'"<<endl;
	}
//	cout<<t<<endl;
}
int main()
{
	cin>>s;
	n=s.size();
	rep(i,n) tot=(tot+s[i])%3;
	if(tot==0)
	{
		cout<<s<<endl;return 0;
	}
	if(tot==2) flag=1;
	rev(s);
//	cout<<s<<endl;
	for(int i=1;i<s.size();++i)
	{
		if(s[i]%3==1)
		{
			rep(j,s.size())
			{
				if(j!=i)
				{
					ans+=s[j];
				}
			}
			rev(ans);cout<<ans<<endl;
			return 0;
		}
	}
	if(s[0]%3==1)
	{
		ans=s.substr(1);
		if(!ans.empty())
		{
			if(ans[0]!='0')
			{
				rev(ans);
				cout<<ans<<endl;
				return 0;
			}
			bool fl=0;
			for(int i=1;i<ans.size();++i)
			{
				if(ans[i]!='0')
				{
					ans=ans.substr(i);
					fl=1;
					break;
				}
			}
			if(!fl)
			ans="";
		}
	}
	rep(i,s.size())
	{
		if(s[i]%3==2)
		find2.pb(i);
	}
	if(find2.size()<2)
	{
		if(ans.empty())
		{
			if(s.find("0")<=s.size()) cout<<"0"<<endl;
			else cout<<-1<<endl;
		}
		else
		{
			rev(ans);cout<<ans<<endl;
		}
		return 0;
	}
	if(find2.size()>=3||find2[0])
	{
		if(find2.size()==2)
		{
			int u=find2[0],v=find2[1];
			find2.clear();find2.pb(0);find2.pb(u);find2.pb(v);
		}
		ans2=s;
		ans2.erase(find2[2],1);ans2.erase(find2[1],1);
		rev(ans2);cout<<ans2<<endl;
		return 0;
	}
	ans2=s;
	ans2.erase(find2[1],1);ans2.erase(0,1);
	if(!ans2.empty())
	{
		bool fl=0;
		rep(i,ans2.size())
		{
			if(ans2[i]!='0')
			{
				fl=1;
				ans2=ans2.substr(i);
				break;
			}
		}
		if(!fl)
		ans2="";
	}
	if(!ans.empty())
	{
		rev(ans);cout<<ans<<endl;
	}
	else if(!ans2.empty())
	{
		rev(ans2);cout<<ans2<<endl;
	}
	else
	{
		if(s.find("0")<=s.size()) cout<<"0"<<endl;
		else cout<<-1<<endl; 
	}
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/