#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
int main() {
    int n,m;
    scanf ("%d %d",&n,&m);
    vector<pii> aa(n), bb(m);
    for (auto &au : aa) {
        scanf ("%d %d",&au.first,&au.second);
        if (au.first > au.second) swap(au.first,au.second);
    }
    for (auto &au : bb) {
        scanf ("%d %d",&au.first,&au.second);
        if (au.first > au.second) swap(au.first,au.second);
    }
    set<int> go;
    for (auto &p1 : aa) {
        int cnt = 0;
        for (auto &p2 : bb) {
            int ree = (p1.first == p2.first) + (p1.second == p2.second) + (p1.first == p2.second) + (p1.second == p2.first);
            if (ree == 1) {
                ++cnt;
                if ((p1.first == p2.first) || (p1.first == p2.second)) go.insert(p1.first);
                else go.insert(p1.second);
            }
        }
    }
    for (auto &p1 : bb) {
        int cnt = 0;
        for (auto &p2 : aa) {
            int ree = (p1.first == p2.first) + (p1.second == p2.second) + (p1.first == p2.second) + (p1.second == p2.first);
            if (ree == 1) {
                ++cnt;
                if ((p1.first == p2.first) || (p1.first == p2.second)) go.insert(p1.first);
                else go.insert(p1.second);
            }
        }
    }
    if (go.size() == 1) return !printf ("%d\n",*go.begin());
    for (auto &p1 : aa) {
        set<int> hmm;
        for (auto &p2 : bb) {
            int ree = (p1.first == p2.first) + (p1.second == p2.second) + (p1.first == p2.second) + (p1.second == p2.first);
            if (ree == 1) {
                if ((p1.first == p2.first) || (p1.first == p2.second)) hmm.insert(p1.first);
                else hmm.insert(p1.second);
            }
        }
        if (hmm.size() > 1) return !printf ("-1\n");
    }
    for (auto &p1 : bb) {
        set<int> hmm;
        for (auto &p2 : aa) {
            int ree = (p1.first == p2.first) + (p1.second == p2.second) + (p1.first == p2.second) + (p1.second == p2.first);
            if (ree == 1) {
                if ((p1.first == p2.first) || (p1.first == p2.second)) hmm.insert(p1.first);
                else hmm.insert(p1.second);
            }
        }
        if (hmm.size() > 1) return !printf ("-1\n");
    }
    printf ("0\n");
    return 0;
}