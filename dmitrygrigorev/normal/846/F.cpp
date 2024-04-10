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
const int K = 1000001;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ai;
    cin >> n;
    vector<vector<int> > data;
    for (int i=0; i <= K; i++){
        vector<int> help;
        help.push_back(-1);
        data.push_back(help);
    }
    for (int i=0; i < n; i++){
        cin >> ai;
        data[ai].push_back(i);
    }
    for (int i=0; i < K; i++){
        data[i].push_back(n);
    }
    int counts = (n * (n+1)) / 2;
    int answer = 0;
    for (int i=0; i < K; i++){
        int bad = 0;
        for (int j=0; j < data[i].size() - 1; j++){
            int n1 = data[i][j];
            int n2 = data[i][j+1];
            int diff = n2 - n1 - 1;
            bad += ((diff+1) * diff) / 2;
        }
        answer += (counts - bad);
    }
    int c1 = counts - n;
    for (int i=0; i < K; i++){
        int bad = 0;
        for (int j=0; j < data[i].size() - 1; j++){
            int n1 = data[i][j];
            int n2 = data[i][j+1];
            int diff = n2 - n1 - 1;
            bad += ((diff+1) * diff) / 2 - diff;
        }
        answer += (c1 - bad);
    }
    cout.precision(30);
    long double first = answer;
    long double second = n*n;
    cout << first / second << endl;
    return 0;
}