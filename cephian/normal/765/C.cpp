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

int a,b,k;
int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> k >> a >> b;
	if((a%k != 0 && b < k) || (b%k != 0 && a < k)) cout << "-1\n";
	else cout << a/k + b/k << "\n";


	return 0;
}