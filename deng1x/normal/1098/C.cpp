#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

int a[N];

ll calc(int n, ll now, int dep, int k){
    ll ans = 0;
    while (n){
        ll x = std::min(now, (ll) n);
        a[dep] = x;
        ans += dep * x;
        ++ dep;
        n -= x;
        now *= k;
    }
    a[dep] = 0;
    return ans;
}

ll sum(int l, int r){
    return 1ll * (l + r) * (r - l + 1) / 2;
}

int main(){
    int n;
    ll s;
    scanf("%d%lld", &n, &s);
    if (s > calc(n, 1, 1, 1) || s < calc(n, 1, 1, n - 1)){
        puts("No");
        return 0;
    }
    puts("Yes");
    int deg;
    for (int i = 1; i < n; ++ i){
        if (calc(n, 1, 1, i) <= s){
            deg = i;
            break;
        }
    }
    ll now = calc(n, 1, 1, deg);
    int last;
    for (int i = 1; ; ++ i){
        if (!a[i]){
            last = i;
            break;
        }
    }
    for (int i = last; i < N; ++ i){
        a[i] = 0;
    }
    int pre = last - 1;
    while (true){
        if (a[pre] == 1){
            -- pre;
        }
        int diff = last - pre;
        if (now + diff > s){
            break;
        }
        -- a[pre];
        ++ a[last ++];
        now += diff;
    }
    -- a[pre];
    ++ a[pre + s - now];
    pre = 1;
    for (int i = 2; i < N; ++ i){
        for (int j = 0; j < a[i] / deg + 1; ++ j){
            for (int k = j * deg; k < std::min((j + 1) * deg, a[i]); ++ k){
                printf("%d ", pre + j); 
            }
        }
        pre += a[i - 1];
    }
    puts("");
    return 0;
}