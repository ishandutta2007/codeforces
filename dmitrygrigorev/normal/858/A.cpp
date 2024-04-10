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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int tw = 0, five = 0, nn = n;
    while (n % 2 == 0){
        tw++;
        n/=2;
    }
    while (n % 5 == 0){
        five++;
        n/=5;
    }
    while (tw < k){
        tw++;
        nn *= 2;
    }
    while (five < k){
        five++;
        nn *= 5;
    }
    cout << nn << endl;
    return 0;
}