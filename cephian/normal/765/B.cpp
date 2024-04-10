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

string s;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> s;
	char nxt = 'a';
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == nxt) {
			++nxt;
		} else if(s[i] > nxt) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}