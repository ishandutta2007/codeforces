#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
using namespace std;
int n, m, x, y;
vector<vector<int> > data;
vector<long long> r;
vector<bool> used;
long long rebro;
void dfs(int vertex){
    used[vertex] = true;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (!used[to]) dfs(to);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0;i<n;i++){
        r.push_back(0);
        used.push_back(true);
        vector<int> help;
        data.push_back(help);
    }
    rebro = 0;
    int st;
    for (int i=0;i<m;i++){
        cin >> x >> y;
        if (x == y) {rebro ++; used[x-1] = false; st=x-1;}
        else{
                    data[x-1].push_back(y-1);
        data[y-1].push_back(x-1);
        r[x-1] ++;
        r[y-1] ++;
        used[x-1] = false;
        st = x-1;
        used[y-1] = false;
        }
    }
    long long ans=0;
    dfs(st);
    for (int i=0;i<n;i++){
        if (!used[i]){
            cout << 0 << endl;
            return 0;
        } 
    }
    for (int i=0;i<n;i++){
        long long res = (r[i] * (r[i] - 1)) / 2;
        ans += res;
    }
    long long res = (rebro) * (rebro - 1) / 2;
    ans += res;
    long long rr = m - rebro;
    res = rebro * rr;
    ans += res;
    cout << ans << endl;
    return 0;
}