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
void no() {cout<<"No"<<en; exit(0);}

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

int n,x1,x2,lo,hi;
pair<int,int> h[300001];
bool ex[600001];

void ch(int nu1)
{
	//if (n==150) cout<<lo<<' '<<hi<<' '<<nu1<<endl;
	int nu2=nu1;
	int mi=(x1+nu1-1)/nu1;
	int po=lower_bound(h,h+n,make_pair(mi,0))-h;
	bool po1=1,po2=0;
	if (po==n)
	{
		lo=nu2+1;
		return;
	}
	if (po+nu1>n) nu1=n-po;
	if ((x1+nu1-1)/nu1>h[po].first) po1=0;
	vector<int> a1,a2;
	for (int i=0;i<n;++i) ex[i]=0;
	for (int i=po;i<po+nu1;++i)
	{
		ex[i]=1;
		a1.push_back(i);
	}
	int poi=n-1,nu=0;
	while (po2==0 && poi>=0)
	{
		while (ex[poi]) --poi;
		++nu;
		//cout<<nu<<' '<<poi<<' '<<h[poi].first<<endl;
		if ((x2+nu-1)/nu<=h[poi].first) po2=1;
		a2.push_back(poi);
		--poi;
	}
	//cout<<nu1<<' '<<po1<<' '<<po2<<endl;
	if (po1 && po2)
	{
		cout<<"Yes"<<endl;
		cout<<a1.size()<<' '<<a2.size()<<endl;
		for (int i: a1)
		{
			cout<<h[i].second+1<<' ';
		}
		cout<<endl;
		for (int i: a2) cout<<h[i].second+1<<' ';
		cout<<endl;
		exit(0);
	}
	if (po1) hi=nu2+1;
	else lo=nu2+1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>x1>>x2;
	double ct=clock();
	for (int i=0;i<n;++i)
	{
		cin>>h[i].first;
		h[i].second=i;
	}
	sort(h,h+n);
	lo=1;
	hi=n+1;
	while (lo+1<hi)
	{
		//if (x1==999987842) cout<<lo<<' '<<hi<<endl;
		if (lo+2==hi)
		{
			ch(lo);
			ch(hi-1);
		}
		int mid=(lo+hi)/2;
		ch(mid);
	}/*
	while ((clock()-ct)/CLOCKS_PER_SEC<1.5)
	{
		lo=rand()%(n/2)+1;
		hi=lo+rand()%(n/2);
		while (lo+1<hi)
		{
			//if (x1==999987842) cout<<lo<<' '<<hi<<endl;
			if (lo+2==hi)
			{
				ch(lo);
				ch(hi-1);
			}
			int mid=(lo+hi)/2;
			ch(mid);
		}
	}*/
	cout<<"No"<<endl;
}