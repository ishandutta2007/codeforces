#include <bits/stdc++.h>

using namespace std;
typedef int64_t var;
typedef pair<var, var> Pair;
#define MAXN 300000

var Sol[MAXN];
set<Pair> Pts;

struct Int {
    var b, e, i;
    Int(var a, var c, var d) {
        b = a; e = c; i = d;
    }
};
vector<Int> Ints;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var n, m;
    cin>>n>>m;

    var lastx, lasty, curx, cury, len;

    cin>>lastx>>lasty;
    for(var i=1; i<n; i++) {
        cin>>curx>>cury;
        Ints.push_back(Int(curx - lasty, cury - lastx, i));
        lastx = curx; lasty = cury;
    }

    for(var i=1; i<=m; i++) {
        cin>>len;
        Pts.insert(Pair(len, i));
    }

    sort(Ints.begin(), Ints.end(), [](Int a, Int b) {return a.e < b.e;});

    for(auto &in: Ints) {
        auto it = Pts.upper_bound(Pair(in.b, 0));
        if(it == Pts.end() || it->first > in.e) {cout<<"No"; return 0;}
        Sol[in.i] = it->second;
        Pts.erase(it);
    }

    cout<<"Yes\n";
    for(var i=1; i<n; i++) {
        cout<<Sol[i]<<' ';
    }



    return 0;
}