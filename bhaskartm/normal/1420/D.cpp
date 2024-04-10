#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'



const int MOD = 998244353;


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

int fact[300005];
int ifact[300005];

int C(int n, int k)
{
	return mul(fact[n], (mul(ifact[k], ifact[n - k])));
}



main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fact[0]=1;
	for(int i=1; i<300005; i++){
		fact[i]=mul(i, fact[i-1]);
	}
	for(int i=0; i<300005; i++){
		ifact[i]=inv(fact[i]);
	}

	int n, k;
	cin>>n>>k;
	multiset<pair<int, int>>se;
	for(int i=0; i<n; i++){
		int l, r;
		cin>>l>>r;
		se.insert({l, 0});
		se.insert({r, 1});
	}
	int ans=0;
	int cnt=0;
	for(auto u:se){
		if(u.s==0){
			cnt++;
			if(cnt>=k){
				ans=(ans+C(cnt-1, k-1))%MOD;
			}
		}
		else{
			cnt--;
		}
		
	}
	cout<<ans<<endl;
	return 0;
}