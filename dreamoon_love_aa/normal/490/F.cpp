#include<assert.h>
#include<stdarg.h>
#include<stdio.h>
#include<list>
using namespace std;

#define MX 1310720

inline void _debug(const char *fmt, ...) {
/*  va_list vl;
    va_start(vl, fmt);
    vfprintf(stderr, fmt, vl);
    va_end(vl);*/
}

inline int max(int a, int b) { return a>b ? a : b; }

typedef struct Node {
    int key, lis, lds;
    int hi, mxis, mxds;
    struct Node *lf, *rt;
    Node() {}
    Node(int a, int b, int c):key(a), lis(b), lds(c), hi(1), mxis(b), mxds(c), lf(NULL), rt(NULL) {}
    inline void clear() {hi = 1, mxis = lis, mxds = lds, lf = rt = NULL; }
    inline void print() { _debug("%d: (%d,%d) mx (%d,%d) hi %d\n", key, lis, lds, mxis, mxds, hi); }
}Node;

typedef struct Tree {
    Node *root;
    Tree():root(NULL) {}
    inline int getH(Node *nd) { return nd==NULL ? 0 : nd->hi; }
    inline int getMxis(Node *nd) { return nd==NULL ? 0 : nd->mxis; }
    inline int getMxds(Node *nd) { return nd==NULL ? 0 : nd->mxds; }
    inline void refresh(Node *nd) {
        nd->hi = max(getH(nd->lf), getH(nd->rt)) + 1;
        nd->mxis = max(nd->lis, max(getMxis(nd->lf), getMxis(nd->rt)));
        nd->mxds = max(nd->lds, max(getMxds(nd->lf), getMxds(nd->rt)));
    }
    inline void rotateLeft(Node *now, Node **par) {
        Node *chd = now->rt;
        now->rt = chd->lf;
        chd->lf = now;
        *par = chd;
        refresh(now);
        refresh(chd);
    }
    inline void rotateRight(Node *now, Node **par) {
        Node *chd = now->lf;
        now->lf = chd->rt;
        chd->rt = now;
        *par = chd;
        refresh(now);
        refresh(chd);
    }
    inline void _insert(Node *now, Node **par, Node *nd) {
        //assert(now->key != nd->key);
        if(now->key < nd->key) {
            if(now->rt == NULL) now->rt = nd;
            else _insert(now->rt, &now->rt, nd);
        } else {
            if(now->lf == NULL) now->lf = nd;
            else _insert(now->lf, &now->lf, nd);
        }
        _debug("\tins %d @ %d h %d %d\n", nd->key, now->key, getH(now->lf), getH(now->rt));
        if(getH(now->lf) > getH(now->rt)+1) {
            if(getH(now->lf->rt) > getH(now->lf->lf)) rotateLeft(now->lf, &now->lf);
            rotateRight(now, par);
        } else if(getH(now->rt) > getH(now->lf)+1) {
            if(getH(now->rt->lf) > getH(now->rt->rt)) rotateRight(now->rt, &now->rt);
            rotateLeft(now, par);
        }
        else refresh(now);
    }
    inline void insert(Node *nd) {
        if(root == NULL) root = nd;
        else _insert(root, &root, nd);
    }
    inline int _queryMxis(Node *now, int key) {
        if(now == NULL) return 0;
        else if(key > now->key) return _queryMxis(now->rt, key);
        //assert(key != now->key);
        return  max(now->lis, max(getMxis(now->rt), _queryMxis(now->lf, key)));
    }
    inline int queryMxis(int key) {
        return _queryMxis(root, key+1);
    }
    inline int _queryMxds(Node *now, int key) {
        if(now == NULL) return 0;
        else if(key < now->key) return _queryMxds(now->lf, key);
        //assert(key != now->key);
        return  max(now->lds, max(getMxds(now->lf), _queryMxds(now->rt, key)));
    }
    inline int queryMxds(int key) {
        return _queryMxds(root, key-1);
    }
    inline void _print(Node *now, int d) {
        if(now->lf != NULL) _print(now->lf, d+1);
        for(int i = 0; i < d; ++i) _debug("  ");
        now->print();
        if(now->rt != NULL) _print(now->rt, d+1);
    }
    inline void print() {
    //  _print(root, 0);
    }
}Tree;

Node _node[MX<<1];
int nNode;

int V[MX], SIZE[MX];
short _in[MX], _vst[MX];
int T, N;
list<int> E[MX];

inline void _checkTree(int c, int p) {
    _vst[c] = T;
    for(list<int>::iterator itr = E[c].begin(); itr != E[c].end(); ++itr)
        if(*itr != p) {
            //assert(_vst[*itr] != T);
            _checkTree(*itr, c);
        }
}

inline int calcSize(int c, int p) {
    SIZE[c] = 1;
    for(list<int>::iterator itr = E[c].begin(); itr != E[c].end(); ++itr)
        if(*itr != p) SIZE[c] += calcSize(*itr, c);
    return SIZE[c];
}

inline Node* newNode(int key, int lis, int lds) {
    Node *r = _node + (nNode++);
    *r = Node(key, lis, lds);
    return r;
}

Node *Q[MX];
inline int mergeQuery(Tree *t1, Tree *t2, int v) {
    int ans = max(t1->queryMxis(v)+t2->queryMxds(v), t1->queryMxds(v)+t2->queryMxis(v)) + 1;
    int head, tail;
    for(head = 0, tail = 1, Q[0] = t2->root; head < tail; ++head) {
        Node *now = Q[head];
        if(now->lf != NULL) Q[tail++] = now->lf;
        if(now->rt != NULL) Q[tail++] = now->rt;
        int t = max(now->lis+t1->queryMxds(now->key), now->lds+t1->queryMxis(now->key));
        if(t > ans) ans = t;
    }
    for(int i = tail-1; i >= 0; --i) {
        Node *now = Q[i];
        now->clear();
        t1->insert(now);
    }
    return ans;
}

inline int dfs(int c, int p, Tree *tree) {
    _debug("dfs %d (%d) %d\n", c, V[c], p);
    if(E[c].size() == 1 && p != -1) {
        tree->insert(newNode(V[c], 1, 1));
        return 1;
    }
    int mxc = -1;
    for(list<int>::iterator itr = E[c].begin(); itr != E[c].end(); ++itr)
        if(*itr != p && (mxc==-1 || SIZE[*itr]>SIZE[mxc])) mxc = *itr;
    _debug("\tmxc %d\n", mxc);
    int ans = dfs(mxc, c, tree);
    for(list<int>::iterator itr = E[c].begin(); itr != E[c].end(); ++itr)
        if(*itr != p && *itr != mxc) {
            Tree tmp;
            dfs(*itr, c, &tmp);
            int r = mergeQuery(tree, &tmp, V[c]);
            if(r > ans) ans = r;
        }
    int lis = tree->queryMxis(V[c])+1, lds = tree->queryMxds(V[c])+1;
    tree->insert(newNode(V[c], lis, lds));
    tree->print();
    if(tree->root->mxis > ans) ans = tree->root->mxis;
    if(tree->root->mxds > ans) ans = tree->root->mxds;
    _debug("dfs %d (%d) %d: %d\n", c, V[c], p, ans);
    return ans;
}

int main() {
    {
        T=1;
        scanf("%d", &N);
        //assert(2 <= N && N <= 100000);
        for(int i = 0; i < N; ++i) {
            scanf("%d", &V[i]);
            //assert(1 <= V[i] && V[i] <= N && _in[V[i]] != T);
            //E[i].clear();
            SIZE[i] = 0;
            _in[V[i]] = T;
        }
        for(int i = 1; i < N; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            --a, --b;
            E[a].push_back(b);
            E[b].push_back(a);
        }
        //_checkTree(0, -1);
        //for(int i = 0; i < N; ++i) assert(_vst[i] == T);
        nNode = 0;
        Tree t;
        int r = 514514514 % N;
        calcSize(r, -1);
        int ans = dfs(r, -1, &t);
        printf("%d\n", ans);
    }
}