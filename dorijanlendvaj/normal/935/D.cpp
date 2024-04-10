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

int n,m;
ll a[100001],b[100001];
ll p[100001],q[100010];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m;
	q[n]=1;
	for (int i=0;i<n;++i) cin>>a[i];
	for (int i=0;i<n;++i) cin>>b[i];
	for (int i=n-1;i>=0;--i)
	{
		if (a[i]==0)
		{
			if (b[i]==0)
			{
				q[i]=mult(q[i+1],mult(m,m));
				p[i]=add(mult(divide(mult(m,m-1),2),q[i+1]),mult(p[i+1],m));
			}
			else
			{
				q[i]=mult(q[i+1],m);
				p[i]=add(mult(m-b[i],q[i+1]),p[i+1]);
			}
		}
		else if (b[i]==0)
		{
			q[i]=mult(q[i+1],m);
			p[i]=add(mult(a[i]-1,q[i+1]),p[i+1]);
		}
		else
		{
			if (a[i]>b[i])
			{
				p[i]=1;
				q[i]=1;
			}
			else if (b[i]>a[i])
			{
				p[i]=0;
				q[i]=1;
			}
			else
			{
				p[i]=p[i+1];
				q[i]=q[i+1];
			}
		}
	}
	cout<<divide(p[0],q[0])<<endl;
}