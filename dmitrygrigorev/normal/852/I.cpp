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
const int N = 100000, LOG = 17;
int n, ai, bi, timer, res;
vector<vector<int> > data;
int binup[N][LOG], counts[N][2];
vector<int> tin(N), tout(N), genders(N), numbers(N), eat(N), who(N), lcas(N), euler;
bool cmp(vector<int> &v1, vector<int> &v2){
    if (v1[1] < v2[1]) return true;
    return false;
}
void add(int p){
    int people = euler[p];
    eat[people]++;
    if (eat[people] == 1){
        res += counts[who[people]][genders[people]^1];
        counts[who[people]][genders[people]]++;
    }
    else{
        res -= counts[who[people]][genders[people]^1];
        counts[who[people]][genders[people]]--;
    }
}
void del(int p){
    int people = euler[p];
    eat[people]--;
    if (eat[people] == 1){
        res += counts[who[people]][genders[people]^1];
        counts[who[people]][genders[people]]++;
    }
    else{
        res -= counts[who[people]][genders[people]^1];
        counts[who[people]][genders[people]]--;
    }
}
void dfs(int vertex, int last){
    tin[vertex] = timer;
    euler.push_back(vertex);
    timer++;
    if (last != -1){
        binup[vertex][0] = last;
        int father = last;
        int level = 0;
        while (binup[father][level] != -1){
            binup[vertex][level+1] = binup[father][level];
            father = binup[father][level];
            level++;
        }
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to == last) continue;
        dfs(to, vertex);
    }
    tout[vertex] = timer;
    euler.push_back(vertex);
    timer++;
}
int LCA(int u, int v){
    if (u == v) return u;
    if (tin[u] < tin[v] && tout[u] > tout[v]) return u;
    if (tin[v] < tin[u] && tout[v] > tout[u]) return v;
    int vertex = u;
    for (int i=LOG-1; i >= 0; i--){
        int cand = binup[vertex][i];
        if (cand == -1) continue;
        if (tin[cand] < tin[v] && tout[cand] > tout[v]) continue;
        vertex = cand;
    }
    return binup[vertex][0];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i < n; i++){
        tin.push_back(-1);
        tout.push_back(-1);
        vector<int> help;
        data.push_back(help);
        for (int j=0; j < LOG; j++){
            binup[i][j] = -1;
        }
    }
    for (int i=0; i < n; i++){
        cin >> genders[i];
    }
    map<int, int> mm;
    for (int i=0; i < n; i++){
        cin >> numbers[i];
        if (mm.count(numbers[i])){
            who[i] = mm[numbers[i]];
        }
        else{
            int sz = mm.size();
            mm[numbers[i]] = sz;
            who[i] = mm[numbers[i]];
        }
    }
    for (int i=0; i < n-1; i++){
        cin >> ai >> bi;
        data[ai-1].push_back(bi-1);
        data[bi-1].push_back(ai-1);
    }
    timer = 0;
    dfs(0, -1);
    int x = ceil(sqrt(2*n));
    vector<int> sqd;
    sqd.push_back(0);
    while (sqd.back() < 2*n){
        int nv = sqd.back() + x;
        if (nv > 2*n) nv = 2*n;
        sqd.push_back(nv);
    }
    vector<pair<int, int> > wanted;
    vector<vector<int> > really;
    int q;
    cin >> q;
    for (int i=0; i < q; i++){
        cin >> ai >> bi;
        wanted.push_back(make_pair(ai-1, bi-1));
    }
    vector<int> answers(q);
    for (int i=0; i < q; i++){
        answers[i] = 0;
        lcas[i] = -1;
        int lca = LCA(wanted[i].first, wanted[i].second);
        vector<int> help;
        if (lca == wanted[i].first){
            help.push_back(tin[wanted[i].first]);
            help.push_back(tin[wanted[i].second]);
            help.push_back(i);
        }
        else if (lca == wanted[i].second){
            help.push_back(tin[wanted[i].second]);
            help.push_back(tin[wanted[i].first]);
            help.push_back(i);
        }
        else{
            lcas[i] = tin[lca];
            if (tout[wanted[i].first] < tout[wanted[i].second]){
                help.push_back(tout[wanted[i].first]);
                help.push_back(tin[wanted[i].second]);
                help.push_back(i);
            }
            else{
                help.push_back(tout[wanted[i].second]);
                help.push_back(tin[wanted[i].first]);
                help.push_back(i);
            }
        }
        really.push_back(help);
    }
    for (int i=0; i < sqd.size() - 1; i++){
        for (int j=0; j < n; j++){
            counts[j][0] = 0;
            counts[j][1] = 0;
            eat[j] = 0;
        }
        res = 0;
        vector<vector<int> > now;
        for (int j=0; j < q; j++){
            if (really[j][0] >= sqd[i] && really[j][0] < sqd[i+1]){
                now.push_back(really[j]);
            }
        }
        if (now.size() == 0) continue;
        sort(now.begin(), now.end(), cmp);
        for (int j=now[0][0]; j <= now[0][1]; j++){
            add(j);
        }
        if (lcas[now[0][2]] != -1){
            add(lcas[now[0][2]]);
        }
        answers[now[0][2]] += res;
        if (lcas[now[0][2]] != -1){
            del(lcas[now[0][2]]);
        }
        int lg = now[0][0];
        int rg = now[0][1];
        for (int j=1; j < now.size(); j++){
            for (int k=rg+1; k <= now[j][1]; k++){
                add(k);
            }
            if (lg > now[j][0]){
                for (int k=lg-1; k >= now[j][0]; k--){
                    add(k);
                }
            }
            else{
                for (int k=lg; k < now[j][0]; k++){
                    del(k);
                }
            }
            if (lcas[now[j][2]] != -1){
                add(lcas[now[j][2]]);
            }
            answers[now[j][2]] += res;
            if (lcas[now[j][2]] != -1){
                del(lcas[now[j][2]]);
            }
            rg = now[j][1];
            lg = now[j][0];
        }
    }
    for (int i=0; i < answers.size(); i++){
        cout << answers[i] << endl;
    }
    return 0;
}