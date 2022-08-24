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
int INF = 1e12;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, ai;
    vector<int> data;
    cin >> n >> k;
    int summ = 0;
    for (int i=0; i < n; i++){
        cin >> ai;
        summ += ai;
        data.push_back(ai);
    }
    sort(data.begin(), data.end());
    int u = 0;
    int kk = k;
    int minimum = data[0];
    while (kk > 0){
        int next = INF;
        if (u < n - 1) next = data[u+1];
        int now = data[u];
        if ((u + 1) * (next - now) <= kk){
            kk -= (u + 1) * (next - now);
            u++;
            minimum = next;
        }
        else{
            int pl = kk / (u + 1);
            minimum += pl;
            break;
        }
    }
    u = n-1;
    kk = k;
    int maximum = data.back();
    while (kk > 0){
        int next = -INF;
        if (u > 0) next = data[u-1];
        int now = data[u];
        if ((n - u) * (now - next) <= kk){
            kk -= (n - u) * (now - next);
            u--;
            maximum = next;
        }
        else{
            int pl = kk / (n - u);
            maximum -= pl;
            break;
        }
    }
    if (minimum + 1 < maximum){
        cout << maximum - minimum << endl;
    }
    else{
        cout << (summ % n != 0) << endl;
    }
    return 0;
}