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
int n,s,a,b,q;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
pair<int,int> h[N];
int pre1[N];

inline int su(int i,int j)
{
	return (i>j?0:pre1[j]-pre1[i-1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	srand((long long)new char);
	for (int i=0;i<10;++i) bases.push_back(raand()+13893829);
	cin>>s>>a>>b>>n;
	for (int i=0;i<n;++i) cin>>h[i+1].first>>h[i+1].second;
	sort(h+1,h+n+1);
	cout<<fixed<<setprecision(10);
	h[0]={-MOD,-MOD};
	h[n+1]={MOD,MOD};
	for (int i=1;i<=n;++i) pre1[i]=pre1[i-1]+h[i].second-h[i].first;
	cin>>q;
	while (q--)
	{
		int x,y;
		cin>>x>>y;
		int lo1=1,hi1=n+1;
		while (lo1<hi1)
		{
			int mid=(lo1+hi1)/2;
			double x1;
			if (x==h[mid].first)
			{
				x1=x;
			}
			else
			{
				double a=(y-0.)/(x-h[mid].first);
				double b=y-a*x;
				x1=(s-b)/a;
			}
			if (x1<a) lo1=mid+1;
			else hi1=mid;
		}
		int lo2=0,hi2=n;
		while (lo2<hi2)
		{
			int mid=(lo2+hi2+1)/2;
			double x1;
			if (x==h[mid].second)
			{
				x1=x;
			}
			else
			{
				double a=(y-0.)/(x-h[mid].second);
				double b=y-a*x;
				x1=(s-b)/a;
			}
			if (x1>b) hi2=mid-1;
			else lo2=mid;
		}
		//cout<<lo1<<' '<<lo2<<endl;
		double rez=su(lo1,lo2)*(1-s*1./y);
		set<int> se;
		se.insert(lo1-1);
		se.insert(lo2+1);
		for (auto mi: se)
		{
			if (mi==0 || mi==n+1) continue;
			//cout<<mi<<endl;
			double x1;
			if (x==h[mi].first)
			{
				x1=x;
			}
			else
			{
				double a=(y-0.)/(x-h[mi].first);
				double b=y-a*x;
				x1=(s-b)/a;
			}
			x1=max(x1,(double)a);
			x1=min(x1,(double)b);
			double x2;
			if (x==h[mi].second)
			{
				x2=x;
			}
			else
			{
				double a=(y-0.)/(x-h[mi].second);
				double b=y-a*x;
				x2=(s-b)/a;
			}
			x2=max(x2,(double)a);
			x2=min(x2,(double)b);
			rez+=x2-x1;
			//cout<<x1<<' '<<x2<<endl;
		}
		cout<<rez<<endl;
	}
}