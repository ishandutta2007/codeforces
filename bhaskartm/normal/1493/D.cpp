#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=2e5+5;
const int MOD=1e9+7;
int n, q;
int arr[N];
int sv[N];
multiset<int>se[N];
map<int, int>ma[N];

vector<pair<int, int>>fun(int x){
	vector<pair<int, int>>ret;
	int nums=x;
	while(nums!=1){
		int val=sv[nums];
		nums=nums/val;
		if(ret.empty() || ret.back().f!=val){
			ret.pb({val,1});
		}
		else{
			auto ti=ret.back().s;
			ret.pop_back();
			ret.pb({val, ti+1});
		}
	}
	return ret;
}



 
 
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


int f2(int ind){
	if(se[ind].size()!=n){
		return 0;
	}
	return (*(se[ind].begin()));
}


 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int x=2; x<N; x++){
		if(sv[x]){
			continue;
		}
		for(int u=x; u<N; u+=x){
			if(sv[u]==0){
				sv[u]=x;
			}
		}
	}

	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	int ans[n+q];
	vector<pair<int, int>>qu;
	
	for(int i=1; i<=n; i++){
		qu.pb({arr[i], i});
	}
	for(int i=0; i<q; i++){
		int ii, x;
		cin>>ii>>x;
		qu.pb({x, ii});
	}
	int gc=1;
	for(int i=0; i<qu.size(); i++){
		vector<pair<int, int>>vec=fun(qu[i].f);
		int ind=qu[i].s;
		for(auto u:vec){
			int ti=ma[ind][u.f];
			int gc1=f2(u.f);
			if(ti!=0){
				se[u.f].erase(se[u.f].find(ti));
			}
			
			ti+=u.s;
			ma[ind][u.f]=ti;
			se[u.f].insert(ti);
			int gc2=f2(u.f);
			gc2-=gc1;
			gc=mul(gc, binpow(u.f, gc2));
		}
		ans[i]=gc;
	}
	for(int i=n; i<n+q; i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}