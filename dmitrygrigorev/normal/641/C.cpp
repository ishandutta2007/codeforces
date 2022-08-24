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
using namespace std;
int n, q, t;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> q;
    long long a1 = 0;
    long long a2 = 0;
    bool change = false;
    for (int i=0;i<q;i++){
        cin >> t;
        if (t == 2){
            if (!change){
                a1 ++;
                a2 --;
                change = true;
            }
            else{
                a2 ++;
                a1 --;
                change = false;
            }
        }
        else{
            cin >> t;
            a1 += t;
            a2 += t;
            if (t % 2 != 0){
                if (!change) change = true;
                else change = false;
            }
        }
    }
    a1 %= n;
    a2 %= n;
    vector<int> res;
    for (int i=0;i<n;i++){
        res.push_back(0);
    }
    for (int i=0;i<n;i++){
        if (i%2 == 0){
            int ans = (i + a1 + 2 * n) % n;
            res[ans] = i + 1;
        }
        else{
            int ans = (i + a2 + 2 * n) % n;
            res[ans] = i + 1;
        }
    }
    for (int i=0;i<n;i++){
        cout << res[i] << " ";
    }
    return 0;
}