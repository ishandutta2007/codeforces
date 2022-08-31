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
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int data[n][2];
    for (int i=0; i < n; i++){
        for (int j=0; j < 2; j++){
            cin >> data[i][j];
        }
    }
    int g[n][2];
    g[0][0] = data[0][0];
    g[0][1] = data[0][1]+data[0][0];
    for (int i=1; i < n; i++){
        int l = g[i-1][0] - 1;
        int r = g[i-1][1] + 1;
        l = max(l, data[i][0]);
        r = min(r, data[i][1]+data[i][0]);
        if (l > r){
            cout << -1 << endl;
            return 0;
        }
        g[i][0] = l;
        g[i][1] = r;
    }
    vector<int> answer(n);
    int now = g[n-1][1];
    for (int i=n-1; i >= 0; i--){
        answer[i] = now;
        if (i == 0) break;
        for (int j=1; j >= -1; j--){
            if (now+j <= g[i-1][1] && now+j >= g[i-1][0]){
                now += j;
                break;
            }
        }
    }
    int F=0, S = 0;
    for (int i=0; i < n; i++) F += data[i][0];
    for (int i=0; i < n; i++) S += answer[i];
    cout << S-F << endl;
    for (int i=0; i < n; i++) cout << answer[i] << " ";
    return 0;
}