#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#define int long long
using namespace std;
int K = 1000000007;
int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
int32_t main(){
    int n, m;
    cin >> n >> m;
    int ans = n + 1 - m;
    for (int i=0; i < m; i++){
        ans *= (2 * n + 2);
        ans %= K;
    }
    int x, y;
    gcd(n+1, K, x, y);
    x *= ans;
    x %= K;
    if (x < 0) x += K;
    cout << x << endl;
    return 0;
}