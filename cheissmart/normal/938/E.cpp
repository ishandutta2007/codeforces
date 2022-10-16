#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int long long 
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int MOD = 1e9 + 7, N = 1e6 + 11;
int f[N],fi[N];
void pre()
{
	f[0]=f[1]=fi[0]=fi[1]=1;
	for (int i=2;i<N;i++)f[i]=i*f[i-1]%MOD;
	for (int i=2;i<N;i++)fi[i]=(MOD-MOD/i)*fi[MOD%i]%MOD;
	for (int i=2;i<N;i++)fi[i]=fi[i]*fi[i-1]%MOD;
}
int c(int n,int k) {
	return f[n] * fi[k] % MOD * fi[n-k] % MOD;
}

int a[1000006];

int32_t main()
{
	IO_OP;
	int n,ans=0;
	cin >> n;
	pre();
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for(int i=0,j=0;i<n;i=j) {
		int s = 0;
		for(;a[j]==a[i];j++)
			s += a[j];
		if (j < n)
			ans += s % MOD * f[i] % MOD * f[n-1-i] % MOD * c(n,i) % MOD;
	}
	cout << ans%MOD << endl;
}