#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define li long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
vector<char> b;
bool found(char c)
{
	for(int i=0;i<b.size();i++)
	{
		if(c==b[i])
			return true;
	}
	return false;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long  n,k,count,ans,i;

	cin>>n>>k;
	string a;
	cin>>a;
	char m;
	for(i=0;i<k;i++)
	{
		cin>>m;
		b.pb(m);
	}
	count=0;
	ans=0;
	for(i=0;i<n;i++)
	{
		if(!found(a[i]))
		{
			ans+=(count*(count+1))/2;
			count=0;
		}
		else 
		{
			count++;
		}
	}
	ans+=(count*(count+1))/2;
	cout<<ans;
	return 0;
}