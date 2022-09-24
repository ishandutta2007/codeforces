/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
const int MOD=998244353;
const int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
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
int n,k,dp[2][2][N][N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main()
{
	ios_base::sync_with_stdio(false);
	srand((long long)new char);
	for (int i=0;i<10;++i) bases.push_back(raand()+13893829);
	cin>>n>>k;
	dp[0][0][1][1]=1;
	dp[0][1][1][2]=1;
	dp[1][0][1][2]=1;
	dp[1][1][1][1]=1;
	for (int i=1;i<=n;++i)
	{
		for (int j=0;j<=k;++j)
		{
			dp[0][0][i+1][j+1]+=dp[1][1][i][j];
			dp[0][0][i+1][j]+=add(add(dp[0][1][i][j],dp[1][0][i][j]),dp[0][0][i][j]);
			dp[1][1][i+1][j+1]+=dp[0][0][i][j];
			dp[1][1][i+1][j]+=add(add(dp[0][1][i][j],dp[1][0][i][j]),dp[1][1][i][j]);
			dp[0][1][i+1][j]+=dp[0][1][i][j];
			dp[0][1][i+1][j+1]+=add(dp[0][0][i][j],dp[1][1][i][j]);
			dp[0][1][i+1][j+2]+=dp[1][0][i][j];
			dp[1][0][i+1][j]+=dp[1][0][i][j];
			dp[1][0][i+1][j+1]+=add(dp[0][0][i][j],dp[1][1][i][j]);
			dp[1][0][i+1][j+2]+=dp[0][1][i][j];
			dp[0][0][i+1][j]%=MOD;
			dp[0][0][i+1][j+1]%=MOD;
			dp[1][1][i+1][j]%=MOD;
			dp[1][1][i+1][j+1]%=MOD;
			dp[0][1][i+1][j]%=MOD;
			dp[0][1][i+1][j+1]%=MOD;
			dp[0][1][i+1][j+2]%=MOD;
			dp[1][0][i+1][j]%=MOD;
			dp[1][0][i+1][j+1]%=MOD;
			dp[1][0][i+1][j+2]%=MOD;
			//cout<<i<<' '<<j<<' '<<dp[0][0][i][j]<<' '<<dp[0][1][i][j]<<' '<<dp[1][0][i][j]<<' '<<dp[1][1][i][j]<<endl;
		}
	}
	cout<<add(add(dp[0][0][n][k],dp[0][1][n][k]),add(dp[1][0][n][k],dp[1][1][n][k]));
}