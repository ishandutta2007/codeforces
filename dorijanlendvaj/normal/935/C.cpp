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

double r,a,b,c,d;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>r>>a>>b>>c>>d;
	c-=a;
	d-=b;
	cout<<fixed<<setprecision(10);
	double k;
	if (c*c+d*d>r*r)
	{
		cout<<a<<' '<<b<<' '<<r<<endl;
		return 0;
	}
	if (d)
	{
		k=c/d;
		double y=r/sqrt(1+k*k),x=y*k;
		if (d>0)
		{
			y=-y;
			x=-x;
		}
		cout<<(x+c)/2+a<<' '<<(y+d)/2+b<<' '<<(sqrt(c*c+d*d)+r)/2<<endl;
	}
	else
	{
		if (c==0) cout<<a+r/2<<' '<<b<<' '<<r/2<<endl;
		else if (c>0)
		{
			cout<<(c-r)/2+a<<' '<<b<<' '<<(c+r)/2<<endl;
		}
		else
		{
			cout<<(c+r)/2+a<<' '<<b<<' '<<(r-c)/2<<endl;
		}
	}
}