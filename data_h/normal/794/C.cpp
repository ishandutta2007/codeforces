#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

string s, t, ans;
int n, ls, lt;

int main() {
	static char buffer[N];
	scanf("%s", buffer);
	s = buffer;
	scanf("%s", buffer);
	t = buffer;
	n = s.size();
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	int who = 0, ls = 0, lt = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 1) s.pop_back();
		else lt++;
	}
	ans.resize(n);
	for (int i = 0; i < n; i++) {
		if (who == 0) {
			if (s[ls] < t.back()) {
				ans[i] = s[ls++];
				who ^= 1;
			} else {
				for (int j = n - 1; j >= i; j -= 2) {
					ans[j] = s.back();
					s.pop_back();
				}
				for (int j = n - 2; j >= i; j -= 2) {
					ans[j] = t[lt++];
				}
				break;
			}
		} else {
			if (t.back() > s[ls]) {
				ans[i] = t.back();
				t.pop_back();
				who ^= 1;
			} else {
				for (int j = n - 1; j >= i; j -= 2) {
					ans[j] = t[lt++];
				}
				for (int j = n - 2; j >= i; j -= 2) {
					ans[j] = s.back();
					s.pop_back();
				}
				break;
			}
		}
	}
	cout << ans << endl;
}