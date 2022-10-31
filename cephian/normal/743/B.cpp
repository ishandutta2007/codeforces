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
	int n;
	ll k;
	cin >> n >> k;
	int ans = 1;
	while(k%2==0) {
		++ans;
		k/=2;
	}
	cout << ans << "\n";
	return 0;
}