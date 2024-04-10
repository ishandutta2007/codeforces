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

int n,preva;
vector<int> pd[2000001];
bool pri[2000001];
set<int> all;
vector<int> has[2000001];
bool poc;

void eras()
{
	for (int i=2;i<=1500000;++i)
	{
		if (pri[i]) continue;
		for (int j=i;j<=1500000;j+=i)
		{
			pri[j]=1;
			pd[j].push_back(i);
			has[i].push_back(j);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	eras();
	cin>>n;
	for (int i=2;i<=1500000;++i) all.insert(i);
	for (int i=0;i<n;++i)
	{
		int a;
		cin>>a;
		if (all.find(a)!=all.end() && !poc)
		{
			cout<<a<<' ';
			for (int di: pd[a])
			{
				if (all.find(di)==all.end()) continue;
				for (int del: has[di])
				{
					//cout<<di<<' '<<del<<endl;
					all.erase(del);
				}
			}
		}
		else
		{
			if (poc) a=*(all.begin());
			else a=*(all.lower_bound(a));
			poc=1;
			cout<<a<<' ';
			for (int di: pd[a])
			{
				if (all.find(di)==all.end()) continue;
				for (int del: has[di]) all.erase(del);
			}
		}
	}
	cout<<en;
}