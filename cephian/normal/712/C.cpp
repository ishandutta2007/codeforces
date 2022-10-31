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

int a[3];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int x,y;
	cin >> x >> y;
	a[0] = a[1] = a[2] = y;
	int m = 0;
	while(a[0]+a[1]+a[2] != 3*x) {
		sort(a,a+3);
		++m;
		a[0] = min(x,a[1]+a[2]-1);
	}
	cout << m << "\n";
	return 0;
}