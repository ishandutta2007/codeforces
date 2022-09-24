#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef unsigned long long int ull;
int MOD=1000000007;
int MOD2=998244353;
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
	if (w.size()) cout<<w[w.size()-1]<<endl;
}

void M998()
{
	swap(MOD,MOD2);
}

ll raand()
{
	ll a=rund();
	a*=RAND_MAX;
	a+=rund();
    return a;
}

#define rand raand

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

ll min(ll a,int b)
{
	if (a<b) return a;
	return b;
}

ll min(int a,ll b)
{
	if (a<b) return a;
	return b;
}

ll max(ll a,int b)
{
	if (a>b) return a;
	return b;
}

ll max(int a,ll b)
{
	if (a>b) return a;
	return b;
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

inline int mult(ll a,ll b)
{
	return (a*b)%MOD;
}

inline int pot(int n,int k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

int divide(int a,int b)
{
	return mult(a,pot(b,MOD-2));
}

inline int sub(int a,int b)
{
	if (a-b>=0) return a-b;
	return a-b+MOD;
}

inline int add(int a,int b)
{
	if (a+b>=MOD) return a+b-MOD;
	return a+b;
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

ll has(string x)
{
	ll h1=0,h2=0;
	x=to_lower(x);
	for (char a: x)
	{
		h1*=bases[0];
		h1+=a-'a';
		h1%=bases[3];
		h2*=bases[1];
		h2+=a-'a';
		h2%=bases[4];
	}
	return h1*(MOD+13893829)+h2;
}

const int N=300010;
ll n,dp[3][11],dp1[3][5][5][5]; //zadnja: 0=nema anse za 10, 1=prva, 2=druga, 3=treca
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>n;
	ll maa=0;
	for (int z=1;z<10;++z) dp[1][z]=-LLINF;
	for (int i=0;i<n;++i)
	{
		int k;
		cin>>k;
		for (int a=0;a<2;++a) for (int b=0;b<=3;++b) for (int c=0;c<=3;++c) for (int d=0;d<=3;++d) dp1[a][b][c][d]=-MOD;
		dp1[1][0][0][0]=dp1[1][0][0][1]=dp1[1][0][0][2]=dp1[1][0][0][3]=0;
		/*for (int j=0;j<k;++j)
		{
			int a,b;
			cin>>a>>b;
			//stopped at 0:10, resumed at 0:45
			int x=j%2;
			int y=!x;
			for (int l=0;l<=3;++l) for (int m=0;m<=3;++m) for (int o=0;o<=3;++o) dp1[x][l][m][o]=dp1[y][l][m][o];
			for (int l=0;l<3;++l) for (int m=0;m<3;++m) for (int o=0;o<=3;++o) dp1[x][l+1][m+a][o]=max(dp1[x][l+1][m+a][o],dp1[y][l][m][o]+b*(1+(o==l+1)));
		}
		for (int o=0;o<=3;++o,cout<<en) for (int l=0;l<=3;++l,cout<<en) for (int m=0;m<=3;++m) cout<<dp1[(k-1)%2][l][m][o]<<' ';*/
		//stoped at 0:50, resumed at 1:05
		//complete wipe at 1:15
		vector<int> u[3];
		for (int j=0;j<k;++j)
		{
			int a,b;
			cin>>a>>b;
			u[a-1].pb(-b);
		}
		for (int j=0;j<3;++j) sort(u[j].begin(),u[j].end());
		vector<pair<int,ll>> a;
		if (u[0].size()>=1) a.pb({1,-u[0][0]});
		if (u[0].size()>=2) a.pb({1,-u[0][1]});
		if (u[0].size()>=3) a.pb({1,-u[0][2]});
		if (u[1].size()>=1) a.pb({2,-u[1][0]});
		if (u[2].size()>=1) a.pb({3,-u[2][0]});
		int x=i%2;
		int y=!x;
		for (int z=1;z<10;++z) dp[x][z]=-LLINF;
		for (int b=0;b<(1<<a.size());++b)
		{
			if (__builtin_popcount(b)>3) continue;
			ll co=0,ma=0,s=0;
			for (int j=0;j<a.size();++j) if (b&(1<<j)) co+=a[j].x,ma=max(ma,a[j].y),s+=a[j].y;
			if (co>3) continue;
			//cout<<co<<' '<<s<<' '<<ma<<endl;
			for (int p=0;p<10;++p)
			{
				int np=p+__builtin_popcount(b);
				if (np>=10)
				{
					dp[x][np-10]=max(dp[x][np-10],dp[y][p]+s+ma);
				}
				else
				{
					dp[x][np]=max(dp[x][np],dp[y][p]+s);
				}
			}
		}
		for (int j=0;j<10;++j) maa=max(maa,dp[x][j]);
		//cout<<endl;
	}
	cout<<maa;
}