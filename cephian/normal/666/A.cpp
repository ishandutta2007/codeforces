#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
bool can2[10009]={0};
bool can3[10009]={0};

set<string> ans;

string s;
bool eq(int i, int j, int len) {
	for(int k = 0; k < len; ++k)
		if(s[i+k] != s[j+k]) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> s;
	int n = s.size();
	for(int i = s.size()-1; i>=0; --i) {
		if(i+2==n) can2[i] = 1;
		else if(i == n-1 || i == n-3) {
			can2[i] = 0;
		} else {
			can2[i] = (can2[i+2] && !eq(i,i+2,2)) || can3[i+2];
		}
		if(i+3 == n) {
			can3[i] = 1;
		} else if(n-i < 5) {
			can3[i] = 0;
		} else {
			can3[i] = can2[i+3] || (can3[i+3] && !eq(i,i+3,3));
		}
	}
	for(int i = 0; i < n; ++i) {
		if(can2[i] && i >= 5) {
			// cout << i << ",2" << endl;
			ans.insert(s.substr(i,2));
		}
		if(can3[i] && i >= 5) {
			// cout << i << ",3" << endl;
			ans.insert(s.substr(i,3));
		}
	}
	cout << ans.size() << "\n";
	for(set<string>::iterator it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << "\n";
	}

	return 0;
}