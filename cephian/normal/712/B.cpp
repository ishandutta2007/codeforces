#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <random>
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

int lr,ud;
string s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	int ans = -1;
	if(s.size()&1){}
	else {
		ans =0;
		for(char c : s) {
			if(c=='L') ++lr;
			if(c=='R') --lr;
			if(c=='U') ++ud;
			if(c=='D') --ud;
		}
		lr = abs(lr);
		ud = abs(ud);
		while(lr > 1) {
			lr -= 2;
			++ans;
		}
		while(ud > 1) {
			ud -= 2;
			++ans;
		}
		ans += ud;
	}
	cout << ans << "\n";


	return 0;
}