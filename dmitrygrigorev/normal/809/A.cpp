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
int n, ai;
vector<int> data;
int CONST = 1000000007;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    sort(data.begin(), data.end());
    if (n == 1){
        cout << 0 << endl;
        return 0;
    }
    int answer = data[n-1] - data[n-2];
    int lans = answer;
    int st = 3;
    int nst = 4;
    for (int i=n-3;i>=0;i--){
        lans *= 2;
        lans += st*(data[i+1] - data[i]);
        st += nst;
        st %= CONST;
        nst *= 2;
        nst %= CONST;
        lans %= CONST;
        answer += lans;
    }
    answer %= CONST;
    cout << answer << endl;
    return 0;
}