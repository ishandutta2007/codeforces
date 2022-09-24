/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const ll LLINF=1ll<<60;
const ll MOD=1000000000000000000ll;
const char en='\n';

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

int prime(ll a)
{
	if (a==1) return 0;
	int div=0;
	for (int i=2;i<=a/2;++i)
	{
		if (a%i==0) ++div;
	}
	return div;
}

int n;
ll l,r;
ll hiu[101];

ll root(ll a,ll b)
{
	ll lo=0,hi=min(a,hiu[b]);
	while (lo!=hi)
	{
		ll mid=(lo+hi+1)/2;
		ll br=1;
		int i=0;
		for (i=0;i<b;++i)
		{
			if (a/mid<br)
			{
				break;
			}
			br*=mid;
		}
		if (lo==hi-1)
		{
			if (i==b) return hi;
			else return lo;
		}
		if (i==b) lo=mid;
		else hi=mid;
		//cout<<lo<<' '<<hi<<endl;
	}
	return lo;
}

int main()
{
	ios_base::sync_with_stdio(false);
	hiu[2]=1000000000;
	hiu[3]=1000000;
	hiu[4]=32000;
	hiu[5]=4000;
	for (ll i=2;i<=1000;++i)
	{
		ll b=i*i*i*i*i;
		for (int j=6;j<=61;++j)
		{
			//cout<<MOD/i<<' '<<b<<endl;
			if (MOD/i<b) break;
			b*=i;
			hiu[j]=i;
		}
	}
	//for (int i=2;i<=61;++i) cout<<i<<' '<<hiu[i]<<endl;
	cin.tie(0);
	cin>>n;
	vector<int> plus,minus;
	plus.push_back(2);
	plus.push_back(3);
	plus.push_back(5);
	plus.push_back(7);
	plus.push_back(11);
	plus.push_back(13);
	plus.push_back(17);
	plus.push_back(19);
	plus.push_back(23);
	plus.push_back(29);
	plus.push_back(30);
	plus.push_back(31);
	plus.push_back(37);
	plus.push_back(41);
	plus.push_back(42);
	plus.push_back(43);
	plus.push_back(47);
	plus.push_back(53);
	plus.push_back(59);
	minus.push_back(6);
	minus.push_back(10);
	minus.push_back(14);
	minus.push_back(22);
	minus.push_back(26);
	minus.push_back(34);
	minus.push_back(38);
	minus.push_back(46);
	minus.push_back(58);
	minus.push_back(15);
	minus.push_back(21);
	minus.push_back(33);
	minus.push_back(39);
	minus.push_back(51);
	minus.push_back(57);
	minus.push_back(35);
	minus.push_back(55);
	while (n--)
	{
		cin>>l>>r;
		ll rj=0;
		if (l==1)
		{
			rj=1;
			l=2;
		}
		for (int i: plus) rj+=root(r,i)-root(l-1,i);
		for (int i: minus) rj-=root(r,i)-root(l-1,i);
		cout<<rj<<en;
	}
}