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

int a[100005];
vi odd;
int sm=0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if(a&1) odd.push_back(a);
		else if(a > 0) sm += a;
	}
	sort(odd.rbegin(),odd.rend());
	sm += odd[0];
	for(int i = 1; i+1 < odd.size(); i += 2) {
		if(odd[i]+odd[i+1] > 0)
			sm+=odd[i]+odd[i+1];
		else break;
	}
	cout << sm << "\n";
	return 0;
}