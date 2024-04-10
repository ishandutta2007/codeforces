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
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x1, yl, x2, y2;
    cin >> x1 >> yl >> x2 >> y2;
    cout << 2*(abs(x1-x2)+ abs(yl-y2)) + 4 + 2*(x1==x2) + 2*(yl==y2);
    return 0;
}