#include <algorithm>
#include <iostream>
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

bool isp(int n) {
	int s = sqrt(n);
	for(int i = 2; i <= s; ++i)
		if(n%i == 0) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie();
	int n;
	cin >> n;
	if(isp(n)) cout << "1\n";
	else if(n%2 == 0) cout << "2\n";
	else if(isp(n-2))cout << "2\n";
	else cout << "3\n";

	return 0;
}