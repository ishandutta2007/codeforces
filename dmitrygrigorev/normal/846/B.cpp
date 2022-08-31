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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> data(k);
    for (int i=0; i < k; i++){
        cin >> data[i];
    }
    sort(data.begin(), data.end());
    int ans = 0;
    for (int i=0; i <= n; i++){
        int th = 0;
        int money = 0;
        for (int j=0; j < k; j++){
            th += i;
            money += data[j] * i;
        }
        th += i;
        if (money > m) continue;
        for (int j=0; j < k; j++){
            for (int p=i+1; p <= n; p++){
                money += data[j];
                if (money <= m) th++;
            }
        }
        ans = max(ans, th);
    }
    cout << ans << endl;
    return 0;
}