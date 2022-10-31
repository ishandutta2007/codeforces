#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int maxn = 2e6+100;
char s[maxn*2];
int n,m,k;
char t[maxn];
map<pair<ULL,ULL>,int>ID;
const int HASH_CNT = 2;
ULL Seed_Pool[]={19260817,91815541};
ULL Mod_Pool[]={1000000009,4294967291ull};
struct Hash_1D{
    ULL Seed,Mod;
    ULL bas[maxn];
    ULL sum[maxn];
    void init(int seedIndex,int modIndex){
        Seed = Seed_Pool[seedIndex];
        Mod = Mod_Pool[modIndex];
        bas[0]=1;
        for (int i=1;i<=2*k*n;i++){
            bas[i] = bas[i-1]*Seed%Mod;
        }
        for (int i=1;i<=2*k*n;i++){
            sum[i] = (sum[i-1]*Seed%Mod+s[i])%Mod;
        }
    }
    ULL getHash(int l,int r){
        return (sum[r]-sum[l-1]*bas[r-l+1]%Mod+Mod)%Mod;
    }
}hasher[HASH_CNT];
ULL tmp[HASH_CNT];
int cnt[maxn];
int Cnt;
inline void add(int i){
    cnt[i] ++;
    Cnt += (cnt[i] == 1);
}
inline void del(int i){
    cnt[i] --;
    Cnt -= (cnt[i] == 0);
}
inline int get_id(int l,int r){
    ULL hash_val1 = hasher[0].getHash(l,r);
    ULL hash_val2 = hasher[1].getHash(l,r);
    int id = 0;
    if (ID.find({hash_val1,hash_val2}) != ID.end()){
        id = ID[{hash_val1,hash_val2}];
    }
    return id;
}
void check(int st_pos){
    //printf("succ at :%d\n",st_pos);
    if (Cnt == n && cnt[0] == 0){
        puts("YES");
        for (int i=0;i<n;i++){
            int l = st_pos + k*i;
            int r = l + k-1;
            int id = get_id(l,r);
            assert(id);
            printf("%d ",id);
        }
        puts("");
        exit(0);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for (int i=0;i<k*n;i++){
        s[i+k*n+1] = s[i+1];
    }
    for (int i=0;i<HASH_CNT;i++){
        hasher[i].init(i,i);
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        scanf("%s",t+1);
        for (int j=0;j<HASH_CNT;j++){
            tmp[j] = 0;
            for (int l=1;l<=k;l++){
                tmp[j] = (tmp[j]*hasher[j].Seed %hasher[j].Mod+ t[l])%hasher[j].Mod;
            }
        }
        assert(ID.find({tmp[0],tmp[1]}) == ID.end());
        ID[{tmp[0],tmp[1]}] = i;
    }
    for (int st = 1;st<=k;st++){
        for (int i=0;i<n;i++){
            int l = st + i * k;
            int r =  l+k-1;
            int id = get_id(l,r);
            add(id);
        }
        check(st);
        for (int i=0;i<n-1;i++){
            int l = st + i*k;
            int r = l +k-1;
            int id = get_id(l,r);
            del(id);
            l += n*k;
            r += n*k;
            id = get_id(l,r);
            add(id);
            check(st+ k);
        }
        for (int i=0;i<n;i++){
            int l = st + (n-1) * k + i*k;
            int r = l + k-1;
            int id = get_id(l,r);
            del(id);
        }
    }
    puts("NO");
    return 0;
}