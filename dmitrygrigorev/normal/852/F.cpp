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
#include <queue>
#include <ctime>
#define int long long
#define double long double
using namespace std;
int MOD;
vector<int> steps, facts;
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
int C(int n, int k){
    int f = facts[n];
    int s = facts[k] * facts[n-k];
    int x, y;
    gcd(s, MOD, x, y);
    x %= MOD;
    f *= x;
    f %= MOD;
    if (f < 0) f += MOD;
    return steps[f];
}
int32_t main(){
    int n, m, a, q;
    cin >> n >> m >> a >> q;
    steps.push_back(1);
    steps.push_back(a%q);
    while (steps.back() % q != 1){
        steps.push_back((steps.back() * a) % q);
    }
    MOD = steps.size()-1;
    facts.push_back(1);
    for (int i=1; i < 2e6; i++){
        int nv = facts.back() * i;
        facts.push_back(nv % MOD);
    }
    int res = a;
    for (int i=0; i < m; i++){
        res *= res;
        res %= q;
    }
    while (n > m){
        cout << res << " ";
        n--;
    }
    int solve = m-1;
    for (int i=0; i < m; i++){
        int mn = C(m, i);
        int x, y;
        gcd(mn, q, x, y);
        x %= q;
        res *= x;
        res %= q;
        if (res < 0) res += q;
        if (solve < n){
            cout << res << " ";
        }
        solve--;
    }
    return 0;
}