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
#define ll long long
using namespace std;
ll K = 1000000009;
ll pr = 113;
vector<ll> steps;
int32_t main(){
    string s;
    cin >> s;
    int sz = s.size();
    int p[sz][sz];
    vector<ll> ans;
    for (int i=0; i < s.size(); i++){
        ans.push_back(0);
    }
    for (int i=0; i < sz; i++){
        for (int j=0; j < sz; j++){
            p[i][j] = 0;
        }
    }
    vector<ll> hashs, hashs_o;
    hashs.push_back(0);
    ll st = 1;
    for (int i=0; i < sz; i++){
        ll num = s[i] - 'a' + 1;
        ll last = hashs.back();
        ll nv = (num * st + last);
        nv %= K;
        hashs.push_back(nv);
        steps.push_back(st);
        st *= pr;
        st %= K;
    }
    hashs_o.push_back(0);
    for (int i=sz-1; i >= 0; i--){
        ll num = s[i] - 'a' + 1;
        ll last = hashs_o.back();
        ll nv = (num * steps[sz-i-1] + last);
        nv %= K;
        hashs_o.push_back(nv);
    }
    for (int d=0; d < s.size(); d++){
        for (int i=0; i <s.size(); i++){
            if (i + d >= s.size()) break;
            int l = i;
            int r = i + d;
            if (d == 0){
                p[l][r] = 1;
                ans[0] ++;
            }
            else{
                int x = (d + 1) / 2;
                int p1 = p[l][l+x-1];
                ll h1 = hashs[l + x] - hashs[l];
                ll h2 = hashs[r + 1] - hashs[r + 1 - x];
                h1 %= K;
                h1 += K;
                h1 %= K;
                h2 %= K;
                h2 += K;
                h2 %= K;
                int diff = (r + 1 - l - x);
                h1 *= steps[diff];
                h1 %= K;
                if (h1 == h2){
                    if (p1 > 0){
                    p[l][r] = p1 + 1;
                    for (int j=0; j < p1 + 1; j++){
                        ans[j] ++;
                    }
                    }
                    else{
                        p[l][r] = 0;
                    }
                }
                else{
                    ll hh = hashs[r + 1] - hashs[l];
                    ll hhh = hashs_o[s.size() - l] - hashs_o[s.size() - r - 1];
                    hh %= K;
                    hh += K;
                    hh %= K;
                    hhh %= K;
                    hhh += K;
                    hhh %= K;
                    if (l > s.size() - r - 1){
                        hhh *= steps[l - s.size() + r + 1];
                        hhh %= K;
                    }
                    else{
                        hh *= steps[s.size() - r - 1 - l];
                        hh %= K;
                    }
                    if (hh != hhh) p[l][r] = 0;
                    else {
                        p[l][r] = 1;
                        ans[0]++;
                    }
                }
            }
        }
    }
    for (int i=0; i < s.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}