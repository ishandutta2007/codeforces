#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a);i<=(b);++i)
#define perk(i,a,b) for(int i=(a);i>=(b);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
string s;
int n;
map<char,int> cnt;
map<char,int>::iterator itr,jtr;
void Q()
{
	cin>>s;
	n=s.size();
	cnt.clear();
	rep(i,n) ++cnt[s[i]];
	if(cnt.size()==1)
	{
		cout<<s<<endl;
		return ;
	}
	for(itr=cnt.begin();itr!=cnt.end();++itr)
	{
		if((itr->se)==1)
		{
			//cout<<(itr->fi)<<endl;
			cout<<(itr->fi);
			s.erase(s.find(itr->fi),1);
			sort(s.begin(),s.end());
			cout<<s<<endl;
			return ;
		}
	}
	itr=jtr=cnt.begin();
	++jtr;
	if(((itr->se)<<1)<=n+2)
	{
		--(itr->se);
		cout<<(itr->fi);
		while(itr->se)
		{
			--(itr->se);
			cout<<(itr->fi);
			if((jtr->se)==0) ++jtr;
			if(jtr==cnt.end()) break;
			cout<<(jtr->fi);
			--(jtr->se);
		}
		for(;jtr!=cnt.end();)
		{
			if(jtr->se)
			{
				cout<<(jtr->fi);
				--(jtr->se);
			}
			else
			++jtr;
		}
		cout<<endl;
		return ;
	}
	itr=cnt.begin();
	if(cnt.size()==2)
	{
		//cout<<"CCC"<<endl<<endl;
		cout<<(itr->fi);
		s.erase(s.find(itr->fi),1);
		sort(s.begin(),s.end(),greater<char>());
		cout<<s<<endl;
	}
	else
	{
		cout<<(itr->fi);
		--(itr->se);
		++itr;
		cout<<(itr->fi);
		--(itr->se);
		--itr;
		while(itr->se)
		{
			--(itr->se);
			cout<<(itr->fi);
		}
		++++itr;
		cout<<(itr->fi);
		--(itr->se);
		for(--itr;itr!=cnt.end();)
		{
			if(itr->se)
			{
				cout<<(itr->fi);
				--(itr->se);
			}
			else
			++itr;
		}
		cout<<endl;
	}
}
int t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	Q();
	return 0;
}
/* things to check
1. int overflow or long long memory need
2. recursion/array/binary search/dp bounds
3. precision
4. forever loop
5. special cases(n=1,bounds)
*/