#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;
const int LIM = 1000;

struct Fenwick{
    const int m = 300000;
    ll tree[300002];

    void init(){
        for(int i=0; i<=m; i++) tree[i] = 0;
    }

    inline void add(int x, ll y){
        while(x <= m){
            tree[x] += y;
            x += x&-x;
        }
    }

    inline ll sum(int x){
        ll ret = 0;
        while(x){
            ret += tree[x];
            x -= x&-x;
        }
        return ret;
    }
} tree1, tree2, tree3;

int n;
ll arr[200002];
ll cnt[300002];
ll weight[300002]; /// guideline
ll ans, gcnt;

int main(){
    scanf("%d", &n);
//    n=200000;
    for(register int i=1; i<=n; i++){
        scanf("%lld", &arr[i]);
//        arr[i] = abs(rand() * rand()) % 300000 + 1;

        if(arr[i] <= LIM) ans += weight[arr[i]], cnt[arr[i]]++;
        else{
            for(int j=1; j<=LIM; j++){
                if(cnt[j]) ans += cnt[j] * ((arr[i] % j) + j);
            }

            for(int j=1; arr[i]*j<=300000; j++){
                ll L = arr[i] * j, R = min(arr[i] * j + (arr[i] - 1), 300000LL);
                ans += tree1.sum(R) - tree1.sum(L-1);
                ans -= (tree2.sum(R) - tree2.sum(L-1)) * arr[i] * j;

                tree3.add(L, arr[i] * j);
                tree3.add(R+1, -arr[i] * j);
            }
            tree1.add(arr[i], arr[i]);
            tree2.add(arr[i], 1);
            gcnt++;

            ans += tree2.sum(arr[i]) * arr[i] - tree3.sum(arr[i]);
            ans += (gcnt - tree2.sum(arr[i])) * arr[i];
            ans += tree1.sum(arr[i]-1);
        }

        printf("%lld ", ans);
        for(int j=1; j<=LIM; j++){
            weight[j] += (arr[i] % j) + (j % arr[i]);
        }
    }
}