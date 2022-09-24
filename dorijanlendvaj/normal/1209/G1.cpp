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

const int N=400010,M=1<<19,B=600;
//const int N=15,M=1<<4,B=5;
int n,q,h[N],ans,ma[N],mi[N],poss[N],s[N/B+10][N/B+10],s1[N/B+10][N/B+10],pr[N];
vi pos[N];
pii seg[M*4+10]; //min, posMin
int prop[M*4+10];
set<int> ens;

bool isFreqOfBeg(int i,int j,int x)
{
	int a=poss[i]+x-1;
	if (pos[h[i]].size()>a && pos[h[i]][a]<=j) return 1;
	return 0;
}

bool isFreqOfEnd(int i,int j,int x)
{
	int a=poss[j]-x+1;
	if (pos[h[j]].size()>a && pos[h[j]][a]>=i) return 1;
	return 0;
}

void pro(int i)
{
	seg[i].x+=prop[i];
	prop[i*2]+=prop[i];
	prop[i*2+1]+=prop[i];
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

pii get(int l,int r,int lo=0,int hi=M,int i=1)
{
	pro(i);
	if (lo>=l && hi<=r) return seg[i];
	if (lo>=r || hi<=l) return {MOD,-MOD};
	int mid=(lo+hi)/2;
	return min(get(l,r,lo,mid,i*2),get(l,r,mid,hi,i*2+1));
}

int maxAp(int i,int j)
{
	int _i=(i+B-1)/B,_j=j/B;
	int ans=s1[_i][_j];
	//cout<<_i<<' '<<_j<<en;
	for (int a=i;a<min(_i*B,j+1);++a)
	{
		while (isFreqOfBeg(a,j,ans+1)) ++ans;
	}
	for (int a=_j*B;a<=j;++a)
	{
		while (isFreqOfEnd(i,a,ans+1)) ++ans;
	}
	return ans;
}

int maxAp2(int i,int j)
{
	multiset<int> m;
	for (int k=i;k<=j;k+=2) m.insert(h[k]);
	int ma=0;
	for (int k=i;k<=j;k+=2) ma=max(ma,m.count(h[k]));
	return ma;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>n>>q;
	n*=2;
	for (int i=M+n;i<M+M;++i) seg[i].x=MOD,seg[i].y=-MOD;
	for (int i=M-1;i>0;--i) seg[i]=min(seg[i*2],seg[i*2+1]);
	memset(mi,63,sizeof(mi));
	memset(ma,-1,sizeof(ma));
	for (int i=0;i<n;++i) seg[i+M].y=i;
	for (int i=0;i<n;i+=2)
	{
		cin>>h[i];
		poss[i]=pos[h[i]].size();
		pos[h[i]].pb(i);
		mi[h[i]]=min(mi[h[i]],i);
		ma[h[i]]=max(ma[h[i]],i);
	}
	for (int i=0;i<n;i+=B)
	{
		int ma1=0,ma2=0;
		for (int j=i;j<n;++j)
		{
			if (j>i && j%B==0) s[i/B][j/B]=ma1,s1[i/B][j/B]=ma2;
			while (isFreqOfEnd(i,j,ma2+1)) ++ma2,ma1=h[j];
		}
	}
	/*for (int i=0;i<n;i+=2) for (int j=i;j<n;j+=2) if (maxAp(i,j)!=maxAp2(i,j))
	{
		cout<<i/2<<' '<<j/2<<' '<<maxAp(i,j)<<' '<<maxAp2(i,j)<<en;
	}*/
	ens.insert(0);
	for (int i=0;i<=N/2;++i) if (ma[i]!=-1)
	{
		++pr[mi[i]];
		--pr[ma[i]+1];
		upd(mi[i],ma[i]+1,1);
	}
	for (int i=1;i<n;++i) pr[i]+=pr[i-1];
	int la=0;
	while (1)
	{
		auto res=get(la,n-1);
		if (res.x)
		{
			ens.insert(n);
			break;
		}
		else 
		{
			la=res.y+1;
			ens.insert(la);
		}
	}
	//for (int i=0;i<n;++i) if (pr[i]==0) ens.insert(i);
	vi u;
	for (auto a: ens) u.pb(a);
	ans=n/2;
	for (int i=1;i<u.size();++i)
	{
		//cout<<u[i-1]<<' '<<u[i]<<en;
		ans-=maxAp(u[i-1],u[i]);
	}
	cout<<ans;
}