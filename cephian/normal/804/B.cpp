#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

ll k = 1;
string s;

ll M = 1e9+7;
ll ans = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	for(char c : s) {
		if(c == 'a') {
			k = (k*2)%M;
		} else {
			ans = (ans+k+M-1)%M;
		}
	}
	cout << ans << "\n";
	return 0;
}