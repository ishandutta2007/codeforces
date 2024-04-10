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
#include <unordered_map>
#define int long long
#define please int
using namespace std;
int counter, n, m, q, ai, bi, ci, di, special;
int CONST = 1000000000000000;
vector<vector<int> >  girls[100005], rmqs[100005];
vector<int> adds[100005];
vector<int> euler_rmq;
vector<int> hhh = {CONST, CONST, CONST};
vector<vector<int> > data, ways;
int asks[100005][4];
int ec[100005];
vector<int> num_ways, counts, lengths, coords, lefts, rights, euler;
void fc(int i, int l, int r, int l1, int r1, int cc, int ch){
    if (l1 >= r1){
        return;
    }
    if (l1 == l && r1 == r){
        rmqs[cc][i][0] += ch;
        adds[cc][i] += ch;
        return;
    }
    int m = (l + r) / 2;
    fc(2*i+1, l, m, l1, min(r1, m), cc, ch);
    fc(2*i+2, m, r, max(l1, m), r1, cc, ch);
    rmqs[cc][i] = min(rmqs[cc][2*i+1], rmqs[cc][2*i+2]);
    rmqs[cc][i][0] += adds[cc][i];
}
void change_euler(int i, int l, int r, int l1, int r1, int dd){
    if (l1 >= r1) return;
    if (l == l1 && r == r1) euler_rmq[i] += dd;
    else{
        int m = (l + r) / 2;
        change_euler(2*i+1, l, m, l1, min(r1, m), dd);
        change_euler(2*i+2, m, r, max(l1, m), r1, dd);
    }
}
int get_euler(int i, int l, int r, int ind){
    if (r - l == 1) return euler_rmq[i];
    int m = (l + r) / 2;
    if (ind < m) return euler_rmq[i] + get_euler(2*i+1, l, m, ind);
    return euler_rmq[i] + get_euler(2*i+2, m, r, ind);
}
vector<int> get_answer(int i, int l, int r, int l1, int r1, int cc, int adp){
    if (l1 >= r1){
        return hhh;
    }
    if (l1 == l && r == r1){
        vector<int> ans = rmqs[cc][i];
        ans[0] += adp;
        return ans;
    }
    int m = (l + r) / 2;
    vector<int> a1 = get_answer(2*i+1, l, m, l1, min(r1, m), cc, adp + adds[cc][i]);
    vector<int> a2 = get_answer(2*i+2, m, r, max(l1, m), r1, cc, adp + adds[cc][i]);
    return min(a1, a2);
}
vector<int> get_girl(int v1, int v2){
    vector<int> girl = hhh;
    while (num_ways[v1] != num_ways[v2]){
        int sz = ways[num_ways[v1]].size() - 1;
        vector<int> gn = get_answer(0, 0, sz, coords[v1], sz, num_ways[v1], 0);
        gn[0] += get_euler(0, 0, counter, ec[num_ways[v1]]);
        girl = min(girl, gn);
        v1 = ways[num_ways[v1]].back();
    }
    if (v1 == v2 && v1 == 0) return girl;
    int sz = ways[num_ways[v1]].size() - 1;
    vector<int> gn = get_answer(0, 0, sz, coords[v1], coords[v2] + 1, num_ways[v1], 0);
    gn[0] += get_euler(0, 0, counter, ec[num_ways[v1]]);
    girl = min(girl, gn);
    return girl;
}
void change(int i, int l, int r, int ind, int d, int cc, int vv, int girl){
    if (r - l == 1){
        rmqs[cc][i][0] = d + adds[cc][i];
        rmqs[cc][i][1] = vv;
        rmqs[cc][i][2] = girl;
        return;
    }
    int m = (l + r) / 2;
    if (ind < m){
        change(2*i+1, l, m, ind, d, cc, vv, girl);
    }
    else{
        change(2*i+2, m, r, ind, d, cc, vv, girl);
    }
    rmqs[cc][i] = min(rmqs[cc][2*i+1], rmqs[cc][2*i+2]);
    rmqs[cc][i][0] += adds[cc][i];
}
void euler_dfs(int vertex, int last){
    lefts[vertex] = euler.size();
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (to == last) continue;
        euler_dfs(to, vertex);
    }
    rights[vertex] = euler.size();
    if (vertex == 0) return;
    int ww = num_ways[vertex];
    int sz = ways[ww].size() - 2;
    if (ways[ww][sz] == vertex && num_ways[0] != ww){
        ec[ww] = euler.size();
        euler.push_back(ww);
    }
}
int dfs(int vertex, int last){
    bool heavy = false;
    int now_way;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (last == to) continue;
        int nw = dfs(to, vertex);
        if (counts[to] * 2 >= counts[vertex] && vertex != 0){
            heavy = true;
            now_way = nw;
            coords[vertex] = ways[nw].size();
            num_ways[vertex] = nw;
        }
        ways[nw].push_back(vertex);
    }
    if (!heavy){
        vector<int> help;
        help.push_back(vertex);
        ways.push_back(help);
        num_ways[vertex] = counter;
        coords[vertex] = 0;
        counter ++;
        return counter - 1;
    }
    return now_way;
}
int count_dfs(int vertex, int last, int d){
    int now_count = 0;
    lengths[vertex] = d;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (to == last) continue;
        now_count += count_dfs(to, vertex, d+1);
    }
    counts[vertex] = now_count + 1;
    return counts[vertex];
}
int get_lca(int f, int s){
    if (num_ways[f] == num_ways[s]){
        if (lengths[f] < lengths[s]) return f;
        return s;
    }
    int k1 = ways[num_ways[f]].back();
    int k2 = ways[num_ways[s]].back();
    if (k1 == k2) return k1;
    if (lengths[k1] >= lengths[k2]){
        return get_lca(k1, s);
    }
    return get_lca(f, k2);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i=0;i<n;i++){
        vector<int> help;
        data.push_back(help);
        lengths.push_back(-1);
        counts.push_back(-1);
        num_ways.push_back(-1);
        coords.push_back(-1);
        lefts.push_back(-1);
        rights.push_back(-1);
    }
    for (int i=0;i<n-1;i++){
        cin >> ai >> bi;
        data[ai - 1].push_back(bi - 1);
        data[bi - 1].push_back(ai - 1);
    }
    for (int i=0;i<m;i++){
        cin >> ai;
        vector<int> gg;
        gg.push_back(i + 1);
        gg.push_back(ai - 1);
        gg.push_back(i + 1);
        girls[ai - 1].push_back(gg);
    }
    for (int i=0;i<q;i++){
        cin >> ai;
        asks[i][0]=ai;
        if (ai == 1){
            cin >> bi >> ci >> di;
            asks[i][1] = bi-1;
            asks[i][2] = ci-1;
            asks[i][3] = di;
        }
        else{
            cin >> bi >> ci;
            asks[i][1] = bi-1;
            asks[i][2] = ci;
        }
    }
    counter = 0;
    count_dfs(0, -1, 0);
    dfs(0, -1);
    for (int i=0;i<4*counter;i++){
        euler_rmq.push_back(0);
    }
    for (int i=0;i<counter;i++){
        vector<vector<int> > rmq;
        vector<int> add;
        for (int j=0;j<4*(ways[i].size() - 1);j++){
            vector<int> g;
            g = hhh;
            rmq.push_back(g);
            add.push_back(0);
        }
        adds[i] = add;
        rmqs[i] = rmq;
    }
    int special = 0;
    for (int i=1;i<n;i++){
        if (girls[i].size() > 0){
            sort(girls[i].begin(), girls[i].end(), greater<vector<int> >());
            int num = num_ways[i];
            int sz = ways[num].size() - 1;
            int count_now = girls[i].back()[0];
            int girl_num = girls[i].back()[2];
            change(0, 0, sz, coords[i], count_now, num, i, girl_num);
        }
    }
    euler_dfs(0, -1);
    ec[num_ways[0]] = euler.size();
    euler.push_back(num_ways[0]);
    if (girls[0].size() > 0){
        sort(girls[0].begin(), girls[0].end(), greater<vector<int> >());
    }
    for (int i=0;i<q;i++){
        if (asks[i][0] == 1){
            int vv = asks[i][1];
            int uu = asks[i][2];
            int kk = asks[i][3];
            vector<int> answer;
            for (int j=0;j<kk;j++){
                vector<int> g1;
                int lca = get_lca(vv, uu);
                g1 = get_girl(vv, lca);
                vector<int> g2 = get_girl(uu, lca);
                if (g1 > g2) swap(g1, g2);
                if (lca == 0){
                    if (girls[0].size() > 0){
                        vector<int> gg = girls[0].back();
                        gg[0] += special;
                        g1 = min(g1, gg);
                    }
                }
                if (g1[0] >= CONST) break;
                answer.push_back(g1[2]);
                int num = g1[1];
                int wn = num_ways[num];
                int sz = ways[wn].size() - 1;
                girls[num].pop_back();
                int mm = CONST;
                int mmm = CONST;
                if (girls[num].size() > 0){
                    mm = girls[num].back()[0];
                    mmm = girls[num].back()[2];
                }
                if (num != 0){
                change(0, 0, sz, coords[num], mm, wn, num, mmm);
                }
            }
            cout << answer.size() << " ";
            for (int j=0;j<answer.size();j++){
                cout << answer[j] << " ";
            }
            cout << endl;
        }
        else{
            int vv = asks[i][1];
            int ch = asks[i][2];
            change_euler(0, 0, counter, lefts[vv], rights[vv], ch);
            if (vv == 0) special += ch;
            else{
                int num = num_ways[vv];
                int sz = ways[num].size() - 1;
                fc(0, 0, sz, 0, coords[vv] + 1, num, ch);
            }
        }
    }
    return 0;
}