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

int n;
int x[100001],y[100001];
typedef long double ld;
const ld EPS=4e-10;

pair<ld,ld> ab(int x1,int y1,int x2,int y2)
{
	return {(y1-y2)*1.L/(x1-x2),y1-x1*((y1-y2)*1.L/(x1-x2))};
}

bool eq(ld a,ld b) {
	return abs(a-b)<EPS;
}

void line(int i1,int i2)
{
	ld a=ab(x[i1],y[i1],x[i2],y[i2]).first,b=ab(x[i1],y[i1],x[i2],y[i2]).second;
	vector<int> no;
	if (x[i2]==x[i1]) {for (int i=0;i<n;++i) if (!eq(x[i1],x[i])) no.push_back(i);}
	else {for (int i=0;i<n;++i) if (!eq(x[i]*a+b,y[i])) no.push_back(i);}
	if (no.size()<=2) yes();
	auto e=ab(x[no[0]],y[no[0]],x[no[1]],y[no[1]]);
	ld a1=e.first;
	ld b1=e.second;
	if (x[no[0]]==x[no[1]]) {for (int i: no) if (!eq(x[no[0]],x[i])) return;}
	else {for (int i: no) if (!eq(x[i]*a1+b1,y[i])) return;}
	yes();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	if (n<4) yes();
	for (int i=0;i<n;++i) cin>>x[i]>>y[i];
	line(0,1);
	line(0,2);
	line(1,2);
	no();
}