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

ll n,m;
long double x,y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>m>>n;
	/*if (n>100)
	{
		cout<<m<<endl;
		return 0;
	}*/
	if (m*m*1./n<0.1)
	{
		cout<<m<<endl;
		return 0;
	}
	x=pow(m,-n);
	double clo=clock();
	for (int i=m-1;i>=0 && (clock()-clo)/CLOCKS_PER_SEC<0.8;--i)
	{
		if (y>m)
		{
			cout<<m-m*1./n<<endl;
			return 0;
		}
		double z=0,a=2,b=n-1,c=n*pow(i*1./m,n);
		for (int j=0;j<n && c>0.000000000000000001;++j)
		{
			//cout<<c<<"\n "[(j<n-1)];
			z+=c;
			c/=i;
			c*=b;
			c/=a;
			--b;
			++a;
		}
		y+=z;
	}
	cout<<fixed<<setprecision(12)<<y+1<<endl;
}