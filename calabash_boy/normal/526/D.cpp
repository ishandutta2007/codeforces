#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int maxn = 1e6+100;
const int HASH_CNT = 2;
char s[maxn];
/*
 * char* 1-bas
 * sum[i] = s[i]+s[i-1]*Seed+s[i-2]*Seed^2+...+s[1]*Seed^(i-1)
 */
ULL Seed_Pool[]={19260817,91815541};
ULL Mod_Pool[]={1000000009,4294967291ull};
int n,k;
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
}hasher[HASH_CNT];
int sum[maxn];
inline void add(int l,int r){
    sum[l]++;sum[r+1]--;
}
bool check(int st1,int st2,int len){
    if (st1 + len-1 >n || st2 + len-1>n)return false;
    for (int i=0;i<HASH_CNT;i++){
        ULL hash_val1 = hasher[i].getHash(st1,st1+len-1);
        ULL hash_val2 = hasher[i].getHash(st2,st2+len-1);
        if (hash_val1 != hash_val2)return false;
    }
    return true;
}
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);

    for (int i=0;i<HASH_CNT;i++){
        hasher[i].init(i,i);
    }
    for (int len = 1;len <=n;len ++){
        //cout<<len<<endl;
        int Len = len * k;
        if (Len >n)break;
        ULL hash_val1 = hasher[0].getHash(1,len);
        ULL hash_val2 = hasher[1].getHash(1,len);
        bool succ = true;
        for (int j=1;j<k;j++){
            int l = len *j+1;
            int r = l+len-1;
            ULL temp_val1 = hasher[0].getHash(l,r);
            ULL temp_val2 = hasher[1].getHash(l,r);
            if (temp_val1 != hash_val1 || temp_val2 != hash_val2){
                succ = false;
                break;
            }
        }
        if (!succ)continue;
        int L = 0;
        int st = Len +1;
        add(Len,Len);
        int R = len;
        while (R-L>1){
            int Mid = L+R>>1;
            if (check(1,st,Mid)){
                L = Mid;
            }else{
                R = Mid;
            }
        }
        int LEN = check(1,st,R)?R:L;
        add(st,st+LEN-1);
    }
    for (int i=1;i<=n;i++){
        sum[i] += sum[i-1];
        if (sum[i]){
            printf("1");
        }else{
            printf("0");
        }
    }
    return 0;
}