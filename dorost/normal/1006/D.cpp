/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	string a, b;
	cin >> n >> a >> b;
	int ans = 0;
	for (int i = 0; i < (n + 1) / 2; i++) {
		int cnt[26] = {};
		cnt[a[i] - 'a']++;
		cnt[b[i] - 'a']++;
		if (n % 2 == 0 || i != n / 2){
			cnt[a[n - 1 - i] - 'a']++;
			cnt[b[n - 1 - i] - 'a']++;
			if(a[i] == a[n - 1 - i] && b[i] != b[n - 1 - i] && a[i] != b[i] && a[i] != b[n - 1 - i])
				ans += 2;
		}
		for (int j = 0; j < 26; j++)
			if (cnt[j] % 2)
				ans++;
	}
	cout << ans / 2;
}