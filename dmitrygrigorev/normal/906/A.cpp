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
    vector<bool> b(26);
    fill(b.begin(), b.end(), true);
    int ans = 0;
    bool ug = false;
    for (int i=0; i < n-1; i++){
        char ch;
        string S;
        cin >> ch >> S;
        if (ug){
            if (ch != '.') ans++;
            continue;
        }
        if (ch == '?'){
            b[S[0] - 'a'] = false;
        }
        if (ch == '!'){
            vector<bool> th(26);
            fill(th.begin(), th.end(), false);
            for (int j=0; j < S.size(); j++) th[S[j] - 'a'] = true;
            for (int j=0; j < 26; j++){
                if (!th[j]) b[j] = false;
            }
        }
        if (ch == '.'){
            for (int j=0; j < S.size(); j++) b[S[j] - 'a'] = false;
        }
        int x = 0;
        for (int j=0; j < 26; j++) x += b[j];
        if (x == 1){
            ug = true;
        }
    }
    cout << ans << endl;
    return 0;
}