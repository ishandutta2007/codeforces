/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;

const int K = 3;
int cnt[K];
string s;
int n;

int main() {
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] < 'a' || s[i] > 'c') {
			cout << "NO" << endl;
			return 0;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] > s[i + 1]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		cnt[s[i] - 'a']++;
	}
	if (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0) {
		cout << "NO" << endl;
		return 0;
	}
	if (cnt[2] != cnt[0] && cnt[2] != cnt[1]) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
}