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
int32_t main()
{
    int n, m, p, ai;
    cin >> n >> m >> p;
    vector<int> people, keys;
    for (int i=0;i<n;i++){
        cin >> ai;
        people.push_back(ai);
    }
    for (int i=0; i < m; i++){
        cin >> ai;
        keys.push_back(ai);
    }
    sort(people.begin(), people.end());
    sort(keys.begin(), keys.end());
    int ans = 1e18;
    for (int i=0; i < m; i++){
        int finish = i + n - 1;
        if (finish >= m) break;
        int cand = 0;
        for (int j=0; j < n; j++){
            cand = max(cand, abs(people[j] - keys[i+j]) + abs(keys[i+j] - p));
        }
        ans = min(ans, cand);
    }
    cout << ans << endl;
    return 0;
}