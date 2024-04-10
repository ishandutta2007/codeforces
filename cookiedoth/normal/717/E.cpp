#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

struct vert {
    int par;
    vector <int> cld;
};
const int mx = 210000, mmx = 500000;
int n, temp, v, u;
bool c[mx], used[mx], bb, c2[mx];
vector<int> nb[mx];
vector<int> way;
vert t[mx];

void add_to_way (int vrt) {
    way.push_back(vrt);
    c[vrt] = !c[vrt];
}

void dfs(int x) {
    int i;
    used[x] = 1;
    for (i = 0; i<nb[x].size(); i++) {
        if (used[nb[x][i]] == 1) t[x].par = nb[x][i];
        else {
            t[x].cld.push_back(nb[x][i]);
            dfs(nb[x][i]);
        }
    }
}

void make_way(int x) {
    if (t[x].cld.empty() == 1) {
        if (c[x] == 0) {
            add_to_way(x);
            add_to_way(t[x].par);
        }
    }
    else {
        add_to_way(x);
        for (int i = 0; i<t[x].cld.size(); i++) {
            make_way(t[x].cld[i]);
        }
        if (c[x] == 0) {
            add_to_way(t[x].par);
            add_to_way(x);
        }
        add_to_way(t[x].par);
    }
}

int main()
{
    cin >> n;
    way.clear();
    way.push_back(0);
    int i;
    for (i = 0; i<n; i++) {
        cin >> temp;
        if (temp == -1) c[i] = 0;
        else c[i] = 1;
        c2[i] = c[i];
        nb[i].clear();
        t[i].cld.clear();
        used[i] = 0;
    }
    for (i = 0; i<n-1; i++) {
        cin >> v >> u;
        nb[v-1].push_back(u-1);
        nb[u-1].push_back(v-1);
    }
    t[0].par = -1;
    dfs(0);
    for (i = 0; i<t[0].cld.size(); i++) {
        make_way(t[0].cld[i]);
    }
    if (c[0] == 0) {
        bb = 1;
        for (i = 1; i<n; i++) {
            if (c2[i] == 0) {
                bb = 0;
            }
        }
        if (bb == 1) {
            way.clear();
            way.push_back(0);
            way.push_back(t[0].cld[0]);
            way.push_back(0);
            way.push_back(t[0].cld[0]);
        }
        else {
            way.pop_back();
        }
    }
    for (i = 0; i<way.size(); i++) {
        cout << way[i] + 1 << " ";
    }
    return 0;
}