#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <bitset>
#include <fstream>
#define int long long
#define D double
using namespace std;
signed main()
{
    int N, S;
    cin >> N >> S;
    int v[N][3];
    for (int i=0; i < N; i++){
        for (int j=0; j < 3; j++){
            cin >> v[i][j];
        }
    }
    vector<pair<int, int> > first, second;
    int fp = 0, sp = 0, ans = 0;
    for (int i=0; i < N; i++){
        if (v[i][1] >= v[i][2]){
            fp += v[i][0];
            ans += v[i][0] * v[i][1];
            first.push_back(make_pair(v[i][1] - v[i][2], v[i][0]));
        }
        else{
            sp += v[i][0];
            ans += v[i][0] * v[i][2];
            second.push_back(make_pair(v[i][2] - v[i][1], v[i][0]));
        }
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    int bminus = 1e18;
    int u = 0;
    int var = 0;
    int ff = fp;
    while (u < first.size() && ff % S != 0){
        int nek = ff % S;
        var += first[u].first * min(first[u].second, nek);
        if (first[u].second >= nek){
            ff = 0;
        }
        else{
            ff -= first[u].second;
        }
        u++;
    }
    if (ff % S == 0){
        bminus = min(bminus, var);
    }
    u = 0;
    var = 0;
    ff = sp;
    while (u < second.size() && ff % S != 0){
        int nek = ff % S;
        var += second[u].first * min(second[u].second, nek);
        if (second[u].second >= nek){
            ff = 0;
        }
        else{
            ff -= second[u].second;
        }
        u++;
    }
    if (ff % S == 0){
        bminus = min(bminus, var);
    }
    u = 0;
    var = 0;
    ff = fp;
    while (u < second.size() && ff % S != 0){
        int nek = S - ff % S;
        var += second[u].first * min(second[u].second, nek);
        if (second[u].second >= nek){
            ff = 0;
        }
        else{
            ff += second[u].second;
        }
        u++;
    }
    if (ff % S == 0){
        bminus = min(bminus, var);
    }
    u = 0;
    var = 0;
    ff = sp;
    while (u < first.size() && ff % S != 0){
        int nek = S - ff % S;
        var += first[u].first * min(first[u].second, nek);
        if (first[u].second >= nek){
            ff = 0;
        }
        else{
            ff += first[u].second;
        }
        u++;
    }
    if (ff % S == 0){
        bminus = min(bminus, var);
    }
    int NP = (fp + sp) / S;
    if ((fp+sp) % S != 0) NP++;
    int FP = fp / S;
    if (fp % S != 0) FP++;
    int SP = sp / S;
    if (sp % S != 0) SP++;
    if (FP + SP == NP) bminus = 0;
    cout << ans - bminus << endl;
    return 0;
}