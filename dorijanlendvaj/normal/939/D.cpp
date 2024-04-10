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
string a,b;
set<int> nei[101];
bool bio[101];

void dfs(int i,int dos)
{
	if (bio[i]) return;
	bio[i]=1;
	set<int> nek=nei[i];
	for (int d:nek)
	{
		if (d==dos) continue;
		if (bio[d])
		{
			nei[i].erase(d);
			nei[d].erase(i);
			continue;
		}
		dfs(d,i);
	}
}

set<pair<int,int> > s;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>a>>b;
	for (int i=0;i<n;++i) if (a[i]!=b[i])
	{
		nei[a[i]-'a'].insert(b[i]-'a');
		nei[b[i]-'a'].insert(a[i]-'a');
	}
	for (int i=0;i<26;++i) dfs(i,i);
	for (int i=0;i<26;++i)
	{
		for (int d: nei[i])
		{
			if (s.find({i,d})==s.end() && s.find({d,i})==s.end()) s.insert({i,d});
		}
	}
	cout<<s.size()<<endl;
	for (auto d: s) cout<<char(d.first+'a')<<' '<<char(d.second+'a')<<endl;
}