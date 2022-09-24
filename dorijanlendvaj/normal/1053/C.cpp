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

const int N=200010,M=1<<18;
int n,q,h[N];
ll seg[M*2+3];
int seg2[M*2+3];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void update(int i,int x)
{
	for (i+=M;i>0;i/=2) seg[i]+=x;
}

ll am(int l,int r,int lo=0,int hi=M,int node=1)
{
	if (l<=lo && r>=hi) return seg[node];
	if (l>=hi || lo>=r) return 0;
	int mid=(lo+hi)/2;
	return am(l,r,lo,mid,node*2)+am(l,r,mid,hi,node*2+1);
}

void update1(int i,int x)
{
	for (i+=M;i>0;i/=2) seg2[i]=add(seg2[i],x);
}

int am1(int l,int r,int lo=0,int hi=M,int node=1)
{
	if (l<=lo && r>=hi) return seg2[node];
	if (l>=hi || lo>=r) return 0;
	int mid=(lo+hi)/2;
	return add(am1(l,r,lo,mid,node*2),am1(l,r,mid,hi,node*2+1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	srand((long long)new char);
	for (int i=0;i<10;++i) bases.push_back(raand()+13893829);
	cin>>n>>q;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
	}
	for (int i=0;i<n;++i) cin>>seg[i+M];
	for (int i=0;i<n;++i) seg2[i+M]=mult(seg[i+M],sub(h[i],i));
	for (int i=M-1;i>=1;--i)
	{
		seg[i]=seg[i*2]+seg[i*2+1];
		seg2[i]=add(seg2[i*2],seg2[i*2+1]);
	}
	while (q--)
	{
		int x,y;
		cin>>x>>y;
		if (x<0)
		{
			x=abs(x)-1;
			update1(x,mult(sub(y,seg[x+M]),sub(h[x],x)));
			update(x,y-seg[x+M]);
		}
		else
		{
			--x;
			ll su=am(x,y)+1;
			su/=2;
			int lo=x,hi=y;
			while (lo<hi-1)
			{
				int mid=(lo+hi)>>1;
				ll su1=am(x,mid);
				//cout<<lo<<' '<<mid<<' '<<su<<' '<<su1<<endl;
				if (su1<su) lo=mid;
				else hi=mid;
			}
			//cout<<lo<<' '<<hi<<' '<<h[lo]<<' '<<am(x,hi)<<' '<<am(hi,y)<<' '<<am1(hi,y)<<' '<<am1(x,hi)<<en;
			ll ri=am(hi,y),li=am(x,hi);
			cout<<add(add(mult(h[lo],sub(li%MOD,ri%MOD)),sub(am1(hi,y)%MOD,am1(x,hi)%MOD)),mult(lo,sub(ri%MOD,li%MOD)))<<en;
		}
	}
}