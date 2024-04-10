#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int nxt[26];
bool prv[26]={0};
bool in[26]={0};

string extract(int i) {
	if(i == -1) return "";
	return extract(nxt[i]).insert(0,1,char(i+'a'));
}

int main() {
	ios::sync_with_stdio(0);
	for(int i = 0; i < 26; ++i) {
		nxt[i] = -1;
	}
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		in[s[0]-'a'] = 1;
		for(int j = 1; j < s.size(); ++j) {
			nxt[s[j-1]-'a'] = s[j]-'a';
			prv[s[j]-'a'] = 1;
			in[s[j]-'a'] = 1;
		}
	}
	for(int i = 0; i < 26; ++i) {
		if(!prv[i] && in[i]) {
			cout << extract(i);
		}
	}
	cout << "\n";
	return 0;
}