#include <bits/stdc++.h>
using namespace std;

const int N = 1<<19;

struct node{
    int ch[2], len, ans = N, lbd = -1, rbd = -1;
} tree[N<<1];

int n, k, res[N];

void pull(int v){
    tree[v].ans = min(tree[tree[v].ch[0]].ans, tree[tree[v].ch[1]].ans);
    if(tree[tree[v].ch[0]].rbd>=0 && tree[tree[v].ch[1]].lbd>=0)
        tree[v].ans = min(tree[v].ans, tree[tree[v].ch[1]].lbd+tree[tree[v].ch[0]].len-tree[tree[v].ch[0]].rbd);
    tree[v].lbd = tree[v].rbd = -1;
    if(tree[tree[v].ch[0]].lbd != -1)
        tree[v].lbd = tree[tree[v].ch[0]].lbd;
    else if(tree[tree[v].ch[1]].lbd != -1)
        tree[v].lbd = tree[tree[v].ch[1]].lbd+tree[tree[v].ch[0]].len;
    if(tree[tree[v].ch[1]].rbd != -1)
        tree[v].rbd = tree[tree[v].ch[1]].rbd+tree[tree[v].ch[0]].len;
    else if(tree[tree[v].ch[0]].rbd != -1)
        tree[v].rbd = tree[tree[v].ch[0]].rbd;
}

void upd(int v, int dep){
    if(dep) upd(tree[v].ch[0], dep-1), upd(tree[v].ch[1], dep-1), pull(v);
    else swap(tree[v].ch[0], tree[v].ch[1]), pull(v);
}

void solve(int x, int dep){
    if(dep == k) return void(res[x] = tree[1].ans);
    solve(x, dep+1); upd(1, k-1-dep); 
    solve(x+(1<<(dep)), dep+1); upd(1, k-1-dep);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i = (1<<k); i<(1<<(k+1)); ++i) tree[i].len = 1;
    for(int i = (1<<k)-1; i>=0; --i)
        tree[i].ch[0] = (i<<1), tree[i].ch[1] = (i<<1|1), tree[i].len = (tree[i<<1].len<<1);
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        tree[a+(1<<k)].lbd = tree[a+(1<<k)].rbd = 0;
        for(int v = (a+(1<<k))/2; v; v >>= 1) pull(v);
    }
    solve(0, 0);
    for(int i = 0; i<(1<<k); ++i)
        cout << res[i] << ' ';
    cout << '\n';
}