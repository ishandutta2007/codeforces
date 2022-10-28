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
	ll n,num,i,pizza,girls,taxi;
	cin>>n;
	string s[n],temp;
	vector<pair<ll,ll>> ta,pi,gi;
	vector<ll> ans1,ans2,ans3;
	for(i=0;i<n;i++)
	{
		taxi=pizza=girls=0;
		cin>>num>>s[i];
		for(auto j=0;j<num;j++)
		{
			cin>>temp;
			if(temp[0]==temp[1] && temp[1]==temp[3] && temp[3]==temp[4] && temp[4]==temp[6] && temp[6]==temp[7])
				taxi++;
			else if(temp[0]>temp[1] && temp[1]>temp[3] && temp[3]>temp[4] && temp[4]>temp[6] && temp[6]>temp[7])
				pizza++;
			else
				girls++;
		}
		ta.pb({taxi,i});gi.pb({girls,i});pi.pb({pizza,i});

	}
	sort(all(pi));sort(all(gi));sort(all(ta));

	for(i=n-1;i>=0;i--)
	{
		if(ta[i].F==ta[n-1].F)
			ans1.pb(ta[i].S);
		if(pi[i].F==pi[n-1].F)
			ans2.pb(pi[i].S);
		if(gi[i].F==gi[n-1].F)
			ans3.pb(gi[i].S);
	}
	sort(all(ans1));sort(all(ans2));sort(all(ans3));
	cout<<"If you want to call a taxi, you should call: ";
	for(auto k=0;k<ans1.size()-1;k++)
		cout<<s[ans1[k]]<<", ";
	cout<<s[ans1[ans1.size()-1]]<<".\n";
	cout<<"If you want to order a pizza, you should call: ";
	for(auto k=0;k<ans2.size()-1;k++)
		cout<<s[ans2[k]]<<", ";
	cout<<s[ans2[ans2.size()-1]]<<".\n";
	cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
	for(auto k=0;k<ans3.size()-1;k++)
		cout<<s[ans3[k]]<<", ";
	cout<<s[ans3[ans3.size()-1]]<<".";

	return 0;
}