#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int SPECIAL_SIZE = 300;
int ee[200000];
vector<pair<int, int>>e[100000];
long long an = 0;
int n, m;
vector<int>bigs[100000];
int big_cnt[100000];
bool bigger[200000];
long long calc(int x) {
    return big_cnt[x] * (long long)(e[x].size() - big_cnt[x]);
}
void build() {
    for(int x = 0; x < n; x++) {
        for(int i = 0; i < (int)e[x].size(); i++) {
            int y = e[x][i].first;
            int eid = e[x][i].second;
            if(x < y) {
                bigger[eid] = 1;
                bigs[x].push_back(eid);
                big_cnt[x]++;
            }
        }
        an += calc(x);
    }
}
void change(int a) {
    an -= calc(a);
    for(int eid : bigs[a]) {
        int y = ee[eid];
        bigger[eid] = 0;
        bigger[eid ^ 1] = 1;
        bigs[y].push_back(eid ^ 1);
        an -= big_cnt[y];
        big_cnt[y]++;
        an += e[y].size() - big_cnt[y];
    }
    bigs[a].clear();
    big_cnt[a] = 0;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        ee[i * 2] = b;
        ee[i * 2 + 1] = a;
        e[a].push_back(make_pair(b,i * 2));
        e[b].push_back(make_pair(a,i * 2 + 1));
    }
    build();
    printf("%lld\n", an);
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        int a;
        scanf("%d", &a);
        a--;
        change(a);
        printf("%lld\n", an);
    }
    return 0;
}