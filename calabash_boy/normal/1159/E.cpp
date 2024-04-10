#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
int T;
int n;
int nxt[maxn];
struct segTree{
    int max_val[maxn*4];
    void build(int x,int l,int r){
        if (l == r){
            max_val[x] = nxt[l];
            return;
        }
        int mid = l + r >> 1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        up(x);
    }
    void up(int x){
        max_val[x] = max(max_val[x<<1],max_val[x<<1|1]);
    }
    int query(int x,int l,int r,int L,int R){
        if (l > R || L > r)return -1;
        if (L <= l && r <= R)return max_val[x];
        int mid = l + r >> 1;
        return max(query(x<<1,l,mid,L,R),query(x<<1|1,mid+1,r,L,R));
    }
}tree;
bool check_legal(){
    for (int i=1;i<=n;i++){
        if (nxt[i] == -1)continue;
        int l = i+1;
        int r = nxt[i]-1;
        if (l >r)continue;
        int R = tree.query(1,1,n,l,r);
        if (R > nxt[i])return false;
    }
    return true;
}
int ans[maxn];
int now;
void gao(int l,int r){
    if (l > r)return;

    vector<int> pos;
    int temp = l;
    while (temp <=r){
        pos.push_back(temp);
        int NXT = nxt[temp];
        if (NXT == -1){
            NXT = r+ 1;
        }
        temp = NXT;
    }
    //cerr<<l<<" "<<r<<endl;
    //cerr<<"pos : ";
    //for (int x : pos){
    //    cerr<<x<<" ";
    //}
    //cerr<<endl;
    for (int i=pos.size()-1;i>=0;i--){
        ans[pos[i]] = now--;
    }
    gao(l+1,pos[0]);
    for (int i=1;i<pos.size();i++){
        gao(pos[i-1] + 1,pos[i] - 1);
    }
    gao(pos.back() + 1,r);
}
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%d",nxt+i);
        }
        tree.build(1,1,n);
        if (!check_legal()){
            puts("-1");
            continue;
        }
        for (int i=1;i<=n;i++){
            ans[i] = -1;
        }
        now = n;
        gao(1,n);
        for (int i=1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        puts("");
    }
    return 0;
}