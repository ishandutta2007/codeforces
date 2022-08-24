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
#include <cassert>
#include <cstdio>
#include <complex>
#define int long long
using namespace std;
int n, k, ai;
vector<int> data;
int32_t main()
{
    cin >> n >> k;
    for (int i=0; i < n; i++){
        cin >> ai;
        data.push_back(ai);
    }
    int ba = 1;
    int ans;
    for (int i=2; i <= 1e5; i++){
        ans = 0;
        for (int j=0; j < n; j++){
            int mn = data[j] / i;
            if (data[j] % i != 0) mn++;
            int money = mn * i - data[j];
            ans += money;
        }
        if (ans <= k) ba = i;
    }
    vector<pair<int, int> > ev;
    for (int i=1; i < 10000; i++){
        for (int j=0; j < n; j++){
            int start = data[j] / i;
            if (data[j] % i != 0) start++;
            if (start <= 100000) continue;
            pair<int, int> p = make_pair(start, j);
            ev.push_back(p);
        }
    }
    vector<int> pls, times;
    sort(ev.begin(), ev.end());
    int pl = 0;
    for (int j=0; j < n; j++){
        int del = data[j] / 100000;
        if (data[j] % 100000 != 0) del ++;
        pl += del;
        pls.push_back(del);
        times.push_back(100000);
    }
    int nt = 1e5;
    int nole = 0;
    for (int i=0; i < ev.size(); i++){
        int tt = ev[i].first;
        int where = ev[i].second;
        int new_ans = ans + max(nole, tt - nt) * pl;
        if (new_ans > k && ans <= k){
            int can = (k - ans) / pl;
            ba = can + nt;
        }
        if (new_ans <= k) ba = tt - 1;
        ans = new_ans;
        if (times[where] != tt){
            int lost = tt * pls[where] - k;
            int better = data[where] / tt;
            if (data[where] % tt != 0) better++;
            int nost = tt * better - k;
            pl += better - pls[where];
            ans -= (lost - nost);
            pls[where] = better;
        }
        nt = tt;
        times[where] = tt;
    }
    sort(data.begin(), data.end());
    int left = data[data.size() - 1];
    int right = 1e12;
    while (right - left > 1){
        int that = 0;
        int mid = (left + right) / 2;
        for (int i=0; i < n; i++){
            that += mid - data[i];
        }
        if (that > k) right = mid;
        else left = mid;
    }
    if (left != data[data.size() - 1]) ba = left;
    cout << ba << endl;
    return 0;
}