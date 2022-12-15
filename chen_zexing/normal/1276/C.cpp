#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[400005],b[400005],cnt[400005],cccnt[400005],tot[400005];
vector <int> v[400005];
vector <int> u;
int id[400005];
bool cmp(int a,int b){
    return cnt[a]>cnt[b];
}
int main() {
    int T = 1;
    //cin>>T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b, cnt[a[i]]++;
        for (int i = 1; i <= n; i++) cccnt[cnt[i]]++,id[i]=i;
        tot[n] = n;
        int now = 0;
        for (int i = n - 1; i >= 1; i--) now += cccnt[i + 1], tot[i] = tot[i + 1] - now;
        int mx = 0;
        for (int i = 1; i <= n; i++) mx = max(mx, cnt[i]);
        int x, y, ans = 0;
        for (int i = 1; i <= n; i++) {
            int t = tot[i] / i;
            //cout<<t<<endl;
            if (t < min(i, mx)) continue;
            if (ans < i * t) ans = i * t, x = i, y = t;
        }
        printf("%d\n%d %d\n", ans, x, y);
        sort(id+1,id+n+1,cmp);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= min(cnt[id[i]], x); j++)
                u.push_back(b[id[i]]);
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                v[i].push_back(0);
        for (int i = 0; i < ans; i++) {
            int xx = i % x, yy = (i / x + xx) % y;
            v[xx][yy] = u[i];
        }
        for (int i = 0; i < x; i++, puts(""))
            for (int j = 0; j < y; j++)
                printf("%d ", v[i][j]);
    }
    return 0;
}