#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 222222, sd = 100111, inf = 1011111111;

int n, w, h, ansx[max_n], ansy[max_n], tp[max_n], t[max_n], x[max_n];
vector<int> all[2][max_n];

bool cmp(int a, int b) {
    return x[a] < x[b];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &w, &h);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &tp[i], &x[i], &t[i]);
        --tp[i];
        all[tp[i]][t[i] - x[i] + sd].push_back(i);
    }
    for (int i = 0; i < max_n; ++i) {
        //if (all[0][i].size() && all[1][i].size()) {
        if (all[0][i].size() || all[1][i].size()) {
            sort(all[0][i].begin(), all[0][i].end(), cmp);
            sort(all[1][i].begin(), all[1][i].end(), cmp);
            vector<int> v = all[1][i];
            queue<int> q;
            int cnt = 0;
            for (int j = 0; j < all[0][i].size(); ++j) {
                if (v.size()) {
                    int last = v.back();
                    v.pop_back();
                    ansx[last] = x[all[0][i][j]];
                    ansy[last] = h;
                    q.push(all[0][i][j]);
                } else if (q.size()) {
                    int last = q.front();
                    q.pop();
                    ansx[last] = x[all[0][i][j]];
                    ansy[last] = h;
                    q.push(all[0][i][j]);
                } else {
                    ansx[all[0][i][j]] = x[all[0][i][j]];
                    ansy[all[0][i][j]] = h;
                }
            }
            cnt = all[1][i].size() - 1;
            while (v.size()) {
                int num = v.back();
                v.pop_back();
                ansy[num] = x[all[1][i][cnt]];
                ansx[num] = w;
                --cnt;
            }
            while (q.size()) {
                int num = q.front();
                q.pop();
                ansy[num] = x[all[1][i][cnt]];
                ansx[num] = w;
                --cnt;
            }
        } else {
            /*for (int j = 0; j < all[0][i].size(); ++j) {
                ansx[all[0][i][j]] = x[all[0][i][j]];
                ansy[all[0][i][j]] = h;
            }
            for (int j = 0; j < all[1][i].size(); ++j) {
                ansx[all[1][i][j]] = w;
                ansy[all[1][i][j]] = x[all[1][i][j]];
            }*/
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", ansx[i], ansy[i]);
    }
    return 0;
}