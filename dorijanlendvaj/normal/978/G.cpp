/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
typedef long long int ll;
const ll LLINF=1ll<<60;
const char en='\n';

void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}

ll raand()
{
   return rand()*RAND_MAX+rand();
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

int n,q;
int h[101];
int t[101];
tuple<int,int,int,int> a[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>q;
	for (int i=0;i<n;++i) h[i]=-1;
	for (int i=0;i<q;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[i]=make_tuple(y,x,z,i);
	}
	sort(a,a+q);
	for (int k=0;k<q;++k)
	{
		int s=get<1>(a[k]),d=get<0>(a[k]),c=get<2>(a[k]),j=get<3>(a[k]);
		t[j]=d-1;
		--s;
		--d;
		int d1=d;
		while (d1<n && h[d1]!=-1) ++d1;
		if (d1==n)
		{
			//cout<<j<<endl;
			cout<<-1<<endl;
			return 0;
		}
		h[d1]=h[d];
		h[d]=q;
		for (int i=0;i<c;++i)
		{
			while (s<n && h[s]!=-1) ++s;
			if (s==n)
			{
				//cout<<i<<' '<<j<<endl;
				cout<<-1<<endl;
				return 0;
			}
			h[s]=j;
			++s;
		}
	}
	for (int i=0;i<n;++i) if (h[i]!=q && h[i]!=-1 && i>t[h[i]]) {
		//for (int i=0;i<n;++i) cout<<h[i]<<' ';
		cout<<-1<<endl;
		return 0;
	}
	for (int i=0;i<n;++i) cout<<h[i]+1<<' ';
	cout<<endl;
}