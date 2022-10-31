#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int maxn = 3e5+100;
map<int,set<pair<ULL,ULL>>> cnt;
ULL Seed_Pool[]={911,146527,19260817,91815541};
ULL Mod_Pool[]={29123,998244353,1000000009,4294967291ull};
ULL bas[4][4][maxn];
struct Hash_1D{
    ULL Seed,Mod;
    ULL sum[maxn];
    void init(int seedIndex,int modIndex,const char *s,int n){
        Seed = seedIndex;
        Mod = modIndex;
        for (int i=1;i<=n;i++){
            sum[i] = (sum[i-1]*Seed_Pool[Seed]%Mod_Pool[Mod]+s[i])%Mod_Pool[Mod];
        }
    }
    ULL getHash(int l,int r){
        return (sum[r]-sum[l-1]*bas[Seed][Mod][r-l+1]%Mod_Pool[Mod]+Mod_Pool[Mod])%Mod_Pool[Mod];
    }
}hasher[2];
char s[maxn];
int main(){
    for (int i=0;i<4;i++)for (int j=0;j<4;j++){
        bas[i][j][0] = 1;
        for (int k=1;k<maxn;k++)bas[i][j][k] = bas[i][j][k-1]*Seed_Pool[i] % Mod_Pool[j];
    }
    int T;
    for (scanf("%d",&T);T;T--){
        int op;
        scanf("%d%s",&op,s+1);
        int n = strlen(s+1);
        hasher[0].init(2,1,s,n);
        hasher[1].init(2,2,s,n);
        if (op == 1){
            cnt[n].insert({hasher[0].getHash(1,n),hasher[1].getHash(1,n)});
        }else if (op == 2){
            cnt[n].erase({hasher[0].getHash(1,n),hasher[1].getHash(1,n)});
        }else{
            int ans =0;
            for (auto &pr : cnt){
                int len = pr.first;
                auto & Set = pr.second;
                for (int i=1;i + len -1 <= n;i++){
                    ULL hval1 = hasher[0].getHash(i,i+ len - 1);
                    ULL hval2 = hasher[1].getHash(i,i + len - 1);
                    ans += Set.count({hval1,hval2});
                }
            }
            printf("%d\n",ans);
            fflush(stdout);
        }
    }
    return 0;
}