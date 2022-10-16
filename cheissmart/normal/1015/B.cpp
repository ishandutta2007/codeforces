#include <bits/stdc++.h>

using namespace std;

int m1[256], m2[256];

int main()
{
	int n;
	string s1 = "", s2 = "";
	cin >> n;
	for(int i=0;i<n;i++) {
		char c;
		cin >> c;
		s1 += c;
		m1[c]++;
	}
	for(int i=0;i<n;i++) {
		char c;
		cin >> c;
		s2 += c;
		m2[c]++;
	}
	for(char c='a';c<='z';c++) {
		if(m1[c] != m2[c]) {
			cout << "-1" << endl;
			return 0;
		}
	}
	int ct = 0;
	string ans = "";
	for(int i=n-1;i>=0;i--) {
		int j;
		for(j=0;s1[j]!=s2[i] && j<n; j++);
		for(int k=j;k<i;k++) {
			swap(s1[k], s1[k+1]);
			ans += to_string(k+1) + " ";
			ct++;
		}
	}
	cout << ct << endl << ans << endl;
}