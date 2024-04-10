#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
using T = int;
const int MM = 5e5+5;

int tree[MM*4];
const T DEF = 0;
int LS, RS;

int n, q, a[MM];

inline T merge(T va, T vb){
    return __gcd(va, vb);
}

inline void pull(int rt){
    tree[rt] = merge(tree[lc], tree[rc]);
}

void build(int nl, int nr, int rt){
    if(nl == nr){
        tree[rt] = a[nl];
        return;
    }
    build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
}

void update(int l, int r, int val, int nl, int nr, int rt){
    if(r < nl || l > nr) return;
    if(l <= nl && r >= nr){
        tree[rt] = val;
        return;
    }
    update(l, r, val, nl, nm, lc); update(l, r, val, nm+1, nr, rc); pull(rt);
}

int query(int l, int r, int nl, int nr, int rt){
    if(r < nl || l > nr) return DEF;
    if(l <= nl && r >= nr) return tree[rt];
    return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
}

int bad;
void get(int l, int r, int x, int nl, int nr, int rt){
    if(bad == 2 or r < nl or l > nr or __gcd(tree[rt], x) == x)
        return;
    if(nl == nr){
        if(__gcd(tree[rt], x) != x){
            bad++;
        }
        return;
    }
    get(l, r, x, nl, nm, lc);
    get(l, r, x, nm+1, nr, rc);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    build(1, n, 1);

    cin>>q;
    while(q--){
        int op, l, r, x;
        cin>>op;
        if(op == 1){
            cin>>l>>r>>x;
            // int v = query(l, r, 1, n, 1);
            // if(v%x == 0){
                // cout<<"YES\n";
                // continue;
            // }
            // cout<<"NO\n";
            bad = 0;
            get(l, r, x, 1, n, 1);
            if(bad >= 2){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }
        else{
            cin>>l>>x;
            update(l, l, x, 1, n, 1);
        }
    }
}