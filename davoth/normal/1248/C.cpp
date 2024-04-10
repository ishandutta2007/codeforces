#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int main(){
	int n,m;
	cin >> n >> m;
	long long f[100002];
	f[1] = 2;
	f[2] = 4;
	if(m<n){
		swap(n,m);
	}
	for(int i=3; i<=m+1; i++) f[i]=(f[i-1]+f[i-2])%mod;
	cout << (f[n] + f[m] - 2) % mod;
	return 0;
}