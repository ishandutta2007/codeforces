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



int main() {
	ios::sync_with_stdio(0); cin.tie();
	ll s,x;
	cin >> s >> x;

	int choice = 0;
	for(int i = 0; i < 63; ++i)
		if((1LL<<i)&x)
			++choice;
	if(x == s) {
		if(s - (s&-s) == 0) cout << "0\n";
		else cout << (1LL<<choice)-2 << "\n";
		return 0;
	}
	ll sm = x;
	for(int i = 62; i >= 0; --i) {
		if((1LL<<i)&x) continue;
		if(sm <= s - (1LL<<(i+1))) {
			sm += (1LL<<(i+1));
		}
	}
	if(sm != s) {
		cout << "0\n";
		return 0;
	}
	cout << (1LL<<choice) << "\n";
	return 0;
}