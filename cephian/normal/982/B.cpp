#include <bits/stdc++.h>

using namespace std;

int n;
const int N = 1e5+5;

set<int> in;
set<int> ex;
map<int,int> rev;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		rev[a] = i;
		in.insert(a);
	}
	string s;
	cin >> s;
	for(char c : s) {
		if(c == '0') {
			int x = *in.begin();
			in.erase(x);
			ex.insert(x);
			cout << rev[x] << " ";
		} else {
			int x = *ex.rbegin();
			ex.erase(x);
			cout << rev[x] << " ";
		}
	}
	cout << "\n";
}