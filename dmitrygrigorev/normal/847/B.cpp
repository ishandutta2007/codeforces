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
vector<vector<int> > data;
int checker(int num){
    int sz = data.size();
    int left = -1;
    int right = sz;
    while (right - left > 1){
        int mid = (left + right) / 2;
        if (num > data[mid].back()){
            right = mid;
        }
        else left = mid;
    }
    return right;
}
int32_t main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++){
        cin >> v[i];
        int res = checker(v[i]);
        if (res == data.size()){
            vector<int> help;
            help.push_back(v[i]);
            data.push_back(help);
        }
        else data[res].push_back(v[i]);
    }
    for (int i=0; i < data.size(); i++){
        for (int j=0; j < data[i].size(); j++){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}