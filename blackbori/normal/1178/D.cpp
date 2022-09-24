#include <bits/stdc++.h>

using namespace std;

int n, k;

bool isprime(int p)
{
	int i;
	
	for(i=2; i*i<=p; i++){
		if(p % i == 0) return false;
	}
	
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i;
	
	cin >> n;
	
	for(k=0; ; k++){
		if(isprime(n + k)) break;
	}
	
	cout << n + k << "\n";
	
	for(i=1; i<=n; i++){
		cout << i << " " << i % n + 1 << "\n";
	}
	
	for(i=1; i<=k; i++){
		cout << i << " " << i + n / 2 << "\n";
	}
	
	return 0;
}