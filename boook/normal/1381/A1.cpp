/*input
5
2
01
10
5
01011
11100
2
01
01
10
0110011011
1000110100
1
0
1
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn

struct N{
    N *l , *r;
    int pri , siz;
    int val, tag;
    N(int _val){
        pri = rand() , siz = 1;
        l = r = NULL;
        val = _val;
        tag = 0;
    }
};
int SIZ(N *now){ return now ? now->siz : 0; }
void push(N *now){
    if (now && now->tag) {
        if (now->l) now->l->val ^= 1, now->l->tag ^= 1, swap(now->l->l, now->l->r);
        if (now->r) now->r->val ^= 1, now->r->tag ^= 1, swap(now->r->l, now->r->r);
        now->tag = 0;
    }
}
void pull(N *now){
    now->siz = 1 + SIZ(now->l) + SIZ(now->r);
}
N *Merge(N *a , N *b){
    if(!a || !b) return a ? a : b;
    if(a->pri > b->pri)
         return push(a), a->r = Merge(a->r , b) , pull(a) , a;
    else return push(b), b->l = Merge(a , b->l) , pull(b) , b;
}
void Split(N *t , int k , N *&a , N *&b){
    if(!t) return a = b = NULL , void();
    push(t);
    if(SIZ(t->l) + 1 <= k)
         a = t , Split(t->r , k - 1 - SIZ(t->l) , a->r , b);
    else b = t , Split(t->l , k , a , b->l);
    pull(t);
}

void put(N *now) {
    push(now);
    if (now->l) put(now->l);
    cout << now->val;
    if (now->r) put(now->r);
}
int t, n;

void T(N *now) {
    // cout << "Here" << endl;
    now->val ^= 1;
    now->tag ^= 1;
    swap(now->l, now->r);
}


int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);

    cin >> t;
    while (t --) {
        string a, b;
        cin >> n >> a >> b;
        N *root = NULL;
        // cout << "a = " << a << endl;
        for (int i = 0; i < a.size(); ++ i) root = Merge(root, new N(a[i] - '0'));
        // put(root), cout << endl;
        vector<int> ans;
        for (int i = (int)a.size() - 1; i >= 0; -- i) {
            N *left, *mid, *right, *tmp;
            Split(root, i + 1, tmp, right);
            Split(tmp, i, left, mid);
            if (mid->val == b[i]) {
                root = Merge(left, Merge(mid, right));
            }
            else {
                left = Merge(left, mid);

                N *one, *las;
                Split(left, 1, one, las);
                // cout << "F " << one->val << " " << b[i] << " " << (int(one->val) == b[i]) << endl;
                // return 0;
                if (one->val == b[i] - '0') {
                    // cout << "why" << endl;
                    ans.emplace_back(1), T(one);
                }

                left = Merge(one, las);
                // cout << "SIZ: " << SIZ(left) << endl;
                T(left);
                ans.emplace_back(i + 1);
                root = Merge(left, right);
            }
            // break;
        }

        // put(root), cout << endl;
        // cout << b << " FINAL" << endl;
        // cout << "ans: ";
        cout << ans.size() << " ";
        for (auto to: ans) cout << to << " "; cout << "\n";
            // break;
    }
    return 0;
}