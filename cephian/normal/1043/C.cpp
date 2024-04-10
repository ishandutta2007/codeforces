#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 1000;
int flip[N] = {};

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	bool fl = 0;
	int n = s.size();
	for(int i = n-1; i >= 0; --i) {
		if(fl) {
			if(s[i] == 'a') {
				flip[i] = false;
			} else {
				flip[i] = true;
				fl ^= 1;
			}
		} else {
			if(s[i] == 'a') {
				fl = true;
				flip[i] = true;
			} else {
				flip[i] = false;
			}
		}
	}
	for(int i = 0; i < n; ++i)
		cout << flip[i] << " ";
	cout << "\n";
}