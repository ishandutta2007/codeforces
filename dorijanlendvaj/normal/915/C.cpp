#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
string a,b;
typedef long long int ll;

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

char dig[21];
map<char,int> a1;
bool found;

void rek(int d,char l,map<char,int> k)
{
	if (found) return;
	if (d==a.size())
	{
		for (int i=0;i<a.size();++i) cout<<dig[i];
		cout<<endl;
		found=1;
		return;
	}
	else
	{
		for (char i=l;i>='0';--i)
		{
			if (!k[i]) continue;
			--k[i];
			dig[d]=i;
			if (i==l && l!=('9'+1))
			{
				if (d<a.size()-1) rek(d+1,b[d+1],k);
				else rek(d+1,0,k);
			}
			else
			{
				rek(d+1,'9'+1,k);
				break;
			}
			++k[i];
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>a>>b;
	for (char k: a) ++a1[k];
	if (b.size()==a.size()) rek(0,b[0],a1);
	else rek(0,'9'+1,a1);
}