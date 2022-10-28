#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int MOD=998244353;



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




main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	vector<int>v;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		v.pb(x);
	}
	sort(v.begin(), v.end());
	int pre[n+1];
	pre[0]=0;
	for(int i=1; i<=n; i++){
		pre[i]=pre[i-1]+v[i-1];
	}
	while(m--){
		int a, b;
		cin>>a>>b;
		int ind=lower_bound(v.begin(), v.end(), b)-v.begin();
		if(ind==n){
			cout<<0<<endl;
			continue;
		}
		int gr=n-ind;
		int s1=0;
		int s2=0;
		s1=pre[ind];
		s2=pre[n]-pre[ind];
		s1=s1%MOD;
		s2=s2%MOD;
		if(a>gr){
			cout<<0<<endl;
			continue;
		}
		int val1=mul(s1, gr-a+1);
		val1=mul(val1, inv(gr+1));
		int val2=mul(s2, gr-a);
		val2=mul(val2, inv(gr));
		cout<<add(val1, val2)<<endl;
	}
	return 0;
}