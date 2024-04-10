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
int mi,ma,nmi,nma;
int naj1,naj2,naj3,naj4;
int a;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	mi=MOD;
	ma=-MOD;
	naj4=n+1;
	for (int i=0;i<n;++i)
	{
		cin>>a;
		if (a<mi)
		{
			mi=a;
			nmi=0;
		}
		if (a==mi) ++nmi;
		if (a>ma)
		{
			ma=a;
			nma=0;
		}
		if (a==ma) ++nma;
	}
	if (ma==mi)
	{
		cout<<n<<endl;
		for (int i=0;i<n;++i) cout<<ma<<' ';
		cout<<endl;
		return 0;
	}
	if (ma==mi+1)
	{
		cout<<n<<endl;
		for (int i=0;i<nmi;++i) cout<<mi<<' ';
		for (int i=0;i<nma;++i) cout<<ma<<' ';
		return 0;
	}
	for (int brmi=0;brmi<=n;++brmi)
	{
		int brma=brmi+nma-nmi;
		if (brma<0 || brma+brmi>n) continue;
		int ka1=brmi,ka2=brma,ka3=n-brmi-brma;
		if (min(ka1,nmi)+min(ka2,nma)+min(ka3,n-nmi-nma)<naj4)
		{
			naj4=min(ka1,nmi)+min(ka2,nma)+min(ka3,n-nmi-nma);
			naj1=ka1;
			naj2=ka3;
			naj3=ka2;
		}
	}
	cout<<naj4<<endl;
	for (int i=0;i<naj1;++i) cout<<mi<<' ';
	for (int i=0;i<naj2;++i) cout<<mi+1<<' ';
	for (int i=0;i<naj3;++i) cout<<mi+2<<' ';
	cout<<endl;
}