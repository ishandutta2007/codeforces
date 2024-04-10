#include<bits/stdc++.h>
using namespace std ;
 
#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e9
#define endl "\n"
#define findMax max_element
ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
bool check1(string s)
{
	for(auto i=0;s[i];i++)
	{
		if(s[i]==',')return false;
	}
	return true;
}
ll hashit(string s)
{
	if(s=="S")return 0;
	if(s=="M")return 1;
	if(s=="L")return 2;
	if(s=="XL")return 3;
	if(s=="XXL")return 4;
	if(s=="XXXL")return 5;
}
ll hash2(string s)
{
	string t;
	for(auto i=0;s[i]!=',';i++)
		t+=s[i];
	return hashit(t);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll a[6],k,n,i,z;
	for(i=0;i<6;i++)cin>>a[i];
	bool found=false;
	ll b[5];
	pair<ll,ll> p[5];
	mem0(p);
	mem0(b);
	cin>>n;
	string s[n];
	string setos[6]={"S","M","L","XL","XXL","XXXL"};
	for(auto k=0;k<n;k++)
	{
		cin>>s[k];
		if(!found)
		{
			if(check1(s[k]))
			{
				z=hashit(s[k]);
				if(a[z]==0)
				{
					found=true;
				}
				else
					a[z]--;
			}
			else 
			{
				z=hash2(s[k]);
				b[z]++;
			}
		}
	}
	if(found)cout<<"NO";
	else
	{
		p[0].F=min(a[0],b[0]);
		b[0]-=min(a[0],b[0]);
		
		for(i=0;i<4;i++)
		{
			if(b[i]<=a[i+1])
			{
				a[i+1]-=b[i];
				p[i].S=b[i];
				p[i+1].F=min(b[i+1],a[i+1]);
				b[i+1]-=min(b[i+1],a[i+1]);
			}
			else
			{
				cout<<"NO";return 0;
			}
		}
		if(b[4]<=a[5])
			p[4].S=b[4];
		else
		{
			cout<<"NO";return 0;
		}
		cout<<"YES"<<endl;
		//for(i=0;i<5;i++)cout<<p[i].F<<" "<<p[i].S<<endl;
		for(i=0;i<n;i++)
		{
			if(check1(s[i]))
			{
				cout<<s[i]<<endl;
			}
			else
			{
				k=hash2(s[i]);
				if(p[k].F>0)
				{
					cout<<setos[k]<<endl;p[k].F--;
				}
				else
				{
					cout<<setos[k+1]<<endl;
				}
			}
		}

	}
	return 0;
}