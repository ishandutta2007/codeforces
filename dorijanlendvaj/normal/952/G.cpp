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

void yes() {cout<<"Yes"<<en; exit(0);}
void no() {cout<<"No"<<en; exit(0);}

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

string h;
int val=0;
const int si=270;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>h;
	for (int o=0;o<h.size();++o)
	{
		char k=h[o];
		int as=int(k)-val;
		for (int i=0;i<si;++i) cout<<'.';
		cout<<en;
		cout<<"...";
		for (int i=0;i<as;++i) cout<<'X';
		for (int i=3+as;i<si;++i) cout<<'.';
		cout<<en<<"X.X";
		for (int i=0;i<as;++i) cout<<'X';
		cout<<"X.";
		for (int i=as+5;i<si;++i) cout<<'X';
		cout<<en;
		for (int i=0;i<si;++i) cout<<'.';
		cout<<en<<'X';
		for (int i=1;i<si-1;++i) cout<<'.';
		cout<<'X'<<en<<'X';
		for (int i=1;i<si;++i) cout<<'.';
		cout<<en;
		for (int i=0;i<si;++i) cout<<'.';
		cout<<en;
		for (int i=0;i<as;++i) cout<<"X.";
		for (int i=as*2;i<si;++i) cout<<'.';
		cout<<en;
	}
}