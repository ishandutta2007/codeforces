#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111;
const long long inf = 1011011011022022022LL;

string a, b, c;

int main() {
    cin >> a >> b >> c;
    for (int i = 0; i < c.length(); ++i) {
        if (('a' <= c[i] && c[i] <= 'z') || ('A' <= c[i] && c[i] <= 'Z')) {
            if ('A' <= c[i] && c[i] <= 'Z') {
                c[i] = c[i] - 'A' + 'a';
                c[i] = b[a.find(c[i])];
                c[i] = c[i] - 'a' + 'A';
            } else {
                c[i] = b[a.find(c[i])];
            }
        }
    }
    cout << c << endl;
    return 0;
}