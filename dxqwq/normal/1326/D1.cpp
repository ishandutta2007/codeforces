#include<bits/stdc++.h>
#define ll long long 
using namespace std;
string str,pp,s,t;
inline bool check(ll l,ll r)
{
	ll p=l,q=r;
	while(str[p]==str[q]&&q>=l)
	{
		p++,q--;
	}
	return q==l-1;
}
int p,q;
inline void solve()
{
	cin>>str,p=0,q=str.length()-1;
	pp=s=t="";
	while(str[p]==str[q]&&q>=0)
	{
		s+=str[p++],t=str[q--]+t;
	}
	if(q==-1)
	{
		cout<<str<<endl;
		return;
	}
	for(register int i=q;i>=p;i--)
	{
		if(check(p,i))
		{
			pp=str.substr(p,i-p+1);
			break;
		}
	}
	for(register int i=p;i<=q;i++)
	{
		if(check(i,q))
		{
			if(q-i+1>=pp.length())
			{
				pp=str.substr(i,q-i+1);
			}
			break;
		}
	}
	cout<<s<<pp<<t<<endl;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}