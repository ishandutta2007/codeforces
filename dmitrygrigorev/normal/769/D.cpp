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
using namespace std;
int CONST = 16384;
vector<long long> vhod;
int n, k, ai;
vector<int> x;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0;i<CONST;i++){
        vhod.push_back(0);
    }
    for (int i=0;i<n;i++){
        cin >> ai;
        vhod[ai] += 1;
    }
    for (int i=0;i<CONST;i++){
        int counter = 1;
        int cc = 0;
        for (int j=0;j<14;j++){
            int an = counter & i;
            if (an != 0){
                cc += 1;
            }
            counter *= 2;
        }
        if (cc == k){
            x.push_back(i);
        }
    }
    long long ans = 0;
    for (int i=0;i<CONST;i++){
        if (vhod[i] == 0) continue;
        for (int j=0;j<x.size();j++){
            int elem = x[j];
            int an = elem ^ i;
            if (an == i) ans += vhod[i] * (vhod[i] - 1);
            else ans += vhod[i] * vhod[an];
        }
    }
    cout << ans / 2 << endl;
    return 0;
}