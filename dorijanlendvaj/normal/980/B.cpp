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

void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}

ll raand()
{
   return rand()*RAND_MAX+rand();
}

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

int n,k;
string h[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	cout<<"YES"<<endl;
	for (int i=0;i<4;++i) for (int j=0;j<n;++j) h[i].push_back('.');
	if (k%2==0)
	{
		for (int i=0;i<k/2;++i)
		{
			h[1][i+1]='#';
			h[2][i+1]='#';
		}
	}
	else
	{
		h[1][n/2]='#';
		--k;
		int p1=n/2-1,p2=n/2+1;
		for (;k && p1>0 && p2<n-1;--p1,++p2)
		{
			h[1][p1]='#';
			h[1][p2]='#';
			--k;
			--k;
		}
		p1=1;
		p2=n-2;
		while (k)
		{
			h[2][p1]='#';
			h[2][p2]='#';
			--k;
			--k;
			++p1;
			--p2;
		}
	}
	for (int i=0;i<4;++i) cout<<h[i]<<endl;
}