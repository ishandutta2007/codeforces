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
	cin >> n;
	cout << n/2 << "\n";
	if(n&1) {
		cout << "3 ";
		n-=3;
	}
	while(n) {
		cout << "2 ";
		n-=2;
	}
	cout << "\n";

	return 0;
}