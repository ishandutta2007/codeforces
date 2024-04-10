#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int maxn = 1e5+100;
char s[maxn];
int n;
/*
 * char* 1-bas
 * sum[i] = s[i]+s[i-1]*Seed+s[i-2]*Seed^2+...+s[1]*Seed^(i-1)
 */
ULL Seed_Pool[]={911,146527,19260817,91815541};
ULL Mod_Pool[]={29123,998244353,1000000009,4294967291ull};
struct Hash_1D{
    ULL Seed,Mod;
    ULL bas[maxn];
    ULL sum[maxn];
    void init(int seedIndex,int modIndex){
        Seed = Seed_Pool[seedIndex];
        Mod = Mod_Pool[modIndex];
        bas[0]=1;
        for (int i=1;i<=n;i++){
            bas[i] = bas[i-1]*Seed%Mod;
        }
        for (int i=1;i<=n;i++){
            sum[i] = (sum[i-1]*Seed%Mod+s[i])%Mod;
        }
    }
    ULL getHash(int l,int r){
        return (sum[r]-sum[l-1]*bas[r-l+1]%Mod+Mod)%Mod;
    }
}hasher;
map<ULL,pair<int,int> > ID[maxn];
vector<int> pos[maxn];
int ans[maxn];
char t[maxn];
int main(){
    scanf("%s",s+1);
    n = strlen(s+1);
    hasher.init(1,1);
    memset(ans,0x3f3f3f3f,sizeof ans);
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        int k;
        scanf("%d%s",&k,t+1);
        int len = strlen(t+1);
        ULL hash_val =0;
        for (int i=1;i<=len;i++){
            hash_val = (hash_val * Seed_Pool[1] % Mod_Pool[1]+ t[i])%Mod_Pool[1];
        }
        assert(ID[len].find(hash_val) == ID[len].end());
        ID[len][hash_val] = {k,i};
    }
    for (int block = 1;block<=n;block++){
        if (ID[block].empty())continue;
        for (int st = 1,ed = block;ed <=n;st++,ed++){
            ULL hash_val = hasher.getHash(st,ed);
            if (ID[block].find(hash_val) == ID[block].end())continue;
            auto pr  = ID[block][hash_val];
            int k = pr.first,id = pr.second;
            pos[id].push_back(st);
            if (pos[id].size() >=k){
                ans[id] = min(ans[id],st - pos[id][pos[id].size()-k]+block);
            }
        }
    }
    for (int i=1;i<=m;i++){
        printf("%d\n",ans[i] == 0x3f3f3f3f?-1:ans[i]);
    }
    return 0;
}