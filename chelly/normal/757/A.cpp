#include<bits/stdc++.h>
using namespace std;
int cnt[999];
int main() {
	string s;
	cin >> s;
	for(int i(0); i < (int)s.size(); i++) {
		cnt[s[i]]++;
	}
	cout << min(cnt['B'], min(cnt['u'] / 2, min(cnt['l'], min(cnt['b'], min(cnt['a'] / 2, min(cnt['s'], cnt['r'])))))) << endl;
}