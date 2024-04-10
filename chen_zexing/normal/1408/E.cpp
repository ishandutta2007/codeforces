#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
struct edge{
    int a,b,w;
};
bool cmp(edge a,edge b){
    return a.w>b.w;
}
vector <edge> v;
int n,m,a[100005],b[100005],s[100005],fa[200005];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int main() {
    long long ans = 0, sum = 0;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= m + n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &s[i]);
        int t;
        for (int j = 1; j <= s[i]; j++) {
            scanf("%d", &t);
            v.push_back(edge{t, i + n, a[i] + b[t]});
            ans += a[i] + b[t];
        }
    }
    sort(v.begin(), v.end(), cmp);
    int sz = 0, now = 0;
    while (sz < m + n && now < v.size()) {
        if (find(v[now].a) != find(v[now].b)) {
            fa[fa[v[now].b]] = fa[v[now].a];
            sz++;
            sum += v[now].w;
        }
        now++;
    }
    cout << ans - sum << endl;
    return 0;
}