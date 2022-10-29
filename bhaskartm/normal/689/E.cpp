#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
const int MOD=1000000007;

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

int fact[200005];

int C(int n, int k)
{
	return mul(fact[n], inv(mul(fact[k], fact[n - k])));
}

int main() {
	fact[0]=1;
	for(int i=1; i<200005; i++){
		fact[i]=mul(i, fact[i-1]);
	}
	int n, k;
	cin>>n>>k;
	set<int>s;
	vector<pair<int, int>>qu;
	for(int i=0; i<n; i++){
		int l, r;
		cin>>l>>r;
		s.insert(l);
		s.insert(r+1);
		qu.pb({l, r});
	}
	map<int, int>ma;
	map<int, int>ma2;
	int pointer=0;
	for(auto it=s.begin(); it!=s.end(); it++){
		ma[(*it)]=pointer;
		ma2[pointer]=(*it);
		pointer++;
	}
	int num[pointer+1];
	for(int i=0; i<=pointer; i++){
		num[i]=0;
	}
	for(auto u:qu){
		num[ma[u.f]]++;
		num[ma[u.s+1]]--;
	}
	int val=0;
	int ans=0;
	for(int i=0; i<pointer; i++){
		val+=num[i];
		if(val<k){
			continue;
		}
		ans=add(ans, mul((ma2[i+1]-ma2[i]), C(val, k)));
	}
	cout<<ans;
	return 0;
}