#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	int least = 'z'+1;
	for(char c : s) {
		//cout << (int)c << " vs " << least << endl;
		if(c <= least) {
			cout << "Mike\n";
		} else
			cout << "Ann\n";
		least = min(least, (int)c);
	}
}