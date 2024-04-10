#include<bits/stdc++.h>
using namespace std;
int d[100000];
vector<int> e[100000];
int find(int x) {
    if(x != d[x]) return d[x] = find(d[x]);
    return x;
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    d[x] = y;
}
int dp[100000];
int answer[100000], id;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        d[i] = i;
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i = 0; i < n; i++) {
        sort(e[i].begin(),e[i].end());
        int lat = -1;
        for(int y: e[i]) {
            if(lat + 1 < y) {
                dp[lat + 1]++;
                dp[y - 1]--;
                join(i, lat + 1);
            }
            lat = y;
        }
        if(lat + 1 < n) {
            dp[lat + 1]++;
            dp[n - 1]--;
            join(i, lat + 1);
        }
    }
    for(int i = 0; i < n; i++) {
        if(i) dp[i] += dp[i - 1];
        if(dp[i]) {
            join(i, i + 1);
        }
    }
    for(int i = 0; i < n; i++) {
        if(find(i) == i) {
            answer[i] = ++id;
        }
    }
    if(id != 3) {
        puts("-1");
        return 0;
    }
    long long cnt[4] = {};
    for(int i = 0; i < n; i++) {
        answer[i] = answer[find(i)];
        cnt[answer[i]]++;
    }
    if(cnt[1] * cnt[2] + cnt[2] * cnt[3] + cnt[1] * cnt[3] != m) {
        puts("-1");
        return 0;
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    return 0;
}