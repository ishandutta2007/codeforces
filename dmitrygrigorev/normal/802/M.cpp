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
int n, k, ai;
vector<int> data;
int32_t main(){
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    sort(data.begin(), data.end());
    int summ = 0;
    for (int i=0;i<k;i++){
        summ += data[i];
    }
    cout << summ << endl;
    return 0;
}