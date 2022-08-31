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
int32_t main(){
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int time1 = t1 * 2 + s * v1;
    int time2 = t2 * 2 + s * v2;
    if (time1 < time2) cout << "First" << endl;
    if (time1 == time2) cout << "Friendship" << endl;
    if (time1 > time2) cout << "Second" << endl;
    return 0;
}