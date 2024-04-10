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

int n;
string h[101][11];
int req[11][11]; //id, star

void diff(int star,int id)
{
	for (int i=0;i<n;++i) for (int j=0;j<n;++j) req[id][star]+=(((i+j+star)%2)!=(h[i][id][j]-'0'));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<4;++i) for (int j=0;j<n;++j) cin>>h[j][i];
	for (int i=0;i<4;++i)
	{
		diff(0,i);
		diff(1,i);
	}
	vector<int> v;
	v.push_back(req[0][0]+req[1][0]+req[2][1]+req[3][1]);
	v.push_back(req[0][0]+req[1][1]+req[2][1]+req[3][0]);
	v.push_back(req[0][1]+req[1][0]+req[2][1]+req[3][0]);
	v.push_back(req[0][1]+req[1][1]+req[2][0]+req[3][0]);
	v.push_back(req[0][1]+req[1][0]+req[2][0]+req[3][1]);
	v.push_back(req[0][0]+req[1][1]+req[2][0]+req[3][1]);
	//cout<<req[0][1]<<' '<<req[1][1]<<' '<<req[2][0]<<' '<<req[3][0]<<en;
	sort(v.begin(),v.end());
	cout<<v[0]<<en;
}