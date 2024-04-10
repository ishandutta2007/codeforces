/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
#define rand rund

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
const int MOD=1000000007;
const int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
inline int rund() {int x576363482791fuweh=rng();return abs(x576363482791fuweh)%RAND_MAX;}
template<class T>
void prVec(vector<T> w)
{
	cout<<w.size()<<endl;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	cout<<w[w.size()-1]<<endl;
}

ll raand()
{
	ll a=rand();
	a*=RAND_MAX;
	a+=rand();
    return a%(MOD-7);
}

ll raaand()
{
	return raand()*(MOD-7)+raand();
}

string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll sti(string a)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
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

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
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

pair<int,int> has(string x)
{
	ll h1=0,h2=0;
	x=to_lower(x);
	for (char a: x)
	{
		h1*=bases[0];
		h1+=a-'a';
		h1%=MOD;
		h2*=bases[1];
		h2+=a-'a';
		h2%=MOD2;
	}
	return make_pair(h1,h2);
}

const int N=2010;
int n,k;
string h[N];
int dp[N][N];
bool d[N][N],bio[N][N]; // 0=up
queue<pii> q,q1;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	srand((long long)new char);
	for (int i=0;i<10;++i) bases.push_back(raand()+13893829);
	cin>>n>>k;
	k=min(k,2*n-1);
	for (int i=0;i<n;++i) cin>>h[i];
	int ma=0;
	for (int i=0;i<n;++i) for (int j=0;j<n;++j)
	{
		int re=0;
		if (i)
		{
			int pr=dp[i-1][j];
			if (pr>re)
			{
				d[i][j]=0;
				re=pr;
			}
		}
		if (j)
		{
			int pr=dp[i][j-1];
			if (pr>re)
			{
				d[i][j]=1;
				re=pr;
			}
		}
		dp[i][j]=re+(h[i][j]=='a');
		if (dp[i][j]+k>=i+j+1) ma=max(ma,i+j);
	}
	int o=max(0,ma-n+1);
	for (int i=1;i<=ma;++i) if (i<n && ma-i<n && ma-i>=0 && dp[i][ma-i]>dp[o][ma-o]) o=i;
	for (int i=0;i<=ma;++i) if (i<n && ma-i<n && ma-i>=0 && dp[i][ma-i]==dp[o][ma-o])
	{
		if (i<n-1) q1.push({i+1,ma-i});
		if (ma-i<n-1) q1.push({i,ma-i+1});
	}
	if (k>0 || h[0][0]=='a') for (int i=0;i<=ma;++i) cout<<'a';
	else cout<<h[0][0];
	int zu=0;
	while (q1.size())
	{
		q=q1;
		int mi=26;
		while (q1.size()) q1.pop();
		while (q.size())
		{
			pii p=q.front();
			q.pop();
			int i=p.x,j=p.y;
			if (bio[i][j]) continue;
			bio[i][j]=1;
			if (h[i][j]-'a'<mi)
			{
				while (q1.size()) q1.pop();
				mi=h[i][j]-'a';
			}
			if (h[i][j]-'a'==mi)
			{
				if (i<n-1) q1.push({i+1,j});
				if (j<n-1) q1.push({i,j+1});
			}
		}
		/*if (zu) */cout<<char('a'+mi);
		//++zu;
	}
}