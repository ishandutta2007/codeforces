#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#define maxn 600009
using namespace std;
struct node{
    int l, r, id;
    bool operator < (const node &rhs)const{
        return l < rhs.l || (l == rhs.l && r > rhs.r);
    }
}a[maxn];
int X[maxn], b[maxn];
map<int,int> mp;
int n, m, tot;
int ans, ansl, ansr;
void update(int x, int val){
    while(x < maxn){
        b[x] += val;
        x += x & -x;
    }
}
int getsum(int x){
    int sum = 0;
    while(x > 0){
        sum += b[x];
        x -= x & -x;
    }
    return sum;
}
int biger(int x){
    x = mp[x];
    return getsum(maxn - 1) - getsum(x - 1);
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        a[i].l = l;
        a[i].r = r;
        a[i].id = i;
        X[tot++] = l;
        X[tot++] = r;
    }
    sort(X, X + tot);
    tot = unique(X, X + tot) - X;
    for(int i = 0; i < tot; i++){
        mp[X[i]] = i + 1;
    }
    sort(a, a + n);
    int p = 0;
    int l = 0, r = 0;
    while(p < n && a[p].l <= X[l]){
        update(mp[a[p].r], 1);
        p++;
    }
    if(biger(X[r]) >= m){
        ans = X[r] - X[l] + 1;
        ansl = X[l];
        ansr = X[r];
    }
    while(l < tot){
        r = max(r, l);
        while(r + 1 < tot && biger(X[r + 1]) >= m)
            r++;
        if(biger(X[r]) >= m){
            if(ans < X[r] - X[l] + 1){
                ans = X[r] - X[l] + 1;
                ansl = X[l];
                ansr = X[r];
            }
        }
        l++;
        if(l >= tot) break;
        while(p < n && a[p].l <= X[l]){
            update(mp[a[p].r], 1);
            p++;
        }
    }
    if(ans == 0){
        printf("%d\n", ans);
        for(int i = 1; i <= m ; i++)
            printf("%d ",i);
    }
    else{
        printf("%d\n", ans);
        int cnt = 0;
        for(int i = 0; i <= n; i++){
            if(a[i].l <= ansl && ansr <= a[i].r && cnt < m){
                cnt++;
                printf("%d ", a[i].id + 1);
            }
        }
    }
    return 0;
}