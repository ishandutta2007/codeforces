#include <bits/stdc++.h>
using namespace std;
const int N = 2100;
char s[N], t[N], tem[N];
int n, sz1[26], sz2[26];

void change(int pos) {
	for (int j = 0; j < n - pos; j++) tem[j] = s[n - j - 1];
	for (int j = n - pos; j < n; j++) tem[j] = s[j - (n - pos)];
	for (int j = 0; j < n; j++) s[j] = tem[j];
}

int main() {
	scanf("%d%s%s", &n, s, t);
	for (int i = 0; i < n; i++) {
		sz1[s[i] - 'a']++;
		sz2[t[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) if (sz1[i] != sz2[i]) return puts("-1"), 0;
	vector<char> vec;
	int l = (n - 1) / 2, r = l + 1, sig = 1;
	for (int i = 0; i < n; i++) {
		if (sig) vec.push_back(t[l--]);
		else vec.push_back(t[r++]);
		sig ^= 1;
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		char cur = vec[i];
		int pos = -1;
		for (int j = i; j < n; j++) {
			if (s[j] == cur) {
				pos = j;
				break;
			}
		}
		ans.push_back(n - pos);
		change(pos);
		ans.push_back(pos - i);
		change(n - pos + i);
		ans.push_back(i + 1);
		change(n - i - 1);
	}
	if (strcmp(s, t)) {
		ans.push_back(n);
		change(0);
	}
	cout << ans.size() << endl;
	for (int it : ans) printf("%d ", it);
}