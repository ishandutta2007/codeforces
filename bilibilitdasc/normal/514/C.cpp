#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
const ll mod3=4985606506409987ll;
const ll mod4=998244353141417ll;
//ios_base::sync_with_stdio(false);???cin
set<pair<ll,ll> > use;
ll pow4[600005];
ll wop4[600005];
pair<ll,ll> hashh(str a)
{
	ll res=0,ret=0;
	rep(i,a.size())
	{
		res=(res*17)+a[i]-'a'+1; 
		res%=mod3;
		ret=(ret*137)+a[i]-'a'+1; 
		ret%=mod4;
	}
	return mp(res,ret);
}
void print(pair<ll,ll> p)
{
	cout<<p.fi<<'?'<<p.se<<endl;
}
void powst()
{
	pow4[0]=1;wop4[0]=1;
	for(int i=1;i<600000;i++)
	{
		pow4[i]=(pow4[i-1]*17)%mod3;
		wop4[i]=(wop4[i-1]*137)%mod4;
	}
}
void add()
{
	str s;
	cin>>s;
	use.insert(hashh(s));
	//print(hashh(s));
}
bool isin(str s)
{
	pair<ll,ll> h=hashh(s);
	rep(i,s.size())
	{
		pair<ll,ll> hh;
		if(s[i]=='a')
		{
			hh=mp((h.fi+pow4[s.size()-1-i])%mod3,(h.se+wop4[s.size()-1-i])%mod4);
		//	cout<<"!";print(hh);
			if(use.count(hh)) return true;
			hh=mp((hh.fi+pow4[s.size()-1-i])%mod3,(hh.se+wop4[s.size()-1-i])%mod4);
		//	cout<<"!";print(hh);
			if(use.count(hh)) return true;
		}
		elif(s[i]=='b')
		{
			hh=mp((h.fi+pow4[s.size()-1-i])%mod3,(h.se+wop4[s.size()-1-i])%mod4);
		//	cout<<"!";print(hh);
			if(use.count(hh)) return true;
			hh=mp((h.fi+mod3-pow4[s.size()-1-i])%mod3,(h.se+mod4-wop4[s.size()-1-i])%mod4);
		//	cout<<"!";print(hh);
			if(use.count(hh)) return true;
		}
		elif(s[i]=='c')
		{
			hh=mp((h.fi+mod3-pow4[s.size()-1-i])%mod3,(h.se+mod4-wop4[s.size()-1-i])%mod4);
		//	cout<<"!";print(hh);
			if(use.count(hh)) return true;
			hh=mp((hh.fi+mod3-pow4[s.size()-1-i])%mod3,(hh.se+mod4-wop4[s.size()-1-i])%mod4);
		//	cout<<"!";print(hh);
			if(use.count(hh)) return true;
		}
	}
	return false;
}
void q()
{
	str s;
	cin>>s;
	if(isin(s))
	{
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
}
int n,m;
int main()
{
	powst();
	cin>>n>>m;
	rep(i,n) add();
	rep(i,m) q();
	return 0;
}