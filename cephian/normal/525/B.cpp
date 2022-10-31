#include <iostream>

using namespace std;

bool flip[100005]={0};
string s;
int m;

int main() {
	ios::sync_with_stdio(0);
	cin >> s >> m;
	while(m--) {
		int a;
		cin >> a;
		flip[a-1] = !flip[a-1];
	}
	for(int i = 1; i < s.size()/2; ++i)
		flip[i] ^= flip[i-1];
	for(int i = 0; i < s.size()/2; ++i)
		if(flip[i]) swap(s[i], s[s.size()-1-i]);
	cout << s << "\n";
	return 0;
}