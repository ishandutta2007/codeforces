#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
typedef vector<pair<int,int> > VE;
int num[11][maxn];
int n,m,q;
struct SegmentTree{
    //left 1-n, right n+1-2n
    VE edge[maxn*4];
    int ans[maxn*4];
    int fa[88];
    vector<int> nodes[88];
    int find(int x){
        return fa[x] == x?x:fa[x] = find(fa[x]);
    }
    void init_dsu(int N){
        for (int i=1;i<=N;i++){
            fa[i] = i;
        }
    }
    void merge(int u,int v){
        int fu = find(u);
        int fv = find(v);
        if (fu == fv)return;
        fa[fv] = fu;
    }
    int scc(const VE& E,int N){
        init_dsu(N);
        for (auto e : E){
            int u,v;
            tie(u,v) = e;
            merge(u,v);
        }
        int cnt = 0;
        for (int i=1;i<=N;i++){
            cnt += i == find(i);
        }
        return cnt;
    }
    pair<int,VE> merge(const VE &e1,const VE &e2,const VE &mid){
        init_dsu(4 * n);
        for (auto e : e1){
            int u,v;
            tie(u,v) = e;
            merge(u,v);
        }
        for (auto e : e2){
            int u,v;
            tie(u,v) = e;
            u += 2 * n;
            v += 2 * n;
            merge(u,v);
        }
        for (auto e : mid){
            int u,v;
            tie(u,v) = e;
            u += n;
            v += n;
            merge(u,v);
        }
        VE ret(0);
        for (int i=1;i<=n;i++){
            nodes[find(i)].push_back(i);
        }
        for (int i=3 * n + 1;i <= 4 * n;i ++){
            nodes[find(i)].push_back(i);
        }
        for (int i=1;i<=4 * n;i ++){
            if (nodes[i].size() == 1)nodes[i].clear();
            if (nodes[i].size() >=2){
                int root = nodes[i].back();
                nodes[i].pop_back();
                if (root >n)root -= 2 * n;
                while (!nodes[i].empty()){
                    int x = nodes[i].back();
                    nodes[i].pop_back();
                    if (x > n)x -= 2 * n;
                    ret.push_back(make_pair(root,x));
                }
            }
        }
        int cnt = 0;
        for (int i=1;i<=4 * n;i++){
            cnt += i == find(i);
        }
        return make_pair(cnt,ret);
    }
    void build(int x,int l,int r){
        if (l == r){
            init_dsu(2 * n);
            for (int i=1;i<=n;i++){
                edge[x].push_back(make_pair(i,i + n));
            }
            for (int i=2;i<=n;i++){
                if (num[i-1][r] == num[i][r])edge[x].push_back(make_pair(i, i-1));
            }
            ans[x] = scc(edge[x],2 * n);
            return;
        }
        int mid = l + r >> 1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        ans[x] = ans[x<<1] + ans[x<<1|1];
        ans[x] -= scc(edge[x<<1], 2 * n);
        ans[x] -= scc(edge[x<<1|1], 2 * n);
        VE temp(0);
        for (int i=1;i<=n;i++){
            if (num[i][mid] == num[i][mid+1]){
                temp.push_back(make_pair(i, i + n));
            }
        }
        auto t = merge(edge[x<<1],edge[x<<1|1],temp);
        edge[x] = t.second;
        ans[x] += t.first;
    }
    pair<int,VE> query(int x,int l,int r,int L,int R){
       // cerr<<l<<" "<<r<<endl;
        if (L <= l && r <= R)return make_pair(ans[x],edge[x]);
        int mid = l + r >> 1;
        if (L >= mid + 1)return query(x<<1|1,mid+1, r, L, R);
        if (R <= mid)return query(x<<1, l, mid, L, R);
        auto left = query(x<<1,l,mid,L,mid);
        auto right = query(x<<1|1,mid+1,r,mid+1,R);
        int ans = left.first + right.first;
        ans -= scc(left.second,2 * n);
        ans -= scc(right.second,2 * n);
        VE temp(0);
        for (int i=1;i<=n;i++){
            if (num[i][mid] == num[i][mid+1]){
                temp.push_back(make_pair(i, i + n));
            }
        }
        auto tt =merge(left.second, right.second, temp);
        ans += tt.first;
        return make_pair(ans,tt.second);
    }
}tree;
int read(){
    int ret = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')ch = getchar();
    while (ch >= '0' && ch <= '9')ret = ret * 10 + ch - '0',ch = getchar();
    return ret;
}
int main(){
    n = read();
    m = read();
    q = read();
    //scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            num[i][j] = read();
            //scanf("%d",&num[i][j]);
        }
    }
    tree.build(1, 1, m);
    while (q--){
        int l,r;
        l = read();
        r = read();
        //scanf("%d%d",&l,&r);
        printf("%d\n",tree.query(1,1,m,l,r).first);
    }
    return 0;
}