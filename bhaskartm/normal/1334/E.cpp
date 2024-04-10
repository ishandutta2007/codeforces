#include <bits/stdc++.h>
using namespace std;
#define int long long int
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

int fact[100005];
int ifact[55];

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fact[0]=1;
	
	for(int i=1; i<=100000; i++){
		fact[i]=mul(fact[i-1], i);
	}
	for(int i=0; i<55; i++){
		ifact[i]=inv(fact[i]);
	}
	int d;
	cin>>d;
	int x=d;
	
	vector<int>v;
	for(int i=2; i*i<=x; i++){
		while(x%i==0){
			if(v.size()==0 || v.back()!=i){
				v.push_back(i);
			}
			x=x/i;
		}
	}
	if(x!=1){
		v.push_back(x);
	}
	
	
	int q;
	cin>>q;
	while(q--){
		int a, b;
		cin>>a>>b;
		int g=__gcd(a, b);
		a=a/g;
		b=b/g;
		vector<int>v1;
		vector<int>v2;
		int t1=0;
		int t2=0;
		for(int i=0; i<v.size(); i++){
			int cnt=0;
			while(a%v[i]==0){
				a=a/v[i];
				cnt++;
			}
			v1.push_back(cnt);
			t1+=cnt;
		}
		for(int i=0; i<v.size(); i++){
			int cnt=0;
			while(b%v[i]==0){
				b=b/v[i];
				cnt++;
			}
			v2.push_back(cnt);
			t2+=cnt;
		}
		int ans=1;
		ans=mul(fact[t1], fact[t2]);
		for(auto u:v1){
			ans=mul(ans, ifact[u]);
		}
		for(auto u:v2){
			ans=mul(ans, ifact[u]);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}