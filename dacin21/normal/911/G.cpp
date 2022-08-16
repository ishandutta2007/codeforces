#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

/*
 *  keeps the array as a union of sored ranges, where each range is stored in a BBST
 *  runs in amortized O((N+Q) (log N)^2) time, if Q updates are performed.
 *  array-element queries can be done on-line in O(log N)
 *
 */


// sparse Segment-tree used as BST, as keys are in {0, 1, ..., N-1}
struct Node{
    unique_ptr<Node> l, r;
    Node(int size):l((Node*)0), r((Node*)0), ssize(size){}
    Node(unique_ptr<Node> ll, unique_ptr<Node> rr, int size):l(move(ll)), r(move(rr)), ssize(size){}
    Node(unique_ptr<Node> ll, unique_ptr<Node> rr):l(move(ll)), r(move(rr)), ssize((l?l->ssize:0) + (r?r->ssize:0)){}
    int ssize;
};

struct Sortedrange{
    static int N;
    mutable unique_ptr<Node> root;

    Sortedrange():root(nullptr){}
    Sortedrange(bool rev):root(new Node(0)){}
    Sortedrange(Sortedrange const&o):root(move(o.root)){}
    Sortedrange(int initval):root(new Node(1)){
        unique_ptr<Node> *cur = &root;
        int a=0, b=N;
        while(a+1<b){
            int mid = (a+b)/2;
            if(initval<mid){
                cur = &((*cur)->l = make_unique<Node>(1));
                b=mid;
            } else {
                cur = &((*cur)->r = make_unique<Node>(1));
                a=mid;
            }
        }
    }

    int size()const{
        return root?root->ssize:0;
    }

    void inter_merge(unique_ptr<Node> &a, unique_ptr<Node> &b)const{
        if(!a) a=move(b);
        if(b){
            a->ssize += b->ssize;
            inter_merge(a->l, b->l);
            inter_merge(a->r, b->r);
            b.reset();
        }
    }

    void absorb(Sortedrange o)const{
        inter_merge(root, o.root);
    }

    unique_ptr<Node> inter_split(unique_ptr<Node> &a, int pos, int l, int r)const{
        if(!a) return nullptr;
        int mid = (l+r)/2;
        unique_ptr<Node> ret;
        if(pos<mid) ret = make_unique<Node>(inter_split(a->l, pos, l, mid),nullptr);
        else ret = make_unique<Node>(move(a->l), inter_split(a->r, pos, mid, r));
        a->ssize-=ret->ssize;
        return ret;
    }

    Sortedrange splitoff(int leftcnt)const{
        assert(leftcnt>=0 && leftcnt<=N);
        Sortedrange ret;
        ret.root = inter_split(root, leftcnt, 0, N);
        return ret;
    }
    bool operator<(const Sortedrange&)const{
        return false;
    }
    int at(int i)const{
        assert(0<=i && i<size());
        unique_ptr<Node> * cur = &root;
        int a = 0, b=N;
        for(;a+1<b;){
            if(i<((*cur)->l?(*cur)->l->ssize:0)){
                cur = &(*cur)->l;
                b=(a+b)/2;
            } else {
                i-=(*cur)->l?(*cur)->l->ssize:0;
                cur = &(*cur)->r;
                a=(a+b)/2;
            }
        }
        return a;
    }
    void extract_rec(unique_ptr<Node>&u, int l, int r, vector<int>&ret){
        if(!u) return;
        if(!u->ssize) return;
        if(l+1 == r){
            ret.push_back(l);
        } else {
            int mid = (l+r)/2;
            extract_rec(u->l, l, mid, ret);
            extract_rec(u->r, mid, r, ret);
        }
    }
    vector<int> extract_all(){
        vector<int> ret;
        extract_rec(root, 0, N, ret);
        return ret;
    }
};
int Sortedrange::N = 0;


using ll = long long;
using ull = unsigned long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}
signed gen(int n){
    ofstream o("gen.txt");
    mt19937 rng(643743);
    auto get_rand = [&](ll a, ll b){return uniform_int_distribution<ll>(a, b)(rng);};
    o << 1 << "\n";
    o << n << "\n";
    for(int i=0;i<n;++i){
        o << get_rand(1, 10) << ' ';
    }
    o << "\n";
    o << 5*n << '\n';
    for(int i=0;i<5*n;++i){
        int l = get_rand(1, n);
        int r = get_rand(1, n);
        if(l>r) swap(l, r);
        o << l << " " << r << " " << get_rand(1, 10) << " " << get_rand(1, 10) << "\n";
    }
    o << endl;
    o.close();
    return 0;
}

namespace FIO{
    char buf[32*1042|1];
    int bc=0, be=0;
    char gc(){
        if(bc>=be){
            be = fread(buf, 1, sizeof(buf)-1, stdin);
            buf[be] = bc = 0;
        }
        return buf[bc++];
    }
    void readint(){}
    void readuint(){}
    template<typename T, typename ...S>
    void readuint(T &a, S& ...b){
        a=0;
        int x=gc();
        while(x<'0' || x>'9') x=gc();
        while(x>='0' && x<='9'){
            a = a*10+x-'0'; x=gc();
        }
        readuint(b...);
    }
	template<typename T, typename ...S>
    void readint(T &a, S& ...b){
        a=0;
        int x=gc(), s=1;;
        while(x!='-' && (x<'0' || x>'9')) x=gc();
		if(x=='-'){ s=-s; x=gc(); }
        while(x>='0' && x<='9'){
            a = a*10+x-'0'; x=gc();
        }
		if(s<0) a=-a;
        readint(b...);
    }
}
using FIO::readint;
using FIO::readuint;
signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; readint(TTT);
    if(TTT<0) return gen(-TTT);
    while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    int n;
    readuint(n);
    Sortedrange::N = n+2;
    map<int, Sortedrange> occ;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;++i){
        readuint(a[i]);
        occ[a[i]].absorb(Sortedrange(i));
        b[i] = a[i];
    }

    auto extract = [&](){
        for(auto &e:occ){
            vector<int> tmp = e.second.extract_all();
            for(auto &f:tmp){
                a[f] = e.first;
            }
        }
    };


    int q;
    readuint(q);
    for(int i=0;i<q;++i){
        int l, r, x, y;
        readuint(l, r, x, y);
        if(x==y) continue;
        --l; --r;
        auto &tr = occ[x];
        auto &tr2 = occ[y];
        auto tr_l = tr.splitoff(l);
        auto tr_m = tr.splitoff(r+1);
        tr.absorb(tr_l);
        tr2.absorb(tr_m);

        /*extract();
        for(int i=l;i<=r;++i){
            if(b[i] == x){
                b[i] = y;
            }
        }
        if(a!=b){
            cerr << i << "!!!\n";
            copy(a.begin(), a.end(), ostream_iterator<int>(cerr, " "));
            cerr << "\n";
            copy(b.begin(), b.end(), ostream_iterator<int>(cerr, " "));
            cerr << "\n";
        }*/
    }
    extract();
    for(auto &e:a) printf("%d ", e);
    printf("\n");




    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}