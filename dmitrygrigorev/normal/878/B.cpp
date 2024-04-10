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
#include <time.h>
#include <bitset>
#include <queue>
#define int long long
using namespace std;
struct Dv{int left; int right; int prev; bool def;};
vector<int> solve(vector<int> data, int &del, int m, int k, int n){
    vector<Dv> g;
    for (int i=0; i < n; i++){
        Dv dv = {i-1, i+1, 0, false};
        g.push_back(dv);
    }
    for (int i=0; i < n; i++){
        int PREV;
        if (g[i].left < 0){
            PREV = 1;
        }
        else {
            PREV = g[g[i].left].prev * (data[g[i].left] == data[i]) + 1;
        }
        g[i].prev = PREV;
        int R = g[i].right;
        if (PREV >= k){
            g[i].def = true;
            del += k*m;
            int now = g[i].left;
            for (int j=0; j < k-1; j++){
                g[now].def = true;
                now = g[now].left;
            }
            if (R < n) g[R].left = now;
            if (now >= 0) g[now].right = R;
        }
        else if (R < n) g[R].left = i;
    }
    vector<int> ret;
    int ind = -1;
    for (int i=0; i < n; i++){
        if (!g[i].def){
            ind = i;
            break;
        }
    }
    if (ind == -1) return ret;
    while (ind < n){
        ret.push_back(data[ind]);
        ind = g[ind].right;
    }
    return ret;
}
int32_t main(){
    //freopen("1.txt", "r", stdin);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> data(n);
    for (int i=0; i < n; i++) cin >> data[i];
    bool both = true;
    for (int i=1; i < n; i++){
        both &= (data[i] == data[i-1]);
    }
    if (both){
        cout << (n*m) % k << endl;
        return 0;
    }
    int del = 0;
    int N = data.size();
    data = solve(data, del, m, k, n);
    n = data.size();
    if (n==0){
        cout << 0 << endl;
        return 0;
    }
    if (m==1){
        cout << N-del << endl;
        return 0;
    }
    vector<int> prev(n), next(n);
    next[n-1] = 1;
    for (int i=n-2; i >= 0; i--) next[i] = (data[i] == data[i+1]) * next[i+1] + 1;
    prev[0] = 1;
    for (int i=1; i < n; i++) prev[i] = (data[i] == data[i-1]) * prev[i-1] + 1;
    int L=0, R=n-1;
    //int del = 0;
    vector<int> lk, rk;
    bool prod = false;
    while (true){
        if (next[L] == R-L+1){
            int ost = m*(R-L+1);
            int och = ost % k;
            del += ost - och;
            if (och == 0){
                prod = true;
            }
            break;
        }
        if (data[L] != data[R]) break;
        int vm = next[L] + prev[R];
        if (vm < k){
            cout << N*m - del << endl;
            return 0;
        }
        int OL = L;
        int P = next[L];
        L += min(k, P);
        for (int j=OL; j < L; j++){
            lk.push_back(data[j]);
        }
        int OR = R;
        if (k > P){
            R -= k - P;
        }
        for (int j=OR; j > R; j--) rk.push_back(data[j]);
        del += k*(m-1);
    }
    if (prod){
        if (lk.size() == 0 || rk.size() == 0){
            cout << N*m - del << endl;
            return 0;
        }
        vector<int> rrk;
        for (int j=rk.size()-1; j >= 0; j--) rrk.push_back(rk[j]);
        rk = rrk;
        int PREV[lk.size()], NEXT[rk.size()];
        NEXT[rk.size()-1] = 1;
        int SZ = rk.size();
        for (int i=SZ-2; i >= 0; i--) NEXT[i] = (rk[i] == rk[i+1]) * NEXT[i+1] + 1;
        PREV[0] = 1;
        for (int i=1; i < lk.size(); i++) PREV[i] = (lk[i] == lk[i-1]) * PREV[i-1] + 1;
        int RR = lk.size() - 1;
        int LL = 0;
        while (LL < rk.size() && RR >= 0){
            if (lk[RR] != rk[LL]) break;
            int SUM = PREV[RR] + NEXT[LL];
            if (SUM < k) break;
            int ORR = RR;
            RR -= min(PREV[ORR], k);
            if (k > PREV[ORR]){
                LL += k - PREV[ORR];
            }
            del += k;
        }
    }
    cout << N*m-del << endl;
    return 0;
}