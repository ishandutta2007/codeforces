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
int32_t main() {
    ios_base::sync_with_stdio(false);
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    int f = 0, t = 0;
    t1 %= 12;
    t2 %= 12;
    h %= 12;
    if (t1 > t2) swap(t1, t2);
    if (s > 5*t1 && s < 5*t2) f++;
    else t++;
    if (m >= 5*t1 && m < 5*t2) f++;
    else t++;
    if (h >= t1 && h < t2) f++;
    else t++;
    if (max(f, t) == 3) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}