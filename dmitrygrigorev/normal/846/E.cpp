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
int INF = 1e18;
vector<vector<int> > data;
vector<vector<int> > money;
int n, ai, bi;
vector<int> a, b;
bool res = true;
int dfs(int vertex, int ed){
    int balance = b[vertex] - a[vertex];
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        balance -= dfs(to, money[vertex][i]);
        if (balance <= -INF){
            res = false;
        }
        if (!res){
            return 0;
        }
    }
    if (balance >= 0){
        return -balance;
    }
    if (vertex == 0){
        res = false;
        return 0;
    }
    int max_wanted = INF / ed + 2;
    int wanted = -balance;
    if (wanted > max_wanted){
        res = false;
        return 0;
    }
    return (-balance * ed);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i < n; i++){
        cin >> bi;
        b.push_back(bi);
    }
    for (int i=0; i < n; i++){
        cin >> ai;
        a.push_back(ai);
    }
    for (int i=0; i < n; i++){
        vector<int> h1, h2;
        data.push_back(h1);
        money.push_back(h2);
    }
    for (int i=0; i < n-1; i++){
        cin >> ai >> bi;
        data[ai-1].push_back(i+1);
        money[ai-1].push_back(bi);
    }
    dfs(0, -1);
    if (res) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}