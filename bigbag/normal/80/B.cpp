#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

char h1, h2, m1, m2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> h1 >> h2 >> m1 >> m1 >> m2;
    double h = (h1 - '0') * 10 + h2 - '0';
    double m = (m1 - '0') * 10 + m2 - '0';
    if (h >= 12) {
        h -= 12;
    }
    printf("%.10lf %.10lf", (h * 60 + m) / 2, m * 6);
    return 0;
}