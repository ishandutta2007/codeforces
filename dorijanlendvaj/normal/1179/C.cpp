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

const int N=300010,M=1<<20;
int n,m,q,a[N],b[N],seg[M*2+10],prop[M*2+10];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void pro(int i)
{
    seg[i]+=prop[i];
    if (i<M)
    {
        prop[i*2]+=prop[i];
        prop[i*2+1]+=prop[i];
    }
    prop[i]=0;
}

void upd(int l,int r,int x,int lo=0,int hi=M,int i=1)
{
    pro(i);
    if (lo>=l && hi<=r)
    {
        prop[i]+=x;
        pro(i);
        return;
    }
    if (lo>=r || hi<=l) return;
    int mid=(lo+hi)/2;
    upd(l,r,x,lo,mid,i*2);
    upd(l,r,x,mid,hi,i*2+1);
    seg[i]=min(seg[i*2],seg[i*2+1]);
}

int bs()
{
    int node=1;
    while (node<M)
    {
        pro(node);
        pro(node*2);
        pro(node*2+1);
        if (seg[node*2+1]>=0) node*=2;
        else node=node*2+1;
    }
    return node-M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>n>>m;
	for (int i=0;i<n;++i)
    {
        cin>>a[i];
        upd(1,a[i]+1,-1);
    }
    for (int i=0;i<m;++i)
    {
        cin>>b[i],
        upd(1,b[i]+1,1);
    }
    cin>>q;
    while (q--)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int i,x;
            cin>>i>>x;
            --i;
            upd(1,a[i]+1,1);
            a[i]=x;
            upd(1,a[i]+1,-1);
        }
        else
        {
            int i,x;
            cin>>i>>x;
            --i;
            upd(1,b[i]+1,-1);
            b[i]=x;
            upd(1,b[i]+1,1);
        }
        int z=bs();
        if (z==0) cout<<-1;
        else cout<<z;
        cout<<en;
    }
}