/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
typedef long long int ll;
const ll LLINF=1ll<<60;
const char en='\n';

void yes() {cout<<"Yes"<<en; exit(0);}
void no() {cout<<"No"<<en; exit(0);}

ll sti(string a)
{
	ll k=0;
	for (int i=0;i<a.size();++i)
	{
		k*=10;
		k+=a[i]-'0';
	}
	return k;
}

string its(ll k)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%10)+'0');
		k/=10;
	}
	reverse(a.begin(),a.end());
	return a;
}

int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

template<class T,class K>
pair<T,K> mp(T a,K b)
{
	return make_pair(a,b);
}

ll mult(ll a,ll b)
{
	return (a*b)%MOD;
}

ll pot(ll n,ll k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

ll divide(ll a,ll b)
{
	return mult(a,pot(b,MOD-2));
}

ll sub(ll a,ll b)
{
	return (a-b+MOD)%MOD;
}

ll add(ll a,ll b)
{
	return (a+b)%MOD;
}

bool prime(ll a)
{
	if (a==1) return 0;
	for (int i=2;i<=round(sqrt(a));++i)
	{
		if (a%i==0) return 0;
	}
	return 1;
}

int n,k,ma;
int h[100001],t[100001],ps1[100001],ps[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for (int i=0;i<n;++i) cin>>h[i];
	for (int i=0;i<n;++i)
	{
		cin>>t[i];
	}
	ps1[1]=h[0]*t[0];
	for (int i=1;i<n;++i) ps1[i+1]=ps1[i]+h[i]*t[i];
	ps[1]=h[0];
	for (int i=1;i<n;++i) ps[i+1]=ps[i]+h[i];
	for (int i=0;i<=n-k;++i) ma=max(ma,ps1[n]+((ps[i+k]-ps[i])-(ps1[i+k]-ps1[i])));
	cout<<ma<<endl;
}