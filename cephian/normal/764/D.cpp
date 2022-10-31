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

int m(int a) {
	a%=2;
	return (a>=0)?a%2:a+2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << "YES\n";
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a,b,c;
		cin >> a >> b >> c >> c;
		cout << 1+m(a)+2*m(b) << "\n";
	}
	return 0;
}