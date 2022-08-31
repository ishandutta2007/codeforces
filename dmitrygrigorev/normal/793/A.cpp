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
#define int long long
using namespace std;
int n, k, ai;
set<int> g;
vector<int> data;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int minimum = 10000000000;
    for (int i=0;i<n;i++){
        cin >> ai;
        g.insert(ai % k);
        data.push_back(ai);
        minimum = min(ai, minimum);
    }
    if (g.size() > 1){
        cout << -1 << endl;
        return 0;
    }
    int answer = 0;
    for (int i=0;i<n;i++){
        answer += (data[i] - minimum) / k;
    }
    cout << answer << endl;
    return 0;
}