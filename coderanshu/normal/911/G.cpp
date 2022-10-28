#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 200005;

template<typename T, bool MULTI = false, typename SIZE_T = int> 
struct sms {
    struct node {
        node *l, *r; // left and right childs
        SIZE_T cnt; // subtree leaf count
        node() : l(NULL), r(NULL), cnt(0) {}
        void update() { // update subtree leaf count
            cnt = 0;
            if (l) cnt += l->cnt;
            if (r) cnt += r->cnt;
        }
    };

    node* root;
    T N;

    sms() : root(NULL), N(0) {}
    sms(T v) : sms() 
    {
        while (v >= N) N = 2*N+1;
        // N is inclusive in the size
    }
    sms(const sms& t) : root(NULL), N(t.N)  // copy - O(t log(N))
    { 
        for (SIZE_T i = 0; i < t.size(); i++) {
            T at = t[i];
            SIZE_T qt = t.count(at);
            insert(at, qt);
            i += qt-1;
        }
    }
    sms(initializer_list<T> v) : sms() { 
        for (T i : v) 
            insert(i); 
    }
    ~sms() {
        vector<node*> q = {root};
        while (q.size()) {
            node* x = q.back(); q.pop_back();
            if (!x) continue;
            q.push_back(x->l), q.push_back(x->r);
            delete x;
        }
    }

    friend void swap(sms& a, sms& b) { // O(1) swap
        swap(a.root, b.root), swap(a.N, b.N);
    }
    SIZE_T size() const { return root ? root->cnt : 0; }
    SIZE_T count(node* x) const { return x ? x->cnt : 0; }
    void clear() {
        sms tmp;
        swap(*this, tmp);
    }
    void expand(T v) { // increase N so value 'v' will fit
        for (; N < v; N = 2*N+1) 
        {
            if (root) 
            {
                node* nroot = new node();
                nroot->l = root;
                root = nroot;
                root->update();
            }
        }
    }

    node* insert(node* at, T idx, SIZE_T qt, T l, T r) {
        if (!at) at = new node();
        if (l == r) {
            at->cnt += qt;
            if (!MULTI) at->cnt = 1;
            return at;
        }
        T m = l + (r-l)/2;
        if (idx <= m) at->l = insert(at->l, idx, qt, l, m);
        else at->r = insert(at->r, idx, qt, m+1, r);
        at->update();
        return at;
    }
    void insert(T v, SIZE_T qt=1) { // insert 'qt' occurrences of 'v'
        if (qt <= 0) return erase(v, -qt);
        assert(v >= 0);
        expand(v);
        root = insert(root, v, qt, 0, N);
    }

    node* erase(node* at, T idx, SIZE_T qt, T l, T r) {
        if (!at) return at;
        if (l == r) 
            at->cnt = at->cnt < qt ? 0 : at->cnt - qt;
        else 
        {
            T m = l + (r-l)/2;
            if (idx <= m) at->l = erase(at->l, idx, qt, l, m);
            else at->r = erase(at->r, idx, qt, m+1, r);
            at->update();
        }
        if (!at->cnt) delete at, at = NULL; // 'cnt' is always positive
        return at;
    }
    void erase(T v, SIZE_T qt=1) { // erase 'qt' occurrences of 'v'
        if (v < 0 or v > N or !qt) 
            return;
        if (qt < 0) 
            insert(v, -qt);
        root = erase(root, v, qt, 0, N);
    }
    void erase_all(T v) { // remove all occurrences of 'v'
        if (v < 0 or v > N) 
            return;
        root = erase(root, v, numeric_limits<SIZE_T>::max(), 0, N);
    }

    SIZE_T count(node* at, T a, T b, T l, T r) const {
        // count of numbers in range --> just like range sum query in segTree
        if (!at or b < l or r < a) 
            return 0;
        if (a <= l and r <= b) 
            return at->cnt;
        T m = l + (r-l)/2;
        return count(at->l, a, b, l, m) + count(at->r, a, b, m+1, r);
    }
    SIZE_T count(T v) const { 
        return count(root, v, v, 0, N); 
    }
    SIZE_T order_of_key(T v) { 
        return count(root, 0, v-1, 0, N); 
    }
    SIZE_T lower_bound(T v) {
        return order_of_key(v);
    }
    const T operator [](SIZE_T i) const { // i-th smallest element (0 -> smallest)
        // array like indexing 
        assert(i >= 0 and i < size());
        node* at = root;
        T l = 0, r = N;
        while (l < r) {
            T m = l + (r-l)/2;
            if (count(at->l) > i) 
                at = at->l, r = m;
            else {
                i -= count(at->l);
                at = at->r; l = m+1;
            }
        }
        return l;
    }

    node* merge(node* l, node* r) {
        if (!l or !r) return l ? l : r;
        if (!l->l and !l->r) { // 'l' is a leaf
            if (MULTI) l->cnt += r->cnt;
            delete r;
            return l;
        }
        l->l = merge(l->l, r->l), l->r = merge(l->r, r->r);
        l->update(), delete r;
        return l;
    }
    void merge(sms& s) { // merge two sets
        if (N > s.N) swap(*this, s);
        expand(s.N);
        root = merge(root, s.root);
        s.root = NULL;
    }

    node* split(node*& x, SIZE_T k) {
        if (k <= 0 or !x) return NULL;
        node* ret = new node();
        if (!x->l and !x->r) 
            x->cnt -= k, ret->cnt += k;
        else {
            if (k <= count(x->l)) 
                ret->l = split(x->l, k);
            else 
            {
                ret->r = split(x->r, k - count(x->l));
                swap(x->l, ret->l);
            }
            ret->update(), x->update();
        }
        if (!x->cnt) delete x, x = NULL; // 'cnt' is always positive
        return ret;
    }
    void split(SIZE_T k, sms& s) { // get the 'k' smallest elements
        s.clear();
        s.root = split(root, min(k,size()));
        s.N = N;
    }
    // get all elements smaller than 'k'
    void split_val(T k, sms& s) { 
        split(order_of_key(k), s); 
    }
};

sms<int> s[101];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
        s[v[i]].insert(i);
    }
    int Q;
    cin>>Q;
    for(int i=0;i<Q;++i)
    {
        sms<int> u,v;
        int l,r,x,y;
        cin>>l>>r>>x>>y;
        --l,--r;
        int yy = s[x].order_of_key(r+1);
        s[x].split(yy,u);
        int xx = u.order_of_key(l);
        u.split(xx,v);
        s[x].merge(v);
        s[y].merge(u);
    }
    for(int i=1;i<=100;++i)
    {
        for(int j=0;j<sz(s[i]);++j)
            v[s[i][j]] = i;
    }
    for(int i=0;i<n;++i)
        cout<<v[i]<<" ";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}