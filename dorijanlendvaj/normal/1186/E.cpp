#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")

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

const int N=3010;
int n,m,q,pr[N][N],mat[N][N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int get3(int a)
{
    if (a==0) return 0;
    if (a%2==0) return get3(a/2);
    else return 1-get3(a/2);
}

int get2(int a,int b)
{
    return get3(a)^get3(b);
}

ll get(int x,int y)
{
    ll a=x/(2*n),b=y/(2*m);
    ll ans=a*b*n*m*2;
    ll p=x-a*2*n,q=y-b*2*m;
    ans+=b*m*p;
    ans+=a*n*q;
    if (get2(a,b)==0) ans+=pr[p][q];
    else ans+=p*q-pr[p][q];
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>n>>m>>q;
	for (int i=0;i<n;++i) for (int j=0;j<m;++j)
    {
        char x;
        cin>>x;
        mat[i][j]=x-'0';
    }
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) mat[i][j+m]=!mat[i][j];
	for (int i=0;i<n;++i) for (int j=0;j<2*m;++j) mat[i+n][j]=!mat[i][j];
	//for (int i=0;i<2*n;++i,cout<<en) for (int j=0;j<2*m;++j) cout<<mat[i][j]<<' ';
	for (int i=0;i<2*n;++i) for (int j=0;j<2*m;++j) pr[i+1][j+1]=pr[i][j+1]+pr[i+1][j]-pr[i][j]+mat[i][j];
	//for (int i=1;i<=6*n;++i,cout<<en) for (int j=1;j<=4*m;++j) cout<<get(i,j)+get(i-1,j-1)-get(i,j-1)-get(i-1,j);
	while (q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        --x1;
        --y1;
        cout<<get(x1,y1)+get(x2,y2)-get(x2,y1)-get(x1,y2)<<en;
        //cout<<get(x2,y2)<<en;
    }
}