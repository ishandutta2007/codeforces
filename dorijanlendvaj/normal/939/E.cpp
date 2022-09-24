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

int q;
vector<ll> pr;
double mi;

int bis(ll lo,ll hi,ll k)
{
	if (lo==hi-1)
	{
		return lo;
	}
	ll mid=(lo+hi)/2;
	//cout<<lo<<' '<<hi<<' '<<mid<<' '<<(pr[mid]+k)*1./(mid+2)<<' '<<(pr[mid-1]+k)*1./(mid+1)<<endl;
	if ((pr[mid]+k)*1./(mid+2)<(pr[mid-1]+k)*1./(mid+1)) return bis(mid,hi,k);
	else return bis(lo,mid,k);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>q;
	cout<<fixed<<setprecision(10);
	while (q--)
	{
		ll t,k;
		cin>>t;
		if (t==1)
		{
			cin>>k;
			if (pr.size()) pr.push_back(k+pr[pr.size()-1]);
			else pr.push_back(k);
			if (pr.size()>1)
			{
				int o=bis(0,pr.size()-1,k);
				//cout<<o<<endl;
				mi=max(mi,k-(k+pr[o])*1./(o+2));
			}
		}
		else
		{
			cout<<mi<<endl;
		}
	}
}