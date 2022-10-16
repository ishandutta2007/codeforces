#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k, same = 0;
	string s;
	cin >> n >> k >> s;
	for(int i=1;i<n;i++) {
		if(s.substr(0, i) == s.substr(n-i, i)) {
			same = i;
		}
	}
	cout << s;
	for(int i=0;i<k-1;i++) {
		cout << s.substr(same, n-same);
	}
}