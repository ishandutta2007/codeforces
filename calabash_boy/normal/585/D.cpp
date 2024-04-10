#include <bits/stdc++.h>
using namespace std;
const int maxn = 25+2;
typedef long long ll;
map<pair<int,int> ,pair<int,int> > mp;
map<pair<int,int> , pair<int,int> > mp2;
int n;
ll bas[maxn];
tuple<int,int,int> a[maxn];
void gao(int L,int R,map<pair<int,int>,pair<int,int> > & mp){
    int m = R - L;
    for (int i=0;i<bas[m];i++){
        int mask = i;
        int idx = L;
        int sum_u = 0,sum_v = 0,sum_w = 0;
        for (int j=0;j<m;j++,idx++){
            int u,v,w;
            tie(u,v,w) = a[idx];
            int dig = mask % 3;
            mask /= 3;
            sum_u += u;
            sum_v += v;
            sum_w += w;
            if (dig == 0){
                sum_u -= u;
            }else if (dig == 1){
                sum_v -= v;
            }else if (dig == 2){
                sum_w -= w;
            }else assert(0);
        }
        sum_v -= sum_u;
        sum_w -= sum_u;
        auto key = make_pair(sum_v,sum_w);
        if (mp.find(key) == mp.end()){
            mp[key] = make_pair(sum_u,i);
        }else{
            int mask,pre_u;
            tie(pre_u,mask) = mp[key];
            if (sum_u > pre_u){
                mp[key] = make_pair(sum_u,i);
            }
        }
    }
}
void output(int mask,int n){
    for (int i=0;i<n;i++){
        int dig = mask % 3;
        mask /= 3;
        if (dig == 0){
            puts("MW");
        }else if (dig == 1){
            puts("LW");
        }else if (dig == 2){
            puts("LM");
        }else assert(0);
    }
}
int main(){
    bas[0] = 1;
    for (int i=1;i<maxn;i++){
        bas[i] = bas[i-1] * 3;
    }
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[i] = make_tuple(u,v,w);
    }
    int limit = min(13,n);
    gao(0,limit,mp);
    if (n > 13)
        gao(limit,n,mp2);
    if (n <= 13){
        auto key = make_pair(0,0);
        if (mp.find(key) == mp.end())puts("Impossible");
        else output(mp[key].second,min(13,n));
    }else{
        pair<int,int> ans_mask = {-1,-1};
        int ans = -25 * 10000001;
        for (auto key : mp){
            int u,v,w,mask1;
            tie(v,w) = key.first;
            tie(u,mask1) = key.second;
            auto key2 = make_pair(-v,-w);
            if (mp2.find(key2) == mp2.end())continue;
            int u2,mask2;
            tie(u2,mask2) = mp2[key2];
            u += u2;
            if (u > ans){
                ans = u;
                ans_mask = {mask1,mask2};
            }
        }
        if (ans_mask.first == -1)puts("Impossible");
        else{
            output(ans_mask.first,13);
            output(ans_mask.second,n-13);
        }
    }
    return 0;
}