#include <bits/stdc++.h>

using namespace std;



namespace TreapSet { 
    
    struct Node {
        int l, r, k, dp, max_dp, p;
        int lazy_k, lazy_dp;
    };
    Node T[1000005];
    int root = 0, nodes = 0;
    

    void lazy_update(int a) {
        if (!a) return;

        if (T[a].lazy_k) {
            if (T[a].l) {
                T[T[a].l].lazy_k += T[a].lazy_k;
            }
            if (T[a].r) {
                T[T[a].r].lazy_k += T[a].lazy_k;
            }
            T[a].k += T[a].lazy_k;
            T[a].lazy_k = 0;
        }
        if (T[a].lazy_dp) {
            if (T[a].l) {
                T[T[a].l].lazy_dp += T[a].lazy_dp;
            }
            if (T[a].r) {
                T[T[a].r].lazy_dp += T[a].lazy_dp;
            }
            T[a].dp += T[a].lazy_dp;
            T[a].max_dp += T[a].lazy_dp;
            T[a].lazy_dp = 0;
        }
    }

    void update(int a) {
        if (!a) return;

        lazy_update(a);
        lazy_update(T[a].l);
        lazy_update(T[a].r);

        T[a].max_dp = max(T[T[a].l].max_dp, T[T[a].r].max_dp);
        T[a].max_dp = max(T[a].max_dp, T[a].dp);
    }
    
     
    void split(int root, int k, int &l, int &r) {
        update(root);

        if(root == 0) l = r = 0;
        else {
            if(T[root].k >= k) {
                split(T[root].l, k, l, T[root].l);
                r = root;
            } else {
                split(T[root].r, k, T[root].r, r);
                l = root;
            }
        }
        update(l);
        update(r);
    }
     
    void join(int l, int r, int &root) {
        update(l);
        update(r);

        if(l == 0 || r == 0) root = l + r;
        else {
            if(T[l].p > T[r].p) {
                join(l, T[r].l, T[r].l);
                root = r;
            } else {
                join(T[l].r, r, T[l].r);
                root = l;
            }
        }
     
        update(root);
    }

    

    void ins(int &root, int k, int val) {
        update(root);

        if(root == 0 || T[root].p > T[nodes].p) {
            split(root, k, T[nodes].l, T[nodes].r);
            root = nodes;
        } else {
            if(T[root].k >= k) ins(T[root].l, k, val);
            else ins(T[root].r, k, val);
        }
     
        update(root);
    }
     
    void real_ins(int &root, int k, int val) {
        ++nodes;
        T[nodes].k = k;
        T[nodes].p = rand();
        T[nodes].dp = val;
        ins(root, k, val);
    }
     
    void dump(int node) {
        update(node);

        if(node == 0) return;
        dump(T[node].l);
        cerr << T[node].k << " ";
        dump(T[node].r);
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cerr << "seed: " << time(0) << endl;
    srand(1495306632);
    srand(time(0));


    int n;
    scanf("%d", &n);
    while (n--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int less_than_l, less_than_r;
        TreapSet::split(TreapSet::root, l, less_than_l, TreapSet::root);
        TreapSet::split(TreapSet::root, r, less_than_r, TreapSet::root);

        TreapSet::lazy_update(less_than_l);
        int dp_l = TreapSet::T[less_than_l].max_dp + 1;
        /*
        cerr << "For: " << l << " " << r << endl;
        TreapSet::dump(less_than_l); cerr << endl;
        TreapSet::dump(less_than_r); cerr << endl;
        TreapSet::dump(TreapSet::root); cerr << endl;
        cerr << "DP_L: " << dp_l << endl;
        cerr << "_____\n";
        */

        if (less_than_r) TreapSet::T[less_than_r].lazy_dp += 1;
        if (less_than_r) TreapSet::T[less_than_r].lazy_k += 1;
        TreapSet::join(less_than_r, TreapSet::root, TreapSet::root);
        TreapSet::join(less_than_l, TreapSet::root, TreapSet::root);
        TreapSet::real_ins(TreapSet::root, l, dp_l);

        // TreapSet::lazy_update(TreapSet::root);
        // cerr << TreapSet::T[TreapSet::root].max_dp << endl;


    }

    TreapSet::lazy_update(TreapSet::root);
    cout << TreapSet::T[TreapSet::root].max_dp << endl;

    

    
    return 0;
}