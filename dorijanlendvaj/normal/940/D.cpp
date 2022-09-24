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
ll mil=-LLINF,mal=LLINF,mar=LLINF,mir=-LLINF,mi4,ma4;
int h[100001];
string b;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i];
	cin>>b;
	for (int i=4;i<n;++i)
	{
		if (b[i]==b[i-1])
		{
			if (b.substr(i-4,4)=="1111")
			{
				mi4=min(min(h[i-4],h[i-3]),min(h[i-2],h[i-1]));
				mir=max(mir,mi4);
			}
			else if (b.substr(i-4,4)=="0000")
			{
				ma4=max(max(h[i-4],h[i-3]),max(h[i-2],h[i-1]));
				mal=min(mal,ma4);
			}
		}
		else
		{
			if (b.substr(i-4,4)=="1111")
			{
				mi4=min(h[i],min(min(h[i-4],h[i-3]),min(h[i-2],h[i-1])));
				mar=min(mar,mi4-1);
			}
			else
			{
				ma4=max(h[i],max(max(h[i-4],h[i-3]),max(h[i-2],h[i-1])));
				mil=max(mil,ma4+1);
			}
		}
	}
	cout<<(mil<-1000000000?-1000000000:mil)<<' '<<(mar>1000000000?1000000000:mar)<<endl;
}