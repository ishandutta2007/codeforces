#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#define int long long
using namespace std;
int ans, cc;
string l, r;
vector<int> v1, v2;
void pr(vector<int> v){
    for (int i=0; i < 10; i++){
        for (int j=0; j < v[i]; j++){
            cout << i;
        }
    }
    cout << endl;
}
void recursion(int level, vector<int> &v){
    if (level <= 9){
        for (int i=0; i <= 19; i++){
            if (v.back() + i > 19) break;
            v.back() += i;
            v[level] += i;
            recursion(level+1, v);
            v.back() -= i;
            v[level] -= i;
        }
    }
    else{
        cc++;
        v1 = v;
        v1[0] = 19 - v1.back();
        int n_out, x, y;
        for (int i=0; i < 19; i++){
            if (l[i] == r[i]){
                v1[l[i] - '0'] --;
                if (v1[l[i] - '0'] < 0) {
                    //pr(vv);
                    return;
                }
            }
            else{
                n_out = i;
                x = l[i] - '0';
                y = r[i] - '0';
                break;
            }
        }
        for (int i=x+1;i<y;i++){
            if (v1[i] > 0){
                ans++;
                return;
            }
        }
        v2 = v1;
        v1[x] --;
        int maximum = -1;
        for (int i=9;i>=0;i--){
            if (v1[i] > 0){
                maximum = i;
                break;
            }
        }
        v2[y] --;
        int minimum = -1;
        for (int i=0;i<=9;i++){
            if (v2[i] > 0){
                minimum = i;
                break;
            }
        }
        if (n_out == 18){
            if (v2[y] == 0 || v1[x] == 0) ans ++;
            else //pr(vv);
            return;
        }
        if (v1[x] >= 0 && maximum != -1){
            bool aa = true;
            for (int i=n_out+1; i < 19;i++){
                int num = l[i] - '0';
                if (num < maximum){
                    ans ++;
                    return;
                }
                if (maximum < num) {
                    aa = false;
                    break;
                }
                v1[maximum]--;
                if (v1[maximum] == 0){
                    for (int j=maximum-1;j>=0;j--){
                        if (v1[j] > 0){
                            maximum = j;
                            break;
                        }
                    }
                }
            }
            if (aa){
                ans ++;
                return;
            }
        }
        if (v2[y] >= 0 && minimum != -1){
            bool aa = true;
            for (int i=n_out+1; i < 19;i++){
                int num = r[i] - '0';
                if (num > minimum){
                    ans ++;
                    return;
                }
                if (minimum > num) {
                    aa = false;
                    break;
                }
                v2[minimum]--;
                if (v2[minimum] == 0){
                    for (int j=minimum+1;j<=9;j++){
                        if (v2[j] > 0){
                            minimum = j;
                            break;
                        }
                    }
                }
            }
            if (aa){
                ans ++;
                return;
            }
        }
        //pr(vv);
    }
}
int32_t main(){
    cin >> l >> r;
    if (l == r){
        cout << 1 << endl;
        return 0;
    }
    while (l.size() < 19){
        l = "0" + l;
    }
    while (r.size() < 19){
        r = "0" + r;
    }
    ans = 0;
    vector<int> v;
    for (int i=0; i < 11; i++){
        v.push_back(0);
    }
    recursion(1, v);
    cout << ans << endl;
    return 0;
}