#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll

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

const int N=100;
int n,pos[10][10],ans,A[1<<20],F[1<<20];
bool ed[10][10];
vector<vi> po={{1,2,3},{1,2,4},{1,2,5},{1,2,6},{1,3,4},{1,3,5},{1,3,6},{1,4,5},{1,4,6},{1,5,6},
	{2,3,4},{2,3,5},{2,3,6},{2,4,5},{2,4,6},{2,5,6},{3,4,5},{3,4,6},{3,5,6},{4,5,6}};
	
vector<vi> po2={{1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5},{1,4,5},
	{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
vector<vi> po3={{4,5},{3,5},{3,4},{2,5},{2,4},{2,3},{1,5},{1,4},{1,3},{1,2}};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>n;
	for (int i=0;i<n;++i) for (int j=0;j<n;++j) cin>>pos[i][j],pos[i][j]=divide(pos[i][j],100);
	if (n<=4)
	{
		for (int b=0;b<(1<<(n*n));++b)
		{
			int prob=1;
			memset(ed,0,sizeof(ed));
			for (int i=0;i<n;++i) for (int j=0;j<n;++j)
			{
				if (b&(1<<(i*n+j))) prob=mult(prob,pos[i][j]),ed[i][j]=1;
				else prob=mult(prob,sub(1,pos[i][j]));
			}
			vi per;
			for (int i=0;i<n;++i) per.pb(i);
			bool flag=0;
			do
			{
				bool f=1;
				for (int i=0;i<n;++i) if (!ed[i][per[i]]) f=0;
				if (f) flag=1;
			}
			while (next_permutation(per.begin(),per.end()));
			if (flag) ans=add(ans,prob);
		}
		cout<<ans;
	}
	else if (n<=6)
	{
		for (int b=0;b<(1<<(3*n));++b)
		{
			int prob=1;
			memset(ed,0,sizeof(ed));
			for (int i=0;i<3;++i) for (int j=0;j<n;++j)
			{
				if (b&(1<<(i*n+j))) prob=mult(prob,pos[i][j]),ed[i][j]=1;
				else prob=mult(prob,sub(1,pos[i][j]));
			}
			int mask=0;
			for (int j=0;j<po.size();++j)
			{
				auto a=po[j];
				if (a[2]==6 && n==5) continue;
				bool po=0;
				do
				{
					bool f=1;
					for (int i=0;i<3;++i) if (!ed[i][a[i]-1]) f=0;
					if (f) po=1;
				}
				while (next_permutation(a.begin(),a.end()));
				if (po) mask+=1<<j;
			}
			A[mask]=add(A[mask],prob);
		}
		//cout<<"done1"<<endl;
		for(int i = 0; i<(1<<20); ++i)
			F[i] = A[i];
		for(int i = 0;i < 20; ++i) for(int mask = 0; mask < (1<<20); ++mask){
			if(mask & (1<<i))
				F[mask] = add(F[mask], F[mask^(1<<i)]);
		}
		//cout<<"done2"<<endl;
		for (int b=0;b<(1<<(n/2*n));++b)
		{
			int prob=1;
			memset(ed,0,sizeof(ed));
			for (int i=0;i<n/2;++i) for (int j=0;j<n;++j)
			{
				if (b&(1<<(i*n+j))) prob=mult(prob,pos[i+3][j]),ed[i+3][j]=1;
				else prob=mult(prob,sub(1,pos[i+3][j]));
			}
			int mask=0;
			//cout<<"oof1"<<endl;
			for (int j=0;j<po.size();++j)
			{
				auto a=po[j];
				if (a[2]==6 && n==5) continue;
				vi b;
				for (int i=0;i<n;++i) b.pb(i);
				for (auto x: a) b.erase(find(b.begin(),b.end(),x-1));
				bool po=0;
				do
				{
					bool f=1;
					for (int i=0;i<n/2;++i) if (!ed[i+3][b[i]]) f=0;
					if (f) po=1;
				}
				while (next_permutation(b.begin(),b.end()));
				if (po) mask+=1<<j;
			}
			//cout<<"oof2"<<endl;
			ans=add(ans,mult(prob,sub(1,F[((1<<20)-1)-mask])));
		}
		cout<<ans;
	}
	else
	{
		for (int b=0;b<(1<<(3*n));++b)
		{
			int prob=1;
			memset(ed,0,sizeof(ed));
			for (int i=0;i<3;++i) for (int j=0;j<n;++j)
			{
				if (b&(1<<(i*n+j))) prob=mult(prob,pos[i][j]),ed[i][j]=1;
				else prob=mult(prob,sub(1,pos[i][j]));
			}
			int mask=0;
			for (int j=0;j<po2.size();++j)
			{
				auto a=po2[j];
				bool po=0;
				do
				{
					bool f=1;
					for (int i=0;i<3;++i) if (!ed[i][a[i]-1]) f=0;
					if (f) po=1;
				}
				while (next_permutation(a.begin(),a.end()));
				if (po) mask+=1<<j;
			}
			A[mask]=add(A[mask],prob);
		}
		//cout<<"done1"<<endl;
		for(int i = 0; i<(1<<10); ++i)
			F[i] = A[i];
		for(int i = 0;i < 10; ++i) for(int mask = 0; mask < (1<<10); ++mask){
			if(mask & (1<<i))
				F[mask] = add(F[mask], F[mask^(1<<i)]);
		}
		//cout<<"done2"<<endl;
		for (int b=0;b<(1<<(2*n));++b)
		{
			int prob=1;
			memset(ed,0,sizeof(ed));
			for (int i=0;i<2;++i) for (int j=0;j<n;++j)
			{
				if (b&(1<<(i*n+j))) prob=mult(prob,pos[i+3][j]),ed[i+3][j]=1;
				else prob=mult(prob,sub(1,pos[i+3][j]));
			}
			int mask=0;
			//cout<<"oof1"<<endl;
			for (int j=0;j<po3.size();++j)
			{
				auto a=po3[j];
				bool po=0;
				do
				{
					bool f=1;
					for (int i=0;i<2;++i) if (!ed[i+3][a[i]]) f=0;
					if (f) po=1;
				}
				while (next_permutation(a.begin(),a.end()));
				if (po) mask+=1<<j;
			}
			//cout<<"oof2"<<endl;
			ans=add(ans,mult(prob,sub(1,F[1023-mask])));
			//for (int i=0;i<(1<<10);++i) if (mask&i) ans=add(ans,mult(A[i],prob));
		}
		cout<<ans;
	}
}