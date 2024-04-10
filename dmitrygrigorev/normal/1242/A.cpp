#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n==1){
		cout << 1;
		exit(0);
	}

	int divisors = 0;
	int cur = -1;
	int T=n;
	for (int i=2; i*i <= T; ++i){
		if (n%i==0){
			divisors++;
			while (n%i==0) n /= i;
			cur = i;
		}
	}

	if (n!=1){
		divisors++;
	}

	if (T==n){
		cout << T;
		exit(0);
	}

	if (divisors > 1){
		cout << 1;
		exit(0);
	}
	cout << cur;


}