#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long double n, a;

    cin >> n >> a;

    long double angle = 2 / n * 180;

    angle *= 0.5;

    long double good = 1e9;

    //cout << angle << endl;

    int c = -1;

    for (long double i = 1; i <= n - 2; i += 1.0) {
        //cout << abs(angle * i - a) << endl;
        if (abs(angle * i - a) <= good) {
            good = abs(angle * i - a);
            c = (int)i;
        }
        if (n != 3 && abs((180 - angle * i) - a) <= good) {
            good = abs((180 - angle * i) - a);
            c = (int)(n - i);
        }
    }

    cout << 2 << " " << 1 << " " <<min((int)n, 2 + c);
    return 0;
}