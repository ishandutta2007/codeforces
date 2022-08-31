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
#include <deque>
#define int long long
using namespace std;
int n, k, ai;
vector<int> data;
bool checker(int number){
    vector<int> d;
    d.push_back(0);
    int u = 0;
    for (int i=1; i < n; i++){
        if (u == d.size()) return false;
        if (d[u] <= i-k && n-i >= k) d.push_back(i);
        while (u != d.size() && data[i] - data[d[u]] > number){
            u++;
        }
    }
    return (u != d.size());
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i=0; i < n; i++){
        cin >> ai;
        data.push_back(ai);
    }
    sort(data.begin(), data.end());
    int left = -1;
    int right = 1e18;
    while (right - left > 1){
        int mid = (left + right) / 2;
        bool res = checker(mid);
        if (res) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}