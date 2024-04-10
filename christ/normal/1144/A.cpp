#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 5e4+2, MOD = 1e9+7, LOG = 15;
#define all(x) (x).begin(),(x).end()
int freq[26];
void solve () {
	string s; memset(freq,0,sizeof freq);
	cin >> s;
	vector<int> which;
	for (int i = 0; i < s.length(); i++) {
		if (freq[s[i]-'a']++) return (void) printf ("NO\n");
		which.push_back(s[i]-'a');
	}
	sort(all(which));
	for (int i = 1; i < which.size(); i++) if (which[i]-which[i-1] != 1) return (void) printf ("NO\n");
	printf ("YES\n");
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}