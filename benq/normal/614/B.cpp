#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

int main() {
	int n, count=0, flag=0;
	string special = "1";
	cin >> n;
	F0R(i,n) {
		string x;
		cin >> x;
		if (x == "0") {
			cout << 0;
			return 0;
		}
		if (flag == 0) {
			int count2 = 0;
			F0R(i,x.length()) {
				if (int(x[i]-'0') > 1) {
					special = x;
					flag = 1;
					break;
				} else if (int(x[i]-'0') == 1) {
					count2++;
					if (count2 > 1) {
						special = x;
						flag = 1;
						break;
					}
				}
			}
			if (flag == 0) {
				count += (x.length()-1);
			}
		} else {
			count += (x.length()-1);
		}
	}
	cout << special;
	F0R(i,count) cout << '0';
	return 0;
}