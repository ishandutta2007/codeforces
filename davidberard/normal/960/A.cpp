#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int state = 0;
	int cnt[3] = {0,0,0};
	string s ; cin >> s;
	bool good = true;
	for(char c : s) {
		if(state != c-'a') {
			if(cnt[state] != 0 && state+1 == c-'a') {
				++state;
			} else {
				good = false;
				break;
			}
		}
		cnt[state]++;
	}
	if((cnt[0] != cnt[2] && cnt[1] != cnt[2]) || cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0) {
		good = false;
	}
	cout << (good ? "YES" : "NO") << endl;
	return 0;
}