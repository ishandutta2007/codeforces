#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

struct rec {
    int w, h, i;
    rec () {}
    rec(int a, int b, int c) : w(a), h(b), i(c) {}
    bool operator< (const rec& o) const {
        if(w == o.w) return h > o.h;
        return w < o.w;
    }
};

int n, W, H;

const int INF = 0x3f3f3f3f;

vector<rec> recs;
vector<pii> f;
vector<int> last;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> W >> H;
    for(int i=1;i<=n;++i) {
        int w, h;
        cin >> w >> h;
        if(w > W && h > H) {
            recs.emplace_back(w, h, i);
        }
    }
    //cerr << "!! " << endl;
    sort(recs.begin(), recs.end());
    f = vector<pii>(n+1, pii(INF, INF));
    last = vector<int>(n+1, 0);
    //cerr << "!! " << endl;
    f[0] = pii(0, 0);


    for(int i=0;i<recs.size();++i) {
        //cerr << " :0" << endl;
        auto it = lower_bound(f.begin(), f.end(), pii(recs[i].h, 0));
        int j = it-f.begin();
        if(f[j].first > recs[i].h) {
            last[recs[i].i] = f[j-1].second;
            f[j] = pii(recs[i].h, recs[i].i);
        }
    }
    int start = 0;
    for(int i=n;i>=0;--i) {
        if(f[i].first != INF) {
            start = i;
            break;
        }
    }
    cout << start << "\n";
    start = f[start].second;
    vector<int> ans;
    while(start) {
        ans.push_back(start);
        start = last[start];
    }
    reverse(ans.begin(), ans.end());
    for(auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}