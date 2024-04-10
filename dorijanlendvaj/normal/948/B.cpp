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

int n,mi,mi1;
bool slo[1000010];
priority_queue<int> dl[1000010];
vector<int> v1;

void eras()
{
	for (int i=2;i<=round(sqrt(n));++i)
	{
		for (int j=i*i;j<=n;j+=i)
		{
			slo[j]=1;
			if (!slo[i]) dl[j].push(i);
		}
	}
}

void eras1()
{
	for (int i=2;i<=round(sqrt(n));++i)
	{
		for (int j=i*i;j<=n;j+=i)
		{
			if (!slo[j/i]) dl[j].push(j/i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	eras();
	eras1();
	mi1=n+1;
	for (int j=(n+1)/2;j>=2;--j)
	{
		if (!slo[j] && n%j==0)
		{
			mi1=min(mi1,n-j+1);
		}
	}
	mi=mi1;
	for (int i=mi1;i<=n;++i)
	{
		//cout<<i<<endl;
		if (slo[i])
		{
			mi=min(mi,i-dl[i].top()+1);
		}
	}
	cout<<mi<<endl;
}