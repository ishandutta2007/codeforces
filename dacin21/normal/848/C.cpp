#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

class avlTree{
public:
    struct node{
        node*l,*r;
        int x, height;
        ll y, suby;
        int subsize;
        node(int _x, ll _y):l(0),r(0),x(_x),height(1),y(_y),suby(y),subsize(1){}
        node* recalc(){
            subsize = 1+(l?l->subsize:0)+(r?r->subsize:0);
            height = 1+max(l?l->height:0, r?r->height:0);
            suby = y + (l?l->suby:0) + (r?r->suby:0);
            return this;
        }

    }*root;
    avlTree():root(0){}
private:
    /// balanced at most once
    static node* balance(node* a, node* l, node* r){
        if((l?l->height:0) > (r?r->height:0)+1){
            if((l->l?l->l->height:0) >= (l->r?l->r->height:0)){
                a->l = l->r; a->r = r; a->recalc();
                l->r = a; return l->recalc();
            }
            a->l = l->r->r; a->r = r; a->recalc();
            node* ret = l->r;
            l->r = l->r->l; l->recalc();
            ret->r = a; ret->l = l; return ret->recalc();
        } else if((r?r->height:0) > (l?l->height:0)+1){
            if((r->r?r->r->height:0) >= (r->l?r->l->height:0)){
                a->r = r->l; a->l = l; a->recalc();
                r->l = a; return r->recalc();
            }
            a->l = l; a->r = r->l->l; a->recalc();
            node* ret = r->l;
            r->l = r->l->r; r->recalc();
            ret->r = r; ret->l = a; return ret->recalc();
        }
        a->l = l; a->r = r; return a->recalc();
    }
    /// balances at most once
    static node* flat_merge(node*a, node*l, node*r){
        return balance(a, l, r);
    }
    /// inserts singleton-node val into a
    static node* insert(node*a, node* val){
        if(a==0) return val;
        if(val->x == a->x){
            a->y+=val->y;
            delete val;
            return a->recalc();
        }
        if(val->x < a->x){
            return balance(a, insert(a->l, val), a->r);
        } else {
            return balance(a, a->l, insert(a->r, val));
        }
    }

    static node* push_front(node*a, node*val){
        if(a==0) return val;
        return balance(a, push_front(a->l, val), a->r);
    }

    static node* push_back(node*a, node*val){
        if(a==0) return val;
        return balance(a, a->l, push_back(a->r, val));
    }

    static node* merge(node*a, node*l, node*r){
        if(l==0) return push_front(r, a);
        if(r==0) return push_back(l, a);
        if(l->height > r->height+1){
            return balance(l, l->l, merge(a, l->r, r));
        }
        if(r->height > l->height+1){
            return balance(r, merge(a, l, r->l), r->r);
        }
        a->l = l; a->r = r; return a->recalc();
    }
    static node* front(node*a){
        while(a->l) a=a->l;
        return a;
    }
    static node* back(node*a){
        while(a->r) a=a->r;
        return a;
    }
    static node* pop_front(node*a){
        if(a->l) return balance(a, pop_front(a->l), a->r);
        return a->r;
    }
    static node* pop_back(node*a){
        if(a->r) return balance(a, a->l, pop_back(a->r));
        return a->l;
    }

    static node* merge(node*a, node*b){
        if(a==0) return b;
        if(b==0) return a;
        node*m = front(b);
        return merge(m, a, pop_front(b));
    }

    static node* flat_merge(node*a, node*b){
        if(a==0) return b;
        if(b==0) return a;
        node*m = front(b);
        return balance(m, a, pop_front(b));
    }
    static pair<node*, node*> split(node*a, int pos){
        if(a==0){
            assert(pos==0);
            return make_pair((node*)0, (node*)0);
        }
        if(pos <= (a->l?a->l->subsize:0)){
            pair<node*, node*> L = split(a->l, pos);
            return make_pair(L.first, merge(a, L.second, a->r));
        }
        pair<node*, node*> R = split(a->r, pos -1 -(a->l?a->l->subsize:0));
        return make_pair(merge(a, a->l, R.first), R.second);
    }
    static pair<node*, node*> splitval(node*a, int val){
        if(a==0){
            return make_pair((node*)0, (node*)0);
        }
        if(val < a->x){
            pair<node*, node*> L = splitval(a->l, val);
            return make_pair(L.first, merge(a, L.second, a->r));
        }
        pair<node*, node*> R = splitval(a->r, val);
        return make_pair(merge(a, a->l, R.first), R.second);
    }
    static node* erase(node*a, int pos){
        if(pos == (a->l?a->l->subsize:0)){
            node*ret =  flat_merge(a->l, a->r);
            delete a;
            return ret;
        }
        if(pos < (a->l?a->l->subsize:0)) return balance(a, erase(a->l, pos), a->r);
        return balance(a, a->l, erase(a->r, pos -1 -(a->l?a->l->subsize:0)));
    }
	static node* eraseval(node*a, int val){
        if(val==a->x){
            node*ret =  merge(a->l, a->r);
            delete a;
            return ret;
        }
        if(val<a->x) return balance(a, eraseval(a->l, val), a->r);
        return balance(a, a->l, eraseval(a->r, val));
    }
    static void destroy(node*a){
        if(a==0) return ;
        destroy(a->l);
        destroy(a->r);
        delete a;
    }
public:
    static void check_balance(node * cur){
        if(cur->l) check_balance(cur->l);
        if(cur->r) check_balance(cur->r);
        int lH = (cur->l?cur->l->subsize:0);
        int rH = (cur->r?cur->r->subsize:0);
        assert(lH<=rH+1 && rH<=lH+1);
    }
    static void traverse(ostream&o, node*cur){
        if(cur==0) return;
        o << " ( ";
        if(cur->l) traverse(o, cur->l);
        o << cur->x << "[" << cur->height << "," << cur->subsize << "]";
        if(cur->r) traverse(o, cur->r);
        o << ")";
    }
    void insert(int x, ll y){
        root = insert(root, new node(x, y));
    }
    void erase(int pos){
        root = erase(root, pos);
    }
    void eraseval(int val){
        root = eraseval(root, val);
    }
    int lower_count(int x){
        int ret=0;
        for(node*cur = root;cur;){
            if(x<cur->x) cur=cur->l;
            else {
                ret+=1 + (cur->l?cur->l->subsize:0);
                cur=cur->r;
        }   }
        return ret;
    }
    void destroy(){
        destroy(root);
    }
    void update(int y, ll val){
        insert(y, val);
    }
    ll q(int y){
        ll ans = 0;
        for(node*cur = root;cur;){
            if(y<cur->x) cur=cur->l;
            else {
                ans+=cur->y + (cur->l?cur->l->suby:0);
                cur=cur->r;
        }   }
        return ans;
    }
    ll query(int y1, int y2){
        return q(y2-1) - q(y1-1);
    }
};

struct tree2d{
    int n;
    vector<avlTree> data;
    tree2d(int _n):n(_n+2), data(n){}
    ll q(int x, int y1, int y2){
        ll ans = 0;
        for(;x;x-=(x&-x)){
            ans+=data[x].query(y1, y2);
        }
        return ans;
    }
    // [x1, x2[ x [y1, y2[
    ll query(int x1, int x2, int y1, int y2){
        return q(x2, y1, y2)-q(x1, y1, y2);
    }
    void u(int x, int y, ll val){
        ++x;
        for(;x<n;x+=(x&-x)){
            data[x].update(y, val);
        }
    }
    void update(int x, int y, ll val){
        u(x, y, val);
    }
};

signed gen(int n){
    int m = n;
    ofstream o("gen.txt");
    o << n << "  " << m << "\n";
    mt19937 rng(21536);
    auto getrand = [&](int r){return uniform_int_distribution<int>(0, r-1)(rng);};
    for(int i=0;i<n;++i){
        o << getrand(1+n/10) << " ";
    }
    o << endl;
    for(int i=0;i<m;++i){
        o << (i%2)+1 << " " << 1+getrand(n) << " " << 1+getrand(n) << "\n";
    }
    o << endl;
    o.close();
    return 0;
}

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT;
    if(TTT<0) return gen(-TTT);
    while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    int n, m;
    cin >> n >> m;

    tree2d tr(n);

    vector<set<int> > bu(n+1);

    vector<int> a(n);
    for(auto &e:a){
        cin >> e;
    }
    for(int i=0;i<n;++i){
        if(!bu[a[i]].empty()){
            int l = *bu[a[i]].rbegin();
            tr.update(l, i, i-l);
        }
        bu[a[i]].insert(i);
    }

    for(int i=0;i<m;++i){
        int t, b, c;
        cin >> t >> b >> c;
        if(t==1){
            --b;
            auto it = bu[a[b]].find(b);
            auto up = [&](ll s){
                auto it2 = next(it);
                if(it2 != bu[a[b]].end()){
                    int l = b;
                    int r = *it2;
                    tr.update(l, r, s*(r-l));
                }
                if(it!=bu[a[b]].begin()){
                    auto it3 = prev(it);
                    int l = *it3;
                    int r = b;
                    tr.update(l, r, s*(r-l));
                    if(it2 != bu[a[b]].end()){
                        l = *it3;
                        r = *it2;
                        tr.update(l, r, -s*(r-l));
                    }
                }
            };
            up(-1);
            bu[a[b]].erase(b);
            a[b] = c;
            bu[a[b]].insert(b);
            it = bu[a[b]].find(b);
            up(1);
        } else {
            --b; --c;
            ll ans = tr.query(b, n+1, 0, c+1);
            cout << ans << "\n";
        }

    }



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}