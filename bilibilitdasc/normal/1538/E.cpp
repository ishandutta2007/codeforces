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
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//long long , 
//ios_base::sync_with_stdio(false);cin
struct str{
	string beg3;
	string ed3;
	long long cnt;
	str(string s="")
	{
		cnt=0;
		if(!s.empty())
		{
			if(s.size()<3)
			{
				beg3=s;
				ed3=s;
			}
			else
			{
				if(s.find("haha")<100u)
				{
					++cnt;
				}
				beg3=s.substr(0,3);
				ed3=s.substr(s.size()-3);
			}
		 } 
	}
	bool lesss()
	{
		return beg3.size()<3;
	 }
	int chk(str b)
	{
		string s=ed3+b.beg3;int ret=0;
		for(int i=0;i<=s.size()-4;++i)
		{
			if(s.substr(i,4)=="haha") ++ret;
		}
		return ret;
	}
	void print()
	{
		cout<<"cnt:"<<cnt<<endl;
		cout<<"prv:"<<beg3<<endl;
		cout<<"suf:"<<ed3<<endl;
	}
};
str operator+(str a,str b)
{
	str c;
	if(!a.lesss()&&!b.lesss())
	{
		c.beg3=a.beg3;
		c.ed3=b.ed3;
		c.cnt=a.cnt+b.cnt+a.chk(b);
		return c;
	}
	else if(a.lesss()&&!b.lesss())
	{
		c.beg3=(a.ed3+b.beg3).substr(0,3);
		c.ed3=b.ed3;
		c.cnt=b.cnt+a.chk(b);
		return c;
	}
	else if(!a.lesss())
	{
		c.beg3=a.beg3;
		c.ed3=(a.ed3+b.beg3).substr(0,3);
		c.cnt=a.cnt+a.chk(b);
		return c;
	}
	else
	{
		string s=a.ed3+b.beg3;
		c.beg3=s.substr(0,min((int)s.size(),3));
		c.ed3=s.substr(s.size()-min((int)s.size(),3));
		if(s=="haha") c.cnt=1;
		else c.cnt=0;
		return c;
	}
}
map<string,str> var;
int t,n;
string a,o,b,c;
void solve()
{
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a>>o;
		if(o==":=")
		{
			cin>>b;
			var[a]=str(b);
			//var[a].print();
		}
		else
		{
			cin>>b>>o>>c;
			var[a]=var[b]+var[c];
			//var[a].print();
		}
	}
	cout<<var[a].cnt<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	solve();
	return 0;
}