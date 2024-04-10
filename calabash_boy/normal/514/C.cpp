//
// Created by calabash_boy on 18-10-18.
//
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[91m[%s %3d]: " fmt "\n\033[0m", \
  __func__,__LINE__, ##__VA_ARGS__)
#else
# define _debug(...) (void(0))
#endif

typedef unsigned long long ULL;

/************* header ******************/
const int maxn = 6e5+100;
const ULL Seed = 146527;
const ULL Mod = 998244353;
const ULL Mod2 = 1000000009;
ULL bas[maxn];
ULL bas2[maxn];
set<pair<ULL,ULL> >S[maxn];
int n,m;
char s[maxn];
void solve(){
    scanf("%s",s);
    int len = strlen(s);
    ULL hash_val = 0,hash_val2 = 0;
    for (int i=0;i<len;i++){
        hash_val = (hash_val * Seed % Mod + s[i] - 'a' +1)%Mod;
        hash_val2 = (hash_val2 * Seed % Mod2 + s[i] - 'a' +1)%Mod2;
    }
    for (int i=0;i<len;i++){
        for (int ch='a';ch<='c';ch++){
            if (ch == s[i])continue;
            ULL true_val = (hash_val + (-s[i] + ch+Mod)%Mod * bas[len-1-i] % Mod + Mod) % Mod;
            ULL true_val2 = (hash_val2 + (-s[i] + ch + Mod2)% Mod2 * bas2[len-1-i] % Mod2 + Mod2)% Mod2;
            if (S[len].find({true_val,true_val2}) != S[len].end()){
                puts("YES");
                return;
            }
        }
    }
    puts("NO");
}
int main(){
    bas[0] = 1,bas2[0] = 1;
    for (int i=1;i<maxn;i++){
        bas[i] = bas[i-1] * Seed %Mod;
        bas2[i] = bas2[i-1] * Seed %Mod2;
    }
    scanf("%d%d",&n,&m);
    for (int o=0;o<n;o++){
        scanf("%s",s);
        int len = strlen(s);
        ULL hash_val = 0,hash_val2 = 0;
        for (int i=0;i<len;i++){
            hash_val = (hash_val * Seed % Mod + s[i] - 'a' +1)%Mod;
            hash_val2 = (hash_val2 * Seed %Mod2 + s[i] - 'a' + 1)%Mod2;
        }
        S[len].insert({hash_val,hash_val2});
    }
    while (m--){
        solve();
    }
    return 0;
}