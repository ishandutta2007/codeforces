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
#define int long long
using namespace std;
int n;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n%2 != 0) n++;
    cout << n/2 - 1 << endl;
    return 0;
}