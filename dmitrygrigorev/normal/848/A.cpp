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
    int n;
    cin >> n;
    vector<int> symb;
    for (int i=0; i < 10000; i++){
        symb.push_back(i * (i+1) / 2);
    }
    if (n == 0){
        cout << "a" << endl;
        return 0;
    }
    string answer = "";
    int u = 0;
    while (n > 0){
        int maxs = 0;
        while (true){
            if (symb[maxs+1] > n){
                break;
            }
            maxs++;
        }
        for (int i=0; i <= maxs; i++){
            answer += (char) (u + 'a');
        }
        n -= symb[maxs];
        u++;
    }
    cout << answer << endl;
    return 0;
}