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
vector<int> step;
int lb(int rr){
    int l = 0;
    int r = rr+1;
    while (r - l > 1){
        int m = (l + r) / 2;
        int reserve = 0;
        int u1 = 0;
        int u2 = 0;
        int wanted = 0;
        int mm = m;
        bool yes = true;
        while (u2 < n){
            if (data[u2] > step[u1]){
                yes = false;
                break;
            }
            else if (data[u2] < step[u1]) {reserve ++; u2 ++;}
            else{
                if (wanted < mm) wanted ++;
                else reserve ++;
                if (u2 == n-1 || data[u2+1] > step[u1]){
                    u1 ++;
                    if (mm - wanted >= 0){
                        reserve -= min(reserve, mm - wanted);
                        mm -= mm - wanted;
                    }
                    wanted = 0;
                }
                u2 ++;
            }
        }
        if (!yes || reserve > mm) l = m;
        else r = m;
    }
    return r;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    int cc = 1;
    for (int i=0;i<50;i++){
        step.push_back(cc);
        cc *= 2;
    }
    int right = 0;
    for (int i=0;i<n;i++){
        if(data[i] == 1) right ++;
    }
    int left = lb(right);
    if (right < left) cout << -1 << endl;
    else{
        for (int i=left;i<=right;i++){
            cout << i << " ";
        }
    }
    return 0;
}