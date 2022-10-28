#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


const int MOD = 1e9+7;
const int N = 200043;

int add(int x, int y)
{
	return (x + y) % MOD;
}

int sub(int x, int y)
{
	return add(x, MOD - y);
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}

int inv(int x)
{
	return binpow(x, MOD - 2);
}

int fact[N];
int ifact[N];
int C(int n, int k)
{
	return mul(fact[n], ( ifact[n - k]));
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fact[0]=1;
	ifact[0]=1;
	for(int i=1; i<=200000; i++){
		fact[i]=mul(fact[i-1], i);
		ifact[i]=inv(fact[i]);
	}
	int n, x, p;
	cin>>n>>x>>p;
	int sm=(x-1);
	int gr=n-x;
	int l=0;
	int r=n;
	int sm2=0;
	int gr2=0;
	while(l<r){
		int mid=(l+r)/2;
		if(mid==p){
			l=mid+1;
			continue;
		}
		if(mid>p){
			gr2++;
			r=mid;
			continue;
		}
		if(mid<p){
			l=mid+1;
			sm2++;
			continue;
		}
	}
	if(sm2>sm || gr2>gr){
		cout<<0;
		return 0;
	}
	
	cout<<mul(mul(C(sm, sm2), C(gr, gr2)), fact[n-1-sm2-gr2])<<endl;
	return 0;
}