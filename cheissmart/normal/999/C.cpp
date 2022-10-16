#include <bits/stdc++.h>

using namespace std;

vector<int> a[256];

int main()
{
	int n, k;
	string s;
	cin >> n >> k >> s;
	for(int i=n-1;i>=0;i--) {
		a[s[i]].push_back(i);
	}
	while(k--) {
		for(char c='a';c<='z';c++) {
			if(a[c].size()) {
				s[a[c].back()] = '.';
				a[c].pop_back();
				break;
			}
		}
	}
	for(int i=0;i<n;i++) {
		if(s[i] != '.')
			cout << s[i];
	}
	cout << endl;
}