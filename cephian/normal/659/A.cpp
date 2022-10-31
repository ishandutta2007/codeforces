#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
typedef long long ll;

int n,a,b;

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> a >> b;
	--a;
	b = (b+n*200)%n;
	cout << ((a+b)%n)+1 << "\n";
	return 0;
}