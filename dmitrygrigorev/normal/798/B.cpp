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
int n;
string ai;
vector<string> data;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    int ans = 100000000;
    for (int i=0;i<data[0].size();i++){
        int moves = i;
        bool yes = true;
        for (int j=1;j<data.size();j++){
            string s1 = data[j];
            int mm = 100000;
            for (int k=0;k<s1.size();k++){
                bool go = true;
                for (int m=k;m<s1.size()+k;m++){
                    if (s1[m%s1.size()] != data[0][(i + m - k) % data[0].size()]){
                        go = false;
                    }
                }
                if (go){
                    mm = min(mm, k);
                }
            }
            if (mm == 100000){
                yes = false;
                break;
            }
            else moves += mm;
        }
        if (yes){
            ans = min(ans, moves);
        }
    }
    if (ans == 100000000){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}