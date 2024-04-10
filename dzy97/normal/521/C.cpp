#include <bits/stdc++.h>
using namespace std;

#define mo 1000000007
#define N 100010

int fact[N], ni[N], val[N], a[N], n, K, f[N];
char str[N];

int pow(int a, int b, int c){
	int ret = 1;
	while(b){
		if(b & 1) ret = 1LL * ret * a % c;
		b >>= 1;
		a = 1LL * a * a % c;
	}
	return ret;
}

int C(int n, int m){
//	if(!n) return 0;
	if(n < m) return 0;
	return 1LL * fact[n] * ni[m] % mo * ni[n - m] % mo;
}

int main(){
	fact[0] = 1;
	ni[0] = 1;
	scanf("%d%d", &n, &K);
	for(int i = 1;i <= n;i ++) fact[i] = 1LL * fact[i - 1] * i % mo, ni[i] = pow(fact[i], mo - 2, mo);
	scanf("%s", str + 1);
	for(int i = 1;i <= n;i ++) a[i] = str[i] - '0', val[i] = (10LL * val[i - 1] + str[i] - '0') % mo;
	for(int i = 1;i <= n;i ++) f[i] = 1LL * C(n - i - 1, K - 1) * pow(10, i - 1, mo);

//	reverse(f + 1, f + n + 1);
	int ans = 0, sum = 0;
	for(int i = n;i;i --){
		int t = (1LL * pow(10, n - i, mo) * C(i - 1, K) + sum) % mo;
		ans = (1LL * (str[i] - '0') * t + ans) % mo;
		sum = (1LL * pow(10, n - i, mo) * C(i - 2, K - 1) + sum) % mo;
	}
		
/*	for(int i = n;i >= 1;i --){
		cout << f[n-i+1] <<" " << a[i] << endl;
		if(i <= K){
			ans = (1LL * a[i] * sum + ans) % mo;
		}else{
			sum = (sum + f[n-i+1]) % mo;
			ans = (1LL * a[i] * sum + 1LL * pow(10, n - i, mo) * (1LL * a[i] * C(i - 1, K) % mo - 1LL * a[i] * C(i - 1, K - 1) % mo) % mo + ans) % mo;
			cout << "      " << a[i] * sum <<" "<< 1LL * pow(10, n - i, mo) * (1LL * a[i] * C(i - 1, K) % mo - 1LL * a[i] * C(i - 1, K - 1) % mo) % mo << endl;
		}
		
	}*/
	cout << ans << endl;
	return 0;
}