/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
bool f[N];
int num[26];

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

int32_t main() {
	string s;
	cin >> s;
	int n = s.size();
	int cnt = 1, mx = 0;
	char an;
	for (int i = 0; i < n; i++) {
		f[i] = true;
	}
	f[0] = false;
	for (int i = n / 2 + 1; i <= n; i++) {
		if (is_prime(i)) {
			cnt++;
			f[i - 1] = false;
		}
	}
	cnt = n - cnt;
	for (int i = 0; i < n; i++) {
		num[s[i] - 'a']++;
		if (num[s[i] - 'a'] > mx) {
			mx = num[s[i] - 'a'];
			an = s[i];
		}
	}
	if (mx < cnt) {
		cout << "NO";
		return 0;
	}
	string t;
	for (int i = 0; i < n; i++) {
		t += '?';
	}
	for (int i = 0; i < n; i++) {
		if (f[i]) {
			t[i] = an;
			num[an - 'a']--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (t[i] != '?')
			continue;
		for (int j = 0; j < 26; j++) {
			if (num[j]) {
				t[i] = j + 'a';
				num[j]--;
				break;
			}
		}
	}
	cout << "YES\n" << t;
}