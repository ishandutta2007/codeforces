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
const int MOD=1000000007;
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

const int N=300010;
int t;
ll a,b;
vector<ll> v;
unordered_map<ll,bool> bio;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
ofstream fout("file.txt");

void rek(ll i,ll rez,int k)
{
	if (k<0) return;
	//if (bio[rez]) return;
	//bio[rez]=1;
	v.push_back(rez);
	if (i==18) return;
	ll o=rez;
	rek(i+1,o*10ll,k);
	for (int d=1;d<10;++d)
	{
		rek(i+1,o*10ll+d,k-1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	srand((long long)new char);
	for (int i=0;i<10;++i) bases.push_back(raand()+13893829);
	cin>>t;
	//rek(0,0,2);
	for (int i=1;i<10;++i) rek(1,i,2);
	v.push_back((MOD-7)*1ll*(MOD-7));
	sort(v.begin(),v.end());
	while (t--)
	{
		cin>>a>>b;
		--a;
		int c=upper_bound(v.begin(),v.end(),a)-v.begin()-1;
		int d=upper_bound(v.begin(),v.end(),b)-v.begin()-1;
		cout<<d-c<<en;
	}
}