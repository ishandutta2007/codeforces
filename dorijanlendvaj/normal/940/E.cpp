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

int n,c;
ll h[100001];
ll su;
vector<int> b;
ll dp[100001];
multiset<int> k;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>c;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		su+=h[i];
	}
	if (c>n)
	{
		cout<<su<<endl;
		return 0;
	}
	for (int i=0;i<c;++i) k.insert(h[i]);
	b.push_back(*(k.begin()));
	for (int i=1;i<=n-c;++i)
	{
		k.erase(k.find(h[i-1]));
		k.insert(h[i+c-1]);
		b.push_back(*(k.begin()));
		//cout<<i<<endl;
	}
	for (int i=0;i<=n-c;++i)
	{
		dp[i]=b[i];
		if (i) dp[i]=max(dp[i],dp[i-1]);
		if (i>=c)
		{
			dp[i]=max(dp[i],b[i]+dp[i-c]);
		}
	}
	cout<<su-dp[n-c]<<endl;
}