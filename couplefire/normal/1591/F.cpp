#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

struct node{
    int sum, tl, tr, a, b;
    node *l, *r;
    node(int _sum, int _tl, int _tr, int _a = 1, int _b = 0){
        sum = _sum, tl = _tl, tr = _tr, a = _a, b = _b;
        l = nullptr; r = nullptr;
    }
    void push(){
        if(tl!=tr){
            if(!l){
                int tm = (tl+tr)>>1;
                l = new node(sum, tl, tm);
                r = new node(sum, tm+1, tr);
            }
            grow(l->a, a); l->b = add(mul(a, l->b), b);
            grow(r->a, a); r->b = add(mul(a, r->b), b);
        } sum = add(mul(a, sum), mul(b, (tr-tl+1)%MOD)); a = 1, b = 0;
    }
    void upd(int l, int r, int na, int nb){ push();
        if(tr<l || tl>r) return;
        if(l<=tl && tr<=r){
            grow(a, na); b = add(mul(na, b), nb);
            push(); return;}
        this->l->upd(l, r, na, nb);
        this->r->upd(l, r, na, nb);
        sum = add(this->l->sum, this->r->sum);
    }
}; node* root = new node(0, 1, 1000000000);

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i = 0; i<n; ++i){
        int b; cin >> b;
        root->upd(1, b, MOD-1, i?root->sum:1);
        root->upd(b+1, 1000000000, 0, 0);
    } cout << root->sum << '\n';
}