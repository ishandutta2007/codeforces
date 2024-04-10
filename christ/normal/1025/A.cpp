#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5;

int main () {
	vector<int> freq(128);
	int n; scanf ("%d",&n);
	static char s[100005];
	scanf ("%s",s);
	bool ok = 1;
	for (int i = 1; i < n; i++) ok &= s[i] == s[0];
	if (ok) return !printf ("Yes\n");
	for (int i = 0; i < n; i++) freq[s[i]]++;
	for (int i : freq) if (i > 1) return !printf ("Yes\n");
	printf ("No\n");
	return 0;
}