//DUEL
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
#define all(a) begin(a),end(a)

using namespace std;
using namespace __gnu_pbds;

using ll=long long;
using ull=unsigned long long;
using ld=long double;
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
void prVec(vector<T> w,bool fl=false)
{
	cout<<w.size()<<en;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<en;
	if (fl) cout<<flush;
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

template<class T>
vi compress(vector<T>&v)
{
	set<T> s;
	for (auto a: v) s.insert(a);
	vector<T> o(all(s));
	vi nv;
	for (int i=0;i<(int)v.size();++i) nv.pb(lower_bound(all(o),v[i])-o.begin());
	return nv;
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

ll sti(string a,int base=10)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=base;
		k+=a[i]-'0';
	}
	return k;
}

template<class T>
void eras(vector<T>& a,T b)
{
	a.erase(find(a.begin(),a.end(),b));
}

string its(ll k,int base=10)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%base)+'0');
		k/=base;
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

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int N=1000010;
int q,n,an[N],p0[N],p1[N],su[N/10+10][26];
string s0,t;
gp_hash_table<ll,int> re;
map<string,int> oc;
vector<pair<pii,int>> qu[N];
pii pr[N];

pii ad(pii ha,char c)
{
	ha.x=add(mult(ha.x,bases[0]),c);
	ha.y=add(mult(ha.y,bases[1]),c);
	return ha;
}

pii ge(int l,int r)
{
	return {sub(pr[r].x,mult(p0[r-l],pr[l].x)),sub(pr[r].y,mult(p1[r-l],pr[l].y))};
}

void rek(string s,int i,int k,int de,int p2)
{
	if (s.size()==1)
	{
		//cout<<i<<' '<<k<<' '<<de<<endl;
		an[i]=add(an[i],mult(p2,sub(su[k][s[0]-'a'],su[de][s[0]-'a'])));
		return;
	}
	if (de>=k) return;
	bool ok=1;
	for (int i=0;i<(int)s.size();i+=2) if (s[i]!=s[0]) ok=0;
	if (ok && s[0]==t[de])
	{
		string s1;
		for (int i=1;i<(int)s.size();i+=2) s1.pb(s[i]);
		rek(s1,i,k,de+1,p2);
	}
	if ((int)s.size()>1)
	{
		ok=1;
		for (int i=1;i<(int)s.size();i+=2) if (s[i]!=s[1]) ok=0;
		if (ok && s[1]==t[de])
		{
			string s1;
			for (int i=0;i<(int)s.size();i+=2) s1.pb(s[i]);
			rek(s1,i,k,de+1,p2);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>q>>s0>>t;
	int in=1;
	for (int i=0;i<n;++i)
	{
		in=divide(in,2);
		for (int j=0;j<26;++j) su[i+1][j]=su[i][j];
		su[i+1][t[i]-'a']=add(su[i+1][t[i]-'a'],in);
	}
	int ss=s0.size();
	for (int i=0;i<ss;++i) for (int j=1;i+j<=ss;++j) ++oc[s0.substr(i,j)];
	p0[0]=p1[0]=1;
	for (int i=1;i<N;++i) p0[i]=mult(bases[0],p0[i-1]),p1[i]=mult(bases[1],p1[i-1]);
	pii has0={0,0};
	for (int i=0;i<ss;++i) has0=ad(has0,s0[i]);
	for (int i=0;i<q;++i)
	{
		int k;
		string s;
		cin>>k>>s;
		int le=s.size();
		int p2=pot(2,k);
		if (le<=ss)
		{
			an[i]=mult(oc[s],p2);
		}
		for (int i=1;i<=le;++i) pr[i]=ad(pr[i-1],s[i-1]);
		for (int p=0;p<=min(ss,le-1);++p)
		{
			int pot=(le-p-1)/(ss+1);
			int kr=p+pot*(ss+1);
			bool ok=1;
			for (int i=0;i<p;++i) if (s[p-i-1]!=s0[ss-i-1]) ok=0;
			for (int i=kr+1;i<le;++i) if (s[i]!=s0[i-kr-1]) ok=0;
			for (int i=p+1;i<=kr;i+=ss+1) if (ge(i,i+ss)!=has0) ok=0;
			//cout<<p<<' '<<ok<<endl;
			if (ok)
			{
				string re;
				for (int i=p;i<=kr;i+=ss+1) re.pb(s[i]);
				//cout<<re<<endl;
				rek(re,i,k,0,p2);
			}
		}
		cout<<an[i]<<en;
	}
	//for (int i=0;i<q;++i) cout<<an[i]<<en;
}