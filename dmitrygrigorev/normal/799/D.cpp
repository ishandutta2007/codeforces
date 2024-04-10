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
int a, b, h, w, n, ai;
vector<int> data;
int CONST = 1600000000000000000;
int CONST2 = 1500000000000000;
bool comp(int f, int s){
    if (f > s) return true;
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> h >> w >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    sort(data.begin(), data.end(), comp);
    long long can = 60;
    bool dp[100001];
    int f = 1000000000000, s = 0;
    for (int i=0;i<100001;i++){
        dp[i] = false;
    }
    bool yes = false;
    dp[1] = true;
    int pl = 1;
    for (int i=0;i<=n;i++){
        for (int j=1;j<=100000;j++){
            if (dp[j]){
                int f1 = w * j;
                int s1 = h * pl / j;
                int f2 = w * pl / j;
                int s2 = h * j;
                if (f1 >= a && s1 >= b){
                    cout << i << endl;
                    return 0;
                }
                if (f2 >= a && s2 >= b){
                    cout << i << endl;
                    return 0;
                }
                if (f1 >= b && s1 >= a){
                    cout << i << endl;
                    return 0;
                }
                if (f2 >= b && s2 >= a){
                    cout << i << endl;
                    return 0;
                }
            }
        }
        if (yes){
        if (w * f >= a && h * s >= b){
            cout << i << endl;
            return 0;
        }
        if (w * s >= a && h * f >= b){
            cout << i << endl;
            return 0;
        }
        if (w * f >= b && h * s >= a){
            cout << i << endl;
            return 0;
        }
        if (w * s >= b && h * f >= a){
            cout << i << endl;
            return 0;
        }
        }
        if (i == n) break;
        for (int j=100000;j>=1;j--){
            if (dp[j]){
                int nn = j * data[i];
                if (nn <= 100000) dp[nn] = true;
                else{
                    if (nn < f) {f = nn; yes = true;} 
                }
            }
        }
        if (pl < CONST2){
            if (pl * (data[i] / 100) < CONST2){
                pl *= data[i];
            }
            else{
                pl = CONST2 + 1;
            }
        }
                if (yes){
        if (f * 100000 <= pl) s = 100000;
        else s = pl / f;
        }
    }
    cout << -1 << endl;
    return 0;
}