#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class MinSTree {
public:
    MinSTree* ltree;
    MinSTree* rtree;
    int left, size;
    long long val, prop;
    void propogate() {
        val += prop;
        if(ltree != nullptr) ltree->prop += prop;
        if(rtree != nullptr) rtree->prop += prop;
        prop = 0;
    }
    long long rmq(int lb, int rb) { // [lb, rb)
        propogate();
        if(lb >= rb) return 0xFFFFFFFFFFFFull;
        if(left == lb && left+size == rb) return val;
        if(rb <= left || left+size < lb) return 0xFFFFFFFFFFFFull;
        return min(ltree->rmq(lb, min(ltree->left+ltree->size, rb)), rtree->rmq(max(lb, rtree->left), rb));
    }
    void inc(int lb, int rb, long long v) {
        propogate();
        if(lb >= rb) return;
        if(left == lb && left+size == rb) {
            prop += v;
            return;
        }
        if(rb <= left || left+size < lb) return;
        ltree->inc(lb, min(ltree->left+ltree->size, rb), v);
        rtree->inc(max(lb, rtree->left), rb, v);
        val = min(ltree->val+ltree->prop, rtree->val+rtree->prop);
    }
};

long long aray[262144];

MinSTree* construct(int lef, int size) {
    MinSTree* t = new MinSTree;
    t->left = lef; t->size = size; t->prop = 0;
    t->ltree = nullptr; t->rtree = nullptr;
    if(size == 1) {
        t->val = aray[lef];
        return t;
    }
    t->ltree = construct(lef, size/2);
    t->rtree = construct(lef+size/2, size/2);
    t->val = min(t->ltree->val, t->rtree->val);
    return t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> aray[i];
    MinSTree* t = construct(0, 262144);
    int m; cin >> m;
    while(m--) {
        string s; cin >> ws; getline(cin, s);
        //cout << s << endl;
        int sp = 0;
        for(char c:s) if(c == ' ') sp++;
        istringstream sst(s);
        if(sp == 1) {
            int lef, rig; sst >> lef >> rig;
            if(lef <= rig) {
                cout << t->rmq(lef, rig+1) << endl;
            } else {
                cout << min(t->rmq(0, rig+1), t->rmq(lef, n)) << endl;
            }
        } else {
            int lef, rig;  long long v; sst >> lef >> rig >> v;
            if(lef <= rig) {
                t->inc(lef, rig+1, v);
            } else {
                t->inc(0, rig+1, v);
                t->inc(lef, n, v);
            }
        }
    }
}