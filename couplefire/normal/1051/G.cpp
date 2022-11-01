#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

const int N = 400005;
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

struct node{
    int pri, key;
    int siz; ll sum;
    node *l, *r;
    node(int kk){
        pri = rng(); key = kk;
        siz = 1; sum = kk;
        l = r = nullptr;
    }
};

int get_siz(node* x){return x?x->siz:0;}
ll get_sum(node* x){return x?x->sum:0ll;}

node* calc(node* x){
    if(!x) return x;
    x->siz = 1+get_siz(x->l)+get_siz(x->r);
    x->sum = x->key+get_sum(x->l)+get_sum(x->r);
    return x;
}

pair<node*, node*> split(node* x, int v){
    if(!x) return {x, x};
    if(x->key>=v){
        auto [a, b] = split(x->l, v); x->l = b;
        return {a, calc(x)};
    } else{
        auto [a, b] = split(x->r, v); x->r = a;
        return {calc(x), b};
    }
}

node* merge(node* a, node* b){
    if(!a || !b) return a?a:b;
    node* x;
    if(a->pri>b->pri)
        a->r = merge(a->r, b), x = a;
    else b->l = merge(a, b->l), x = b;
    return calc(x);
}

struct comp{
    node* root = nullptr;
    int smol; ll ans1 = 0, ans2 = 0;
    vector<pii> stuff;

    void ins(int bi){
        auto [a, b] = split(root, bi);
        ans2 += get_sum(a)+1ll*get_siz(b)*bi;
        root = merge(a, merge(new node(bi), b));
    }

    void fill(node* x){
        if(!x) return;
        ins(x->key);
        fill(x->l); fill(x->r);
    }
} comps[N];

void merge(comp& x, comp& y){
    if(x.stuff.size()<y.stuff.size())
        swap(x, y);
    if(x.smol<y.smol)
        x.ans1 += y.ans1+y.root->sum*(y.smol-x.smol);
    else x.ans1 += y.ans1+x.root->sum*(x.smol-y.smol);
    x.smol = min(x.smol, y.smol);
    x.fill(y.root); delete y.root;
    for(auto a : y.stuff)
        x.stuff.push_back(a);
    y.stuff.clear();
}

set<int> avail;
int fa[N]; ll ans;

int find(int x){
    return x==fa[x]?x:fa[x] = find(fa[x]);
}

void merge(int x, int y){
    x = find(x), y = find(y);
    if(x==y) return;
    if(comps[x].stuff.size()<comps[y].stuff.size())
        swap(x, y);
    fa[y] = x; 
    ans -= (comps[x].ans2-comps[x].ans1)+(comps[y].ans2-comps[y].ans1);
    merge(comps[x], comps[y]);
    ans += comps[x].ans2-comps[x].ans1;
}

void solve(int ai, int bi){
    int pos = *avail.lower_bound(ai);
    avail.erase(pos);
    comps[pos].smol = ai;
    comps[pos].stuff.push_back({ai, bi});
    comps[pos].ins(bi);
    if(!avail.count(pos-1))
        merge(pos-1, pos);
    if(!avail.count(pos+1))
        merge(pos, pos+1);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i = 0; i<N; ++i)
        avail.insert(i), fa[i] = i;
    for(int i = 0; i<n; ++i){
        int a, b; cin >> a >> b;
        solve(a, b);
        cout << ans << '\n';
    }
}