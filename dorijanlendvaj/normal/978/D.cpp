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

int n;
int a[11];
int h[100001],h1[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i],h1[i]=h[i];
	if (n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	h1[0]-=1;
	h1[1]-=0;
	int nu=1;
	for (int i=2;i<n;++i)
	{
		if (h1[i]-h1[i-1]>h1[1]-h1[0]) --h1[i],++nu;
		if (h1[i]-h1[i-1]<h1[1]-h1[0]) ++h1[i],++nu;
		if (h1[i]-h1[i-1]!=h1[1]-h1[0])
		{
			nu=-1;
			break;
		}
	}
	a[0]=((nu==-1)?(MOD):(nu));
	for (int i=0;i<n;++i) h1[i]=h[i];
	h1[0]-=0;
	h1[1]-=0;
	nu=0;
	for (int i=2;i<n;++i)
	{
		if (h1[i]-h1[i-1]>h1[1]-h1[0]) --h1[i],++nu;
		if (h1[i]-h1[i-1]<h1[1]-h1[0]) ++h1[i],++nu;
		if (h1[i]-h1[i-1]!=h1[1]-h1[0])
		{
			nu=-1;
			break;
		}
	}
	a[1]=((nu==-1)?(MOD):(nu));
	for (int i=0;i<n;++i) h1[i]=h[i];
	h1[0]+=1;
	h1[1]-=0;
	nu=1;
	for (int i=2;i<n;++i)
	{
		if (h1[i]-h1[i-1]>h1[1]-h1[0]) --h1[i],++nu;
		if (h1[i]-h1[i-1]<h1[1]-h1[0]) ++h1[i],++nu;
		if (h1[i]-h1[i-1]!=h1[1]-h1[0])
		{
			nu=-1;
			break;
		}
	}
	a[2]=((nu==-1)?(MOD):(nu));
	for (int i=0;i<n;++i) h1[i]=h[i];
	h1[0]-=1;
	h1[1]-=1;
	nu=2;
	for (int i=2;i<n;++i)
	{
		if (h1[i]-h1[i-1]>h1[1]-h1[0]) --h1[i],++nu;
		if (h1[i]-h1[i-1]<h1[1]-h1[0]) ++h1[i],++nu;
		if (h1[i]-h1[i-1]!=h1[1]-h1[0])
		{
			nu=-1;
			break;
		}
	}
	a[3]=((nu==-1)?(MOD):(nu));
	for (int i=0;i<n;++i) h1[i]=h[i];
	h1[0]-=1;
	h1[1]+=1;
	nu=2;
	for (int i=2;i<n;++i)
	{
		if (h1[i]-h1[i-1]>h1[1]-h1[0]) --h1[i],++nu;
		if (h1[i]-h1[i-1]<h1[1]-h1[0]) ++h1[i],++nu;
		if (h1[i]-h1[i-1]!=h1[1]-h1[0])
		{
			nu=-1;
			break;
		}
	}
	a[4]=((nu==-1)?(MOD):(nu));
	for (int i=0;i<n;++i) h1[i]=h[i];
	h1[0]-=0;
	h1[1]-=1;
	nu=1;
	for (int i=2;i<n;++i)
	{
		if (h1[i]-h1[i-1]>h1[1]-h1[0]) --h1[i],++nu;
		if (h1[i]-h1[i-1]<h1[1]-h1[0]) ++h1[i],++nu;
		if (h1[i]-h1[i-1]!=h1[1]-h1[0])
		{
			nu=-1;
			break;
		}
	}
	a[5]=((nu==-1)?(MOD):(nu));
	for (int i=0;i<n;++i) h1[i]=h[i];
	h1[0]-=0;
	h1[1]+=1;
	nu=1;
	for (int i=2;i<n;++i)
	{
		if (h1[i]-h1[i-1]>h1[1]-h1[0]) --h1[i],++nu;
		if (h1[i]-h1[i-1]<h1[1]-h1[0]) ++h1[i],++nu;
		if (h1[i]-h1[i-1]!=h1[1]-h1[0])
		{
			nu=-1;
			break;
		}
	}
	a[6]=((nu==-1)?(MOD):(nu));
	for (int i=0;i<n;++i) h1[i]=h[i];
	h1[0]+=1;
	h1[1]-=1;
	nu=2;
	for (int i=2;i<n;++i)
	{
		if (h1[i]-h1[i-1]>h1[1]-h1[0]) --h1[i],++nu;
		if (h1[i]-h1[i-1]<h1[1]-h1[0]) ++h1[i],++nu;
		if (h1[i]-h1[i-1]!=h1[1]-h1[0])
		{
			nu=-1;
			break;
		}
	}
	a[7]=((nu==-1)?(MOD):(nu));
	for (int i=0;i<n;++i) h1[i]=h[i];
	h1[0]+=1;
	h1[1]+=1;
	nu=2;
	for (int i=2;i<n;++i)
	{
		//cout<<h1[i]<<' '<<h1[i-1]<<' '<<h1[1]<<' '<<h1[0]<<' '<<nu<<endl;
		if (h1[i]-h1[i-1]>h1[1]-h1[0]) --h1[i],++nu;
		if (h1[i]-h1[i-1]<h1[1]-h1[0]) ++h1[i],++nu;
		if ((h1[i]-h1[i-1])!=(h1[1]-h1[0]))
		{
			nu=-1;
			break;
		}
		//cout<<h1[i]<<' '<<h1[i-1]<<' '<<h1[1]<<' '<<h1[0]<<endl;
	}
	/*for (int i=0;i<n;++i) cout<<h1[i]<<' ';
	cout<<endl;*/
	a[8]=((nu==-1)?(MOD):(nu));
	int mi=MOD;
	//cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<a[4]<<' '<<a[5]<<' '<<a[6]<<' '<<a[7]<<' '<<a[8]<<endl;
	for (int i=0;i<9;++i)
	{
		mi=min(a[i],mi);
		//cout<<a[i]<<' ';
	}
	if (mi==MOD) cout<<-1<<endl;
	else cout<<mi<<endl;
}