/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
const int MOD2=998244353;
const int BASE=29;
typedef long long int ll;
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
	for (int i=0;i<a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll sti(string a)
{
	ll k=0;
	for (int i=0;i<a.size();++i)
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

int gcd(int a,int b)
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

string n;
int sl=MOD;

void try1(char a,char b)
{
	string h=n;
	int pos1=-1,pos2=-1,sol=0;
	for (int i=h.size()-1;i>=0;--i) if (h[i]==b)
	{
		pos1=i;
		break;
	}
	if (pos1==-1) return;
	while (h[h.size()-1]!=b)
	{
		if (pos1==0 && h[pos1+1]=='0')
		{
			int p=2;
			while (h[p]=='0') ++p;
			swap(h[pos1+1],h[pos1+p]);
			sol+=p-1;
		}
		swap(h[pos1],h[pos1+1]);
		++pos1;
		++sol;
	}
	for (int i=h.size()-2;i>=0;--i) if (h[i]==a)
	{
		pos2=i;
		break;
	}
	if (pos2==-1) return;
	while (h[h.size()-2]!=a)
	{
		if (pos2==0 && h[pos2+1]=='0')
		{
			int p=2;
			while (h[p]=='0') ++p;
			swap(h[pos2+1],h[pos2+p]);
			sol+=p-1;
		}
		swap(h[pos2],h[pos2+1]);
		++pos2;
		++sol;
	}
	sl=min(sol,sl);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	try1('0','0');
	try1('2','5');
	try1('5','0');
	try1('7','5');
	if (sl!=MOD) cout<<sl;
	else cout<<-1;
}