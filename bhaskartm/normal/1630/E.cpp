#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

const int N=1e6+5;
const int MOD=998244353;

int n;
int cn[N];
int arr[N];


int su[N];
int cnt[N];
int fact[N];
int ifact[N];

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
	return (x * y) % MOD;
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
	int t;
	cin>>t;
	fact[0]=1;
	for(int i=1; i<N; i++){
		fact[i]=(i*fact[i-1])%MOD;
	}
	ifact[N-1]=inv(fact[N-1]);
	for(int i=N-2; i>=0; i--){
		ifact[i]=mul(ifact[i+1], i+1);
	}
	while(t--){
		cin>>n;
		for(int i=1; i<=n; i++){
			cn[i]=0;
			cnt[i]=0;
			su[i]=0;
		}
		for(int i=1; i<=n; i++){
			cin>>arr[i];
			cn[arr[i]]++;
		}
		int gc=0;
		vector<int>vec;
		for(int i=1; i<=n; i++){
			gc=__gcd(gc, cn[i]);
			if(cn[i]==0){
				continue;
			}
			vec.pb(cn[i]);
		}
		int sz=vec.size();
		if(sz==1){
			cout<<1<<endl;
			continue;
		}
		for(int rep=n; rep>=1; rep--){
			if((n%rep)!=0 || (gc%rep)!=0){
				continue;
			}
			
			vector<int>vec2;
			int nu=0;
			int den=0;
			for(int i=0; i<vec.size(); i++){
				vec2.pb(vec[i]/rep);
				den+=vec2[i];
				nu+=(vec2[i]*(vec2[i]-1));
			}
			den=(den*(den-1));
			den=den%MOD;
			nu=nu%MOD;
			cnt[rep]=fact[n/rep];
			for(auto u:vec2){
				cnt[rep]=mul(cnt[rep], ifact[u]);
			}
		
			su[rep]=sub(n, mul(mul(n, nu), inv(den)));
			su[rep]=mul(su[rep], cnt[rep]);
			
			for(int j=2; j*rep<=n; j++){
				cnt[rep]=sub(cnt[rep], cnt[j*rep]);
				su[rep]=sub(su[rep], su[j*rep]);
			}
		}
		int fin1=0;
		int fin2=0;
		for(int rep=1; rep<=n; rep++){
			fin1=add(fin1, mul(su[rep], rep));
			fin2=add(fin2, mul(cnt[rep], rep));
		}
		int ans=mul(fin1, inv(fin2));
		cout<<ans<<endl;
	}
	return 0;
}