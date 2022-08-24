#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <fstream>
#define int long long
using namespace std;
int n, k, pi, ci, li;
vector<vector<int> > data, f, c;
vector<int> us, d, vs;
int CONST = pow(10, 15);
int dfs(int vertex, int flow){
    if (vertex == us.size()-1 || flow <= 0) return flow;
    while (us[vertex] < us.size()){
        int now = us[vertex];
        if (d[now] - 1 != d[vertex]) {us[vertex] ++; continue;}
        if (c[vertex][now] == -1) {us[vertex] ++; continue;}
        int res = dfs(now, min(flow, c[vertex][now] - f[vertex][now]));
        if (res > 0){
            f[vertex][now] += res;
            f[now][vertex] -= res;
            return res;
        }
        us[vertex] ++;
    }
    return 0;
}
bool get_prime(int number){
    for (int i=2;i*i<=number;i++){
        if (number % i == 0) return false;
    }
    return true;
}
void bfs(int level){
    for (int i=0;i<vs.size();i++){
        d[vs[i]] = level;
    }
    vector<int> nvs;
    for (int i=0;i<vs.size();i++){
        int vv = vs[i];
        for (int j=0;j<us.size();j++){
            if (c[vv][j] != -1 && f[vv][j] < c[vv][j] && d[j] == -1){
                nvs.push_back(j);
            }
        }
    }
    if (nvs.size() > 0){
    vs = nvs;
    bfs(level + 1);
    }
}
int dinic(int l, int counter){
    c.clear();
    f.clear();
    d.clear();
    us.clear();
    for (int i=0;i<counter+2;i++){
        vector<int> fn, cn;
        us.push_back(0);
        for (int j=0;j<counter+2;j++){
            fn.push_back(0);
            cn.push_back(-1);
        }
        f.push_back(fn);
        d.push_back(-1);
        c.push_back(cn);
    }
    vector<vector<int> > now;
    int o = -1;
    for (int i=0;i<n;i++){
        if (data[i][2] <= l){
            if (data[i][1] != 1){
                now.push_back(data[i]);
            }
            else{
                o = max(o, data[i][0]);
            }
        }
    }
    if (o != -1){
        vector<int> help;
        help.push_back(o);
        help.push_back(1);
        help.push_back(l);
        now.push_back(help);
    }
    for (int i=0;i<counter;i++){
        if (now[i][1] % 2 == 0){
            c[i+1][counter+1] = now[i][0];
            c[counter+1][i+1] = 0;
        }
        else {c[0][i+1] = now[i][0]; c[i+1][0] = 0;}
    }
    for (int i=0;i<counter;i++){
        for (int j=0;j<counter;j++){
            if (now[i][1] % 2 == 0 || now[j][1] % 2 != 0) continue;
            bool pr = get_prime(now[j][1] + now[i][1]);
            if (pr) {c[i+1][j+1] = CONST; c[j+1][i+1] = 0;}
        }
    }
    int summ = 0;
    while (true){
        for (int i=0;i<counter+2;i++){
            d[i] = -1;
            us[i] = 0;
        }
        vs.clear();
        vs.push_back(0);
        bfs(0);
        if (d[counter+1] == -1) break;
        while (true){
            int flow = dfs(0, CONST);
            if (flow == 0){
                break;
            }
        }
    }
    for (int i=0;i<counter+2;i++){
        summ += f[0][i];
    }
    return summ;
}
int32_t main(){
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> pi >> ci >> li;
        vector<int> help;
        help.push_back(pi);
        help.push_back(ci);
        help.push_back(li);
        data.push_back(help);
    }
    for (int level=1;level<=100;level++){
        int summ = 0;
        int cc = 0;
        int o = -1;
        for (int i=0;i<n;i++){
            if (data[i][2] <= level){
                if (data[i][1] != 1){
                    summ += data[i][0];
                    cc++;
                }
                else{
                    o = max(o, data[i][0]);
                }
            }
        }
        if (o != -1){
            summ += o;
            cc ++;
        }
        int fl = dinic(level, cc);
        if (summ - fl >= k){
            cout << level << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}