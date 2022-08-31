#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

struct node{
    node*l, *r;
    int val;
    node():l(0), r(0), val(0){}
    node(node*_l, node*_r, int v):l(_l), r(_r), val(v){}
};
vector<node*> trees;

node* pers_insert(node*c, int a, int b, int const&l){
    if(l<a || l>b) return c;
    if(c == 0) c = new node(0, 0, 0);
    else c = new node(c->l, c->r, c->val);
    ++c->val;
    if(a==b) return c;
    c->l = pers_insert(c->l, a, (a+b)/2, l);
    c->r = pers_insert(c->r, (a+b)/2+1, b, l);
    return c;
}
int pers_query(node*c, int a, int b, int const&l, int const&r){
    if(r<a || b<l) return 0;
    if(!c) return 0;
    if(l<=a && b<=r) return c->val;
    return pers_query(c->l, a, (a+b)/2, l, r) + pers_query(c->r, (a+b)/2+1, b, l, r);
}
// [x1, x2] x [y1, y2]
int rec_query(int x1, int x2, int y1, int y2){
    //cerr << "q: [" << x1 << "," << x2 << "] x [" << y1 << "," << y2 << "]\n";
    int n = (int)trees.size()-1;
    if(x1<0) x1 = 0;
    if(x2<0) x2 = 0;
    if(x2>=n) x2 = n-1;
    if(x1>n) x1 = n;
    //cerr << "-> [" << x1 << "," << x2+1 << "] x [" << y1 << "," << y2 << "]\n";
    int ret = pers_query(trees[x2+1], 0, n-1, y1, y2) - pers_query(trees[x1], 0, n-1, y1, y2);
    //cerr << "->" << ret << "\n";
    return ret;
}

void build(int n, vector<int> const&pts){
    trees.resize(n+1, 0);
    for(int i=0;i<n;++i){
        trees[i+1] = pers_insert(trees[i], 0, n-1, pts[i]);
    }
}
ll nc2(ll x){
    return x*(x-1)/2;
}

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &e:a){
        cin >> e;
        --e;
    }
    build(n, a);
    for(int i=0;i<q;++i){
        int x1, x2, y1, y2;
        cin >> x1 >>y1 >> x2 >> y2;
        --x1; --x2;
        --y1; --y2;
        ll ans = nc2(n);
        ll sub1 = nc2(rec_query(-1e8, x1-1, -1e8, 1e8));
        ll sub2 = nc2(rec_query(x2+1, 1e8, -1e8, 1e8));
        ll sub3 = nc2(rec_query(-1e8, 1e8, -1e8, y1-1));
        ll sub4 = nc2(rec_query(-1e8, 1e8, y2+1, 1e8));
        ll add1 = nc2(rec_query(-1e8, x1-1, -1e8, y1-1));
        ll add2 = nc2(rec_query(-1e8, x1-1, y2+1, 1e8));
        ll add3 = nc2(rec_query(x2+1, 1e8, -1e8, y1-1));
        ll add4 = nc2(rec_query(x2+1, 1e8, y2+1, 1e8));
        //cerr << ans << "\n" << sub1 << " / " << sub2 << " / " << sub3 << " / " << sub3 << "\n";
        //cerr << add1 << " / " << add2 << " / " << add3 << " / " << add3 << "\n";
        ans-=sub1+sub2+sub3+sub4;
        ans+=add1+add2+add3+add4;
        cout << ans << "\n";
    }
    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}