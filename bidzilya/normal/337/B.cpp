#include <cstdio>
#include <cstring>
#include <cmath>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

int gcd(int a, int b) {
    while (a > 0 && b > 0) 
        if (a >= b)
            a %= b;
        else
            b %= a;
    return (a + b);
}

void norm(int& a, int& b) {
    int g = gcd(a, b);
    a /= g;
    b /= g;
}

int a, b, c, d;

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> a >> b >> c >> d;
    norm(a, b);
    norm(c, d);
    if (a == c && b == d) {
        cout << "0/1" << endl;
    } else {
        int p, q;
        if (b * c - a * d > 0) {
            p = b * c - a * d;
            q = b * c;
        } else {
            p = a * d - b * c;
            q = a * d;
        }
        norm(p, q);
        cout << p << "/" << q << endl;
    }
        
    return 0;
}