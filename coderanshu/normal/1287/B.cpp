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
	string str[2000],temp;
	int n,k,i,j,l,ans=0;
	cin>>n>>k;
	multiset<string> s;
	for(i=0;i<n;i++)
	{
		cin>>str[i];
		s.insert(str[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			temp.clear();
			for(l=0;l<k;l++)
			{
				if(str[i][l]==str[j][l])temp+=str[i][l];
				else temp+=(char)(str[i][l]^str[j][l]^'S'^'E'^'T');
			}
			s.erase(s.find(str[i]));
			s.erase(s.find(str[j]));
			if(s.count(temp))
				ans++;
			s.insert(str[i]);s.insert(str[j]);
			temp.clear();
		}
	}
	cout<<ans/3;
	return 0;
}