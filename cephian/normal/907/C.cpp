#include <bits/stdc++.h>
using namespace std;

bool consistent[26];
bool contains[26] = {};

int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	fill(consistent,consistent+26,1);
	bool unique = false;
	int ans = 0;
	while(n--) {
		string a,b;
		cin >> a >> b;
		fill(contains,contains+26,0);
		for(char c : b)
			contains[c-'a'] = true;
		if(a == "!") {
			ans += unique;
			for(int i = 0; i < 26; ++i) {
				if(!contains[i])
					consistent[i] = false;
			}
		} else if(a == ".") {
			for(int i = 0; i < 26; ++i) {
				if(contains[i])
					consistent[i] = false;
			}
		} else {
			if(n != 0) {
				consistent[b[0] - 'a'] = false;
				ans += unique;
			}
		}
		int ctr = 0;
		for(int i = 0; i < 26; ++i) {
			ctr += consistent[i];
		}
		if(ctr == 1) unique = true;
	}
	cout << ans << "\n";
}