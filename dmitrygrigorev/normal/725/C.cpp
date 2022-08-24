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
string s;
char dp[2][13];
map<char, int> mm;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> s;
    char now;
    int d, ii;
    for (int i=0;i<27;i++){
        char ch = s[i];
        if (!mm.count(ch)){
            mm[ch] = i;
        }
        else{
            now = ch;
            d = i - mm[ch] - 1;
            ii = i + 1;
            break;
        }
    }
    if (d == 0){
        cout << "Impossible" << endl;
        return 0;
    }
    else{
        dp[0][(26 - d - 1) / 2] = now;
    }
    int pos = mm[now] + 1;
    int np = (26 - d - 1) / 2;
    int nnp = np - 1;
    bool change = false;
    while (d > 0){
         if (!change){
            if (np < 12){
                dp[0][np + 1] = s[pos];
                pos ++;
                np ++;
            }
            else{
                change = true;
                dp[1][np] = s[pos];
                np --;
                pos ++;
            }
         }
         else{
            dp[1][np] = s[pos];
            np --;
            pos ++;
         }
         d--;
    }
    bool go = false;
    while (ii < 27){
        if (!go){
            if (np > 0){
                dp[1][np] = s[ii];
                np --;
            }
            else{
                dp[1][np] = s[ii];
                go = true;
            }
        }
        else{
            dp[0][np] = s[ii];
            np ++;
        }
        ii ++;
    }
    pos = mm[now] - 1;
    go = false;
    while (pos >= 0){
        if (nnp < 0){
            nnp = 0;
            go = true;
        }
        if (!go){
            if (nnp > 0){
                dp[0][nnp] = s[pos];
                nnp --;
            }
            else{
                dp[0][nnp] = s[pos];
                go = true;
            }
        }
        else{
            dp[1][nnp] = s[pos];
            nnp ++;
        }
        pos --;
    }
    for (int i=0;i<2;i++){
        for (int j=0;j<13;j++){
            cout << dp[i][j];
        }
        cout << endl;
    }
    return 0;
}