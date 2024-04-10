#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	for(int i = 0; i < n; ++i) {
		int mr = i;
		for(int j = i; j <= min(n-1,k+i); ++j) {
			if(s[j] > s[mr]) mr = j;
		}
		k -= mr-i;
		int dg = s[mr];
		for(int j = mr; j > i; --j)
			s[j] = s[j-1];
		s[i]=dg;	
	}
	cout << s << "\n";
	return 0;
}