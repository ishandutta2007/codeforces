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
#include <deque>
#define int long long
using namespace std;
int32_t main(){
    int n, x;
    cin >> n >> x;
    int d[n];
    for (int i=0; i < n; i++){
        cin >> d[i];
    }
    int v = x;
    for (int i=0; i < n; i++){
        if (d[i]<x) v--;
        if (d[i] == x)v++;
    }
    cout << v << endl;
    return 0;
}