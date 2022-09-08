#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a, b;

int gcd(int a, int b) {
    while (a != 0 && b != 0) {
        int k = a;
        a = b;
        b = k % b;
    }
    return a + b;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    if (a > b) swap(a, b);
    b = 7 - b;
    int g = gcd(b, 6);
    if (g == 0) {
        cout << "0/1\n";
    }
    int x = b / g, y = 6 / g;
    cout << x << "/" << y << endl;
    return 0;
}