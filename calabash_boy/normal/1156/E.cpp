#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int n;
int p[maxn];
int pos[maxn];
struct Segment_Tree{
    int max_val[maxn*4];
    void build(int x,int l,int r){
        if (l == r){
            max_val[x] = p[l];
            return ;
        }
        int mid = l + r >> 1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        max_val[x] = max(max_val[x<<1],max_val[x<<1|1]);
    }
    int query(int x,int l,int r,int L,int R){
        if (l > R || L > r)return 0;
        if (L <= l && r <= R)return max_val[x];
        int mid = l + r >> 1;
        return max(query(x<<1,l,mid,L,R),query(x<<1|1,mid+1,r,L,R));
    }
}tree;
int gaol(int x){
    int val = p[x];
    int l = 1;
    int r = x;
    while (r-l>1){
        int mid = l + r >> 1;
        int max_val = tree.query(1,1,n,mid,x);
        if (max_val == val){
            r = mid;
        }else{
            l = mid;
        }
    }
    int max_val = tree.query(1,1,n,l,x);
    if (max_val == val)return l;
    else return r;
}
int gaor(int x){
    int val = p[x];
    int l = x;
    int r = n;
    while (r-l>1){
        int mid = l + r >> 1;
        int max_val = tree.query(1,1,n,x,mid);
        if (max_val == val){
            l = mid;
        }else{
            r = mid;
        }
    }
    int max_val = tree.query(1,1,n,x,r);
    if (max_val == val)return r;
    else return l;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",p+i);
        pos[p[i]] = i;
    }
    tree.build(1,1,n);
    int ans = 0;
    for (int i=1;i<=n;i++){
        int ai = p[i];
        int l = gaol(i);
        int r = gaor(i);
        if (i-l < r-i){
            for (int j=l;j<i;j++){
                int other = p[i] - p[j];
                if (other <=0 || other > n)continue;
                ans += pos[other] >i && pos[other] <=r;
            }
        }else{
            for (int j=i+1;j<=r;j++){
                int other = p[i] - p[j];
                if (other <=0 || other > n)continue;
                ans += pos[other] <i && pos[other] >=l;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}