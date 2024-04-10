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

int n;
int sus[2001][2001];
int h[2001],be1[2001],af2[2001],ma;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		if (h[i]==1) ++be1[i];
		if (i) be1[i]+=be1[i-1];
	}
	for (int i=n-1;i>=0;--i)
	{
		if (h[i]==2) ++af2[i];
		af2[i]+=af2[i+1];
		int ma12=-MOD,n2=0,n1=0;
		for (int j=i;j>=0;--j)
		{
			if (h[j]==2) ++n2;
			else ++n1;
			ma12=max(n1-n2,ma12);
			sus[j][i]=ma12+n2;
			if (!n1) ++sus[j][i];
		}
	}
	for (int i=0;i<n;++i)
	{
		for (int j=i;j<n;++j)
		{
			ma=max(ma,sus[i][j]+(i?be1[i-1]:0)+((j<n-1)?af2[j+1]:0));
		}
	}
	cout<<ma<<endl;
}