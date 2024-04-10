
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
using namespace std;
int n, k, x, y;
vector<vector<int> > data;
vector<long long> please;
vector<bool> used;
int mm, mv;
long long answer;
bool get_centroid(int vertex, int last, int d){
    bool go = false;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (used[to] || last == to) continue;
        bool res = get_centroid(to, vertex, d+1);
        if (res) go = true;
        if (d == mm / 2 && res){
            mv = vertex;
        }
    }
    if (d > mm){mm=d;return true;}
    return go;
}
void udal(int vertex, int last, int d){
    if (d > mm){mm = d;mv=vertex;}
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (to == last || used[to]) continue;
        udal(to, vertex, d+1);
    }
}
void get_result(int vertex, int last, int d){
    if (please.size() > d){
        please[d] ++;
    }
    else please.push_back(1);
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (used[to] || to == last) continue;
        get_result(to, vertex, d+1);
    }
}
void dfs(int vertex, int last){
    mm = -1;
    udal(vertex, -1, 0);
    if (mv == vertex) return;
    mm = -1;
    get_centroid(mv, -1, 0);
    vector<long long> summ;
    int mmv = mv;
    vector<vector<long long> > res;
    for (int i=0;i<data[mmv].size();i++){
        int to = data[mmv][i];
        if (used[to]) continue;
        please.clear();
        get_result(to, mmv, 0);
        for (int j=0;j<please.size();j++){
            if (j < summ.size()) summ[j] += please[j];
            else summ.push_back(please[j]);
        }
        res.push_back(please);
    }
    for (int i=0;i<summ.size();i++){
        answer += summ[i] * (i / k + 1);
    }
    long long lll = 0;
    long long defeat[k];
        for (int j=0;j<k;j++){
            defeat[j%k] = 0;
        }
        for (int j=0;j<summ.size();j++){
            defeat[j % k] += summ[j];
        }
        long long nns = 0;
        for (int j=0;j<summ.size();j++){
            nns += summ[j] * (j / k + 1);
        }
    for (int i=0;i<res.size();i++){
        long long spl = 0;
        vector<long long> now = res[i];
        for (int j=0;j<min(now.size(), summ.size());j++){
            summ[j] -= now[j];
        }
        long long ns = nns;
        for (int j=0;j<now.size();j++){
            ns -= now[j] * (j / k + 1);
        }
        for (int j=0;j<now.size();j++){
            defeat[j%k] -= now[j];
        }
        for (int j=0;j<now.size();j++){
            ns += defeat[((k - j - 1)%k + k) % k];
            spl += ns * now[j];
        }
        lll += spl;
        for (int j=0;j<min(now.size(), summ.size());j++){
            summ[j] += now[j];
        }
        for (int j=0;j<now.size();j++){
            defeat[j%k] += now[j];
        }
    }
    answer += lll / 2;
    used[mmv] = true;
    for (int i=0;i<data[mmv].size();i++){
        int to = data[mmv][i];
        if (used[to]) continue;
        dfs(data[mmv][i], mmv);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0;i<n;i++){
        vector<int> help;
        data.push_back(help);
        used.push_back(false);
    }
    answer = 0;
    for (int i=0;i<n-1;i++){
        cin >> x >> y;
        data[x-1].push_back(y-1);
        data[y-1].push_back(x-1);
    }
    dfs(0, -1);
    cout << answer << endl;
    return 0;
}