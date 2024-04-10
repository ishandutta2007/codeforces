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
#define int long long
using namespace std;
int dp1[5001][5001], dp2[5001][5001];
int n, b, x;
vector<vector<int> > data;
vector<int> mass;
int K = 1e14;
int vc[5000], vd[5000];
int l[5000];
bool cmp(int first, int second){
    if (mass[first] < mass[second]) return true;
    return false;
}
void init(int vertex){
    mass[vertex] = 1;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        init(to);
        mass[vertex] += mass[to];
    }
}
void dfs(int vertex){
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        dfs(to);
    }
    int last = 1;
    dp1[vertex][0] = 0;
    dp1[vertex][1] = vc[vertex];
    dp2[vertex][1] = vc[vertex] - vd[vertex];
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        for (int j=last;j>=0;j--){
            for (int k=0;k<=l[to];k++){
                dp1[vertex][j+k] = min(dp1[vertex][j+k], dp1[vertex][j] + dp1[to][k]);
                dp2[vertex][j+k] = min(dp2[vertex][j+k], dp2[vertex][j] + min(dp1[to][k], dp2[to][k]));
            }
        }
        last += l[to];
    }
    l[vertex] = last;
}
int32_t main()
{
    cin >> n >> b;
    for (int i=0;i<n;i++){
        mass.push_back(0);
        vector<int> help; data.push_back(help);
    }
    cin >> vc[0] >> vd[0];
    for (int i=1;i<n;i++){
        cin >> vc[i] >> vd[i] >> x;
        data[x-1].push_back(i);
    }
    init(0);
    for (int i=0;i<n;i++){
        sort(data[i].begin(), data[i].end(), cmp);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<=n;j++){
            dp1[i][j] = K;
            dp2[i][j] = K;
        }
    }
    dfs(0);
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (min(dp1[0][i], dp2[0][i]) <= b) ans++;
    }
    cout << ans << endl;
    return 0;
}