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
    int k;
    string s;
    cin >> k >> s;
    vector<char> v;
    int summ = 0;
    for (int i=0; i < s.size(); i++){
        v.push_back(s[i]);
        summ += s[i] - '0';
    }
    sort(v.begin(), v.end());
    int ch = 0;
    int u = 0;
    while (summ < k){
        ch++;
        summ += '9' - v[u];
        u++;
    }
    cout << ch << endl;
    return 0;
}