#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	cin.sync_with_stdio(false);
	
	ll n, i;
	
	cin >> n;
	
	if(n == 1){
		printf("1\n");
		return 0;
	}
	
	for(i = 2; i * i <= n; i ++){
		if(n % i == 0) break;
	}
	
	if(i * i > n) i = n;
	
	for(; n % i == 0; n /= i);
	
	if(n == 1) cout << i << "\n";
	else cout << 1 << "\n";
	
	return 0;
}