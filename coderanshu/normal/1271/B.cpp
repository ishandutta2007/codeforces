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
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,i,w=0,b=0,count=0;
	vector<int> v;
	v.clear();
	string s;
	char k;
	cin>>n;
	cin>>s;
	for(i=0;i<n;i++)
	{
		if(s[i]=='W')w++;
		else b++;
	}
	if(w%2==0 || b%2==0)
	{
		if(w==0 || b==0)
		{
			cout<<0;return 0;
		}
		if(w%2==0)k='W';
		else k='B';
		for(i=0;i<n;i++)
		{
			if(s[i]==k)
				v.pb(i);
		}
		for(i=1;i<v.size();i+=2)
		{
			count+=v[i]-v[i-1];
		}
		cout<<count<<"\n";
		for(i=1;i<v.size();i+=2)
		{
			for(auto j=0;j<v[i]-v[i-1];j++)
				cout<<v[i-1]+1+j<<" ";
		}

	}
	else
		cout<<-1;
	return 0;
}