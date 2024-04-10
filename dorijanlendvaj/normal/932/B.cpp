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

int q;
int g[1000010],qu[1000010][11];

int prod(int k)
{
	string h=its(k);
	int rj=1;
	for (char o: h) if (o!='0') rj*=o-'0';
	return rj;
}

int dp(int x)
{
	if (g[x]) return g[x];
	return g[x]=dp(prod(x));
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>q;
	for (int i=1;i<10;++i) g[i]=i;
	for (int i=10;i<=1000000;++i) g[i]=dp(i);
	for (int i=1;i<10;++i)
	{
		for (int j=1;j<=1000000;++j) qu[j][i]=qu[j-1][i]+(g[j]==i);
	}
	while (q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		cout<<qu[r][k]-qu[l-1][k]<<endl;
	}
}