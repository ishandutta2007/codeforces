/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
const int MOD=1000000007;
const int MOD2=998244353;
const int BASE=29;
const ll LLINF=1ll<<60;
const char en='\n';

void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}

ll raand()
{
   return rand()*RAND_MAX+rand();
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
	for (auto a: x)
	{
		h1*=BASE;
		h1+=a-'a';
		h1%=MOD;
		h2*=BASE;
		h2+=a-'a';
		h2%=MOD2;
	}
	return {h1,h2};
}

const int N=300010;
const ll MULT=1000000;
const ll SQMU=1000;
int n;
ll c1,c2,y;
ll dup[2010];
int u,p,akor[2010],bkor[2010];
bool bio[2010];
ll a[2010],b[2010];

void ispisi()
{
	cout<<y/MULT<<'.';
	ll e=y%MULT;
	if (e==0)
	{
		cout<<e<<endl;
		exit(0);
	}
	while (e<=100000)
	{
		cout<<0;
		e*=10;
	}
	cout<<y%MULT<<endl;
	exit(0);
}

int dp(int n)
{
	if (n==0) return 0;
	if (bio[n]) return dup[n];
	bio[n]=1;
	ll nist=dp(n-1);
	ll poke=dp(n-1)-c1+a[n];
	ll ultr=dp(n-1)-c2+b[n];
	ll oboj=dp(n-1)-c1-c2+(MULT-(SQMU-a[n]/SQMU)*(SQMU-b[n]/SQMU));
	ll naj=max(max(nist,poke),max(ultr,oboj));
	dup[n]=naj;
	if (nist==naj)
	{
		akor[n]=akor[n-1];
		bkor[n]=bkor[n-1];
	}
	else if (poke==naj)
	{
		akor[n]=akor[n-1]+1;
		bkor[n]=bkor[n-1];
	}
	else if (ultr==naj)
	{
		akor[n]=akor[n-1];
		bkor[n]=bkor[n-1]+1;
	}
	else if (oboj==naj)
	{
		akor[n]=akor[n-1]+1;
		bkor[n]=bkor[n-1]+1;
	}
	return naj;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>p>>u;
	for (int i=1;i<=n;++i)
	{
		int x,z;
		char y;
		cin>>x>>y>>z;
		a[i]=x*MULT+z*(MULT/1000);
	}
	for (int i=1;i<=n;++i)
	{
		int x,z;
		char y;
		cin>>x>>y>>z;
		b[i]=x*MULT+z*(MULT/1000);
	}
	ll lo1=0,hi1=2000ll * MULT;
	while (hi1 - lo1 > 1)
	{
		c1=(lo1+hi1)/2;
		if (c1==1) c1=0;
		ll lo2=0,hi2=2000ll * MULT;
		y=-1;
		//cout<<"odabire se a: "<<lo1<<' '<<hi1<<' '<<c1<<endl;
		while (hi2 - lo2 > 1)
		{
			c2=(lo2+hi2)/2;
			if (c2==1) c2=0;
			//cout<<"odabire se b: "<<lo2<<' '<<hi2<<' '<<c2<<endl;
			//memset(dup,0,sizeof(dup));
			//memset(bkor,0,sizeof(bkor));
			memset(bio,0,sizeof(bio));
			ll x=dp(n);
			//cout<<"a se koristi "<<akor[n]<<" puta, a b "<<bkor[n]<<" puta."<<endl;
			if (bkor[n]==u)
			{
				y=x+u*c2+p*c1;
				//cout<<lo<<' '<<hi<<' '<<c<<endl;
				//for (int i=1;i<=n;++i) for (int j=0;j<=p;++j) cout<<dup[i][j]<<" \n"[j==p];
				//for (int i=1;i<=n;++i) for (int j=0;j<=p;++j) cout<<bkor[i][j]<<" \n"[j==p];
				break;
			}
			else if (bkor[n]>u) lo2=c2;
			else hi2=c2;
		}
		if (akor[n]==p)
		{
			y=dp(n)+u*c2+p*c1;
			ispisi();
		}
		else if (akor[n]>p) lo1=c1;
		else hi1=c1;
	}
	if (c1==1) c1=0;
	if (c2==1) c2=0;
	y=dp(n)+u*c2+p*c1;
	ispisi();
}