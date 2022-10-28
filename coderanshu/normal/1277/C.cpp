#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(i=a;i<b;i++)

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e==1)
		return b;
	if(e%2==0)
		return power(b*b%m,e/2,m);
	else
		return b*power(b*b%m,(e-1)/2,m)%m;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s,temp,one("one"),two("two"),th("twone");
	ll t,n,i;
		cin>>t;
		while(t--)
		{
			s.clear();
			cin>>s;
			n=s.length();
			vector<ll > v;
			for(i=0;i<n;i++)
			{
				temp.clear();
				if(i+4<n)
				{
				temp=s.substr(i,5);
				if(temp.compare(th)==0)
				{
					v.pb(i+3);
					i+=4;
				}
				}
				temp.clear();
				if(i+2<n)
				{
				temp=s.substr(i,3);
				if(temp.compare(one)==0 || temp.compare(two)==0)
				{
					v.pb(i+2);
					i+=2;
				}
				}
			}
			cout<<v.size()<<"\n";
			for(auto j:v)
			cout<<j<<" ";
			cout<<"\n"; 
			v.clear();
		}	
	return 0;
}