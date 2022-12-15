#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int sza[2005],szb[2005],save[1005][1005][2],xa[1005],xb[1005],la[2005],ra[2005],lb[2005],rb[2005];
vector <int> va[2005],vb[2005];
void dfs1(int x,int from) {
    if (x != 1) sza[x] = 1;
    for (int i = 0; i < va[x].size(); i++) {
        if (va[x][i] == from) continue;
        dfs1(va[x][i], x);
        la[x] = min(la[x], la[va[x][i]]);
        ra[x] = max(ra[x], ra[va[x][i]]);
        sza[x] += sza[va[x][i]];
    }
    //cout<<x<<" "<<la[x]<<" "<<ra[x]<<" "<<sza[x]<<endl;
    save[la[x]][ra[x]][0] = sza[x];
}
void dfs2(int x,int from) {
    if (x != 1) szb[x] = 1;
    for (int i = 0; i < vb[x].size(); i++) {
        if (vb[x][i] == from) continue;
        dfs2(vb[x][i], x);
        lb[x] = min(lb[x], lb[vb[x][i]]);
        rb[x] = max(rb[x], rb[vb[x][i]]);
        szb[x] += szb[vb[x][i]];
    }
    save[lb[x]][rb[x]][1] = szb[x];
}
int dp[1005];
int main() {
    int n, a, b;
    cin >> n;
    cin >> a;
    for (int i = 1; i <= a; i++) la[i] = INT_MAX, ra[i] = 0;
    for (int i = 2; i <= a; i++) {
        int t;
        scanf("%d", &t);
        va[t].push_back(i);
        va[i].push_back(t);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &xa[i]);
        la[xa[i]] = ra[xa[i]] = i;
    }
    cin >> b;
    for (int i = 1; i <= b; i++) lb[i] = INT_MAX, rb[i] = 0;
    for (int i = 2; i <= b; i++) {
        int t;
        scanf("%d", &t);
        vb[t].push_back(i);
        vb[i].push_back(t);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &xb[i]);
        lb[xb[i]] = rb[xb[i]] = i;
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            dp[i] = max(dp[i], dp[j] + max(save[j + 1][i][1], save[j + 1][i][0]));
    cout << dp[n] << endl;
    return 0;
}