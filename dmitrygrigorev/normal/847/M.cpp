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
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i=0; i < n; i++){
        cin >> data[i];
    }
    set<int> p;
    for (int i=0; i < n-1; i++){
        p.insert(data[i+1] - data[i]);
    }
    if (p.size() > 1){
        cout << data[n-1] << endl;
    }
    else{
        cout << data[n-1] + (*p.begin()) << endl;
    }
    return 0;
}