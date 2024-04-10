#include<bits/stdc++.h>
using namespace std;
const int MN = 500+3;
#define eb emplace_back
vector<pair<int,int>> graph;
int main() {
    int k;
    scanf ("%d",&k);
    if (k == 1) return !printf ("YES\n2 1\n1 2\n");
    if (!(k&1)) return !printf ("NO\n");
    printf ("YES\n");
    int cur = 1;
    for (int i = 1; i <= k; i++) {
        graph.eb(1,++cur);
        int rut = cur, ret = ++cur;
        int st = cur;
        for (int i = 1; i < k; i++) {
            graph.eb(rut,++cur);
            for (int j = i-1; j > 0; j--) if (i-j>1||(i&1)) graph.eb(cur,cur-i+j);
            graph.eb(cur,ret);
        }
        graph.eb(ret,++cur);
        ret=cur;
        for (int i = 1; i < k; i++) {
            graph.eb(ret,++cur);
            for (int j = i-1; j > 0; j--) graph.eb(cur,cur-i+j);
            graph.eb(st+i,cur);
        }
    }

    printf ("%d %d\n",cur,graph.size());
    assert(graph.size() <= 1000000);
    for (auto &a : graph) {
        printf ("%d %d\n",a.first,a.second);
    }
    return 0;
}