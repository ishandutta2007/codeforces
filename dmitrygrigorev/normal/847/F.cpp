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
#include <deque>
#define int long long
using namespace std;
int32_t main(){
    int n, k, m, a, ai;
    cin >> n >> k >> m >> a;
    vector<int> kk;
    vector<int> votes(n);
    for (int i=0; i < n; i++){
        votes[i] = 0;
    }
    for (int i=0; i < a; i++){
        cin >> ai;
        kk.push_back(ai-1);
        votes[ai-1]++;
    }
    vector<int> ans(n);
    for (int i=0; i < n; i++){
        vector<pair<int, int> > p;
        bool can = false, cant = false;
        for (int j=0; j < n; j++){
            if (j == i) continue;
            p.push_back(make_pair(votes[j], j));
        }
        sort(p.begin(), p.end(), greater<pair<int, int> > ());
        if (n == k){
            if (votes[i] != 0 || a != m){
                can = true;
            }
        }
        else{
            if (votes[i] != 0 || a != m){
                int vv = p[k-1].first;
                int must = max((int) 0, vv - votes[i]+1);
                if (vv == votes[i]){
                    int sliv = 0;
                    for (int j=0; j < n-1; j++){
                        if (p[j].first > votes[i]) sliv++;
                    }
                    for (int j=0; j < n; j++){
                        bool cm = true;
                        if (i == j) continue;
                        if (votes[j] != votes[i]) continue;
                        for (int t=a-1; t >= 0; t--){
                            if (kk[t] == j) break;
                            if (kk[t] == i){
                                cm = false;
                                break;
                            }
                        }
                        if (!cm) sliv++;
                    }
                    if (sliv < k) must--;
                }
                if (m-a >= must) can = true;
            }
        }
        if (votes[i] == 0){
            cant = true;
        }
        else{
            if (k != n){
                int must = 0;
                for (int j=0; j < k; j++){
                    int jj = p[j].first;
                    int pay = max((int) 0, votes[i] - jj + 1);
                    if (votes[i] == jj){
                        bool cm = true;
                        for (int t=a-1; t >= 0; t--){
                            if (kk[t] == i) break;
                            if (kk[t] == p[j].second){
                                cm = false;
                                break;
                            }
                        }
                        if (cm) pay--;
                    }
                    must += pay;
                }
                if (m-a >= must) cant = true;
            }
        }
        if (can && cant){
            ans[i] = 2;
        }
        else if (can){
            ans[i] = 1;
        }
        else ans[i] = 3;
    }
    for (int i=0; i < n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}