#pragma GCC optimize(3)
#include<bits/stdc++.h>
typedef long long ll;
#define int ll
using namespace std;
const int maxn = 1e6+100;
struct Q{
    int l,r,id;
};
vector<Q> query;
struct BIT{
    int sum[maxn];
    int lowbit(int x){
        return x & (-x);
    }
    void add(int x,int val){
        while (x<maxn){
            sum[x] ^= val;
            x += lowbit(x);
        }
    }
    int query(int x){
        int ans = 0;
        while (x){
            ans ^= sum[x];
            x -= lowbit(x);
        }
        return ans;
    }
    int query(int l,int r){
        return query(r) ^ query(l-1);
    }
}bit;
int n,m;
vector<int> ID;
int last[maxn];
int a[maxn];
int sum[maxn];
int ans[maxn];
bool cmp(const Q &x,const Q &y){
    return x.r < y.r;
}
signed main(){
    int n,m;
    scanf("%lld",&n);
    for (int i=1;i<=n;i++){
        scanf("%lld",a+i);
        ID.push_back(a[i]);
    }
    sort(ID.begin(),ID.end());
    ID.erase(unique(ID.begin(),ID.end()),ID.end());
    for (int i=1;i<=n;i++){
        a[i] = lower_bound(ID.begin(),ID.end(),a[i]) - ID.begin();
    }
    scanf("%lld",&m);
    for (int i=1;i<=m;i++){
        int l,r;
        scanf("%lld%lld",&l,&r);
        query.push_back((Q){l,r,i});
    }
    sort(query.begin(),query.end(),cmp);
    for (int i=1,j=0;i<=n&&j<query.size();i++){

        int val = ID[a[i]];
        sum[i] = sum[i-1] ^ val;
        if (last[a[i]] == 0){
            bit.add(1,val);
            bit.add(i+1,val);
            last[a[i]] = i;
        }else{
            bit.add(last[a[i]]+1,val);
            bit.add(i+1,val);
            last[a[i]] = i;
        }
        while (j < query.size() && query[j].r == i){
            int l = query[j].l,r = query[j].r;
            int t = sum[r] ^ sum[l-1];
            int tt = bit.query(l);
            ans[query[j].id] = tt ^ t;
            j++;

        }
    }
    for (int i=1;i<=m;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}