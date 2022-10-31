#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
typedef unsigned long long ULL;
const int HASH_CNT = 2;
vector<int> ID;
vector<int> pos[maxn];
int n;
int a[maxn];

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
        for (int i=1;i<=n;i++){
            bas[i] = bas[i-1]*Seed%Mod;
        }
        for (int i=1;i<=n;i++){
            sum[i] = (sum[i-1]*Seed%Mod+a[i])%Mod;
        }
    }

    ULL getHash(int l,int r){
        return (sum[r]-sum[l-1]*bas[r-l+1]%Mod+Mod)%Mod;
    }
}hasher[HASH_CNT];
vector<pair<int,int> >check_list(0);
bool check(int st1,int st2,int len){
    if (st1+len-1 >n || st2+len-1>n)return false;
    for (int i=0;i<HASH_CNT;i++){
        ULL hash_val1 = hasher[i].getHash(st1,st1+len-1);
        ULL hash_val2 = hasher[i].getHash(st2,st2+len-1);
        if (hash_val1 != hash_val2)return false;
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
        ID.push_back(a[i]);
    }
    sort(ID.begin(),ID.end());
    ID.erase(unique(ID.begin(),ID.end()),ID.end());
    for (int i=1;i<=n;i++){
        a[i] = lower_bound(ID.begin(),ID.end(),a[i]) - ID.begin()+1;
        pos[a[i]].push_back(i);
    }
    for (int i=0;i<HASH_CNT;i++){
        hasher[i].init(i,i);
    }
    for (int i=1;i<=(int)ID.size();i++){
        for (int j=0;j<pos[i].size();j++){
            for (int k=j+1;k<pos[i].size();k++){
                int l = pos[i][j];
                int r = pos[i][k];
                int len = r-l;
                if (check(l,r,len))check_list.push_back({l,len});
            }
        }
    }
    sort(check_list.begin(),check_list.end(),[](const pair<int,int> &a,
            const pair<int,int> &b){
       return a.second != b.second?a.second < b.second:a.first < b.first;
    });
    int now = 1;
    for (pair<int,int> & pr : check_list){
        if (pr.first < now)continue;
        now = pr.first+pr.second;
    }
    printf("%d\n",n-now+1);
    for (int i=now;i<=n;i++){
        printf("%d ",ID[a[i]-1]);
    }
    return 0;
}