#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
bool is_digit(char c)
{
	return c>=48 && c<=57;
}
int mstoi(string s)
{
	reverse(all(s));
	int ans=0;
	for(int i=0;s[i];++i)
	{
		ans+=(s[i]-'0')*power(10,i);
	}
	return ans;
}
int calc(string l)
{
	int ans=0,i;
	int n=l.length();
	for(i=0;i<n;++i)
	{
		ans+=(l[i]-'A'+1)*power(26,n-i-1);
	}
	return ans;
}
string calc2(string l)
{
	int x=mstoi(l);
	string s;
	while(x>0)
	{
		int t=x%26;
		if(t==0){s+="Z";--x;}
		else s+=(char)('A'-1+t);
		x/=26;
	}
	reverse(all(s));
	return s;
}
void solve(string s)
{
	int n=s.length(),i,j;
	string t,l;
	for(i=n-1;i>=0;--i)
	{
		if(!is_digit(s[i]))break;
		t+=s[i];
	}
	reverse(all(t));
	bool t1=false,t2=false;
	for(j=0;j<=i;++j)
	{
		if(is_digit(s[j]))
		{
			t2=true;
		}
		l+=s[j];
	}
	if(!t2)t1=true;
	if(t1)
	{
		cout<<"R"<<t<<"C"<<calc(l)<<endl;return ;
	}
	cout<<calc2(t);
	for(i=1;i<l.length()-1;++i)cout<<l[i];
		cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s;
	while(n--)
	{
		cin>>s;
		solve(s);
	}
	return 0;
}