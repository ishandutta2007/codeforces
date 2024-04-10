#include<bits/stdc++.h>
using namespace std;
int n, k;
int solve(string s) {
	int st = 0;
	while(st < n && s[st] == '.') { st++; }
	int an = 1;
	while(1) {
		int nxt = min(n - 1, st + k);
		while(nxt > st && s[nxt] == '.') { nxt--; }
		if(nxt == st) { return an; }
		st = nxt;
		an++;
	}
}
int main() {
	int T;
	cin >>T;
	while(T--) {
		cin >> n >> k;
		string s;
		cin >> s;
		cout << solve(s) <<endl;
	}
}