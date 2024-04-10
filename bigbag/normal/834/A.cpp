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

const string s = "v<^>";

int n;
char a, b;

char get(char a, int n) {
    return s[(s.find(a) + n) % 4];
}

int main() {
    cin >> a >> b >> n;
    if (n % 4 == 2 || n % 4 == 0) {
        cout << "undefined" << endl;
    } else if (get(a, n % 4) == b) {
        cout << "cw" << endl;
    } else {
        cout << "ccw" << endl;
    }
    return 0;
}