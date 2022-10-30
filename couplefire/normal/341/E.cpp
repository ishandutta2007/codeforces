#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000010;

struct node{
    int x, id;
} a[N], ans[N];

int anss;

bool cmp(node x, node y){
    if (x.x != y.x)
        return x.x > y.x;
    return x.id < y.id;
}

void solve(){
    int k = a[2].x / a[3].x;
    while (k){
        if (k & 1){
            a[2].x -= a[3].x;
            a[3].x <<= 1;
            ans[++anss].x = a[3].id;
            ans[anss].id = a[2].id;
        }
        else{
            a[1].x -= a[3].x;
            a[3].x <<= 1;
            ans[++anss].x = a[3].id;
            ans[anss].id = a[1].id;
        }
        k >>= 1;
    }
}

int n;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        a[i].id = i, scanf("%d", &a[i].x);
    sort(a + 1, a + n + 1, cmp);
    if (!a[2].x){
        puts("-1");
        return 0;
    }
    while (a[3].x){
        solve();
        sort(a + 1, a + n + 1, cmp);
    }
    printf("%d\n", anss);
    for (int i = 1; i <= anss; ++i)
        printf("%d %d\n", ans[i].x, ans[i].id);
    return 0;
}