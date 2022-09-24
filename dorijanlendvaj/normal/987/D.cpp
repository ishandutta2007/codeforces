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

int n,m,k,s;
int mit[100010][101];
bool bio[100001][101];
int h[100001];
vector<int> ch[100001];
queue<pair<int,int> > a[101];

void bfs(int col)
{
	while (a[col].size())
	{
		int i=a[col].front().first,p=a[col].front().second;
		a[col].pop();
		if (bio[i][col]) continue;
		bio[i][col]=1;
		mit[i][col]=mit[p][col]+1;;
		for (auto d: ch[i]) if (!bio[d][col]) a[col].push({d,i});
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k>>s;
	for (int i=0;i<k;++i) mit[100001][i]=-1;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		--h[i];
		a[h[i]].push({i,100001});
	}
	for (int i=0;i<m;++i)
	{
		int a,b;
		cin>>a>>b;
		--a;
		--b;
		ch[b].push_back(a);
		ch[a].push_back(b);
	}
	for (int i=0;i<k;++i) bfs(i);
	for (int i=0;i<n;++i)
	{
		sort(mit[i],mit[i]+k);
		int sol=0;
		for (int j=0;j<s;++j) sol+=mit[i][j];
		cout<<sol<<' ';
	}
}