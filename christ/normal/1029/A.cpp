#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	string ret = s;
	while (--k) {
		int oi = ret.length();
		for (int i = ret.length()-1; i > ret.length()-s.length(); i--) {
			int toend = ret.length()-i;
			if (ret.substr(i,toend) == s.substr(0,toend)) oi = i;
		}
		ret = ret.substr(0,oi);
		ret += s;
	}
	cout << ret << endl;
    return 0;
}