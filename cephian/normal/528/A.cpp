#include <iostream>
#include <set>
typedef long long ll;

using namespace std;
typedef pair<int,int> pii;
struct dim {
    multiset<int> widths;
    set<pii> intervals;

    dim(){};

    void init(int len) {
        widths.insert(len);
        intervals.insert(pii(0,len));
    }

    ll getmax() {
        return *widths.rbegin();
    }

    void cut(int pos) {
        pii p = *(--intervals.upper_bound(pii(pos,1e9)));
        widths.erase(widths.find(p.second-p.first));
        widths.insert(pos-p.first);
        widths.insert(p.second-pos);
        intervals.erase(p);
        intervals.insert(pii(p.first,pos));
        intervals.insert(pii(pos,p.second));
    }
};

dim W,H;

int main() {
    ios::sync_with_stdio(0);
    int w,h,n;
    cin >> w >> h >> n;
    W.init(w);
    H.init(h);
    for(int i = 0; i < n; ++i) {
        string s;
        int k;
        cin >> s >> k;
        if(s == "H") {
            H.cut(k);
        } else {
            W.cut(k);
        }
        cout << W.getmax()*H.getmax() << "\n";
    }
    return 0;
}