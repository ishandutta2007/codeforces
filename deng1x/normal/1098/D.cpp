#include<bits/stdc++.h>

typedef long long ll;

const int N = 500010;

ll c[N];
int uni[N];
int type[N], x[N];
char s[N];

void add(int sit, int value){
    for (++ sit; sit < N; sit += sit & -sit){
        c[sit] += value;
    }
}

ll query(int sit){
    ll ret = 0;
    for (++ sit; sit; sit -= sit & -sit){
        ret += c[sit];
    }
    return ret;
}

int main(){
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++ i){
        scanf("%s%d", s, &x[i]);
        type[i] = s[0] == '+';
        uni[i] = x[i];
    }
    std::sort(uni, uni + q);
    int cnt = std::unique(uni, uni + q) - uni;
    std::multiset <ll> set;
    for (int i = 0; i < q; ++ i){
        int sit = std::lower_bound(uni, uni + cnt,  x[i]) - uni;
        add(sit, (type[i] ? 1 : -1) * x[i]);
        if (type[i]){
            set.insert(x[i]);
        }
        else{
            auto u = set.find(x[i]);
            set.erase(u);
        }
        if (set.empty()){
            puts("0");
            continue;
        }
        auto u = set.begin();
        int ans = 0;
        while (true){
            int sit = std::lower_bound(uni, uni + cnt, *u) - uni;
            ll now = query(sit);
            auto v = set.upper_bound(2 * now);
            if (v == set.end()){
                break;
            }
            auto w = v;
            -- w;
            if (*w == *u){
                ++ ans;
                u = v;
            }
            else{
                u = w;
            }
        }
        printf("%d\n", (int) set.size() - 1 - ans);
    }
    return 0;
}