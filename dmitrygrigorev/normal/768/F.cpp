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
using namespace std;
vector<long long> fact;
long long f, w, h;
long long CONST = 1000000007;
long long gcd(long long a, long long b, long long &x, long long &y){
    if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	long long x1, y1;
	long long d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
long long obr(long long number){
    long long x, y;
    gcd(number, CONST, x, y);
    return (x + CONST) % CONST;
}
long long cnk(long long first, long long second){
    return (((fact[first] * obr(fact[second])) % CONST) * obr(fact[first - second])) % CONST;
}
int main(){
    std::ios::sync_with_stdio(false);
    long long counter = 1;
    fact.push_back(1);
    for (int i=0;i<1000000;i++){
        fact.push_back(counter);
        counter = (counter * (i + 2)) % CONST;
    }
    cin >> f >> w >> h;
    if (w == 0){
        cout << 1 << endl;
        return 0;
    }
    long long res = 0;
    for (int u=1;u<=f+1;u++){
         long long ss = cnk(f+1, u) % CONST;
         if (w - u * h - u >= 0){
            ss = (ss * cnk(w - u * h - 1, w - u * h - u)) % CONST;
         }
         else ss = 0;
         res += ss;
         res = res % CONST;
    }
    cout << (res * obr(cnk(w + f, f))) % CONST;
    return 0;
}