// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

constexpr int B = 1777;
constexpr int N = 200005;

int n;

class ValDecomp {
public:
    int small[N], lar[N/B+2];
    void upd(int i, int v) {
        while(i <= n && i % B) 
            small[i] += v, i++;
        while(i <= n) 
            lar[i/B] += v, i += B;
    }
    int qry(int i) { 
        return small[i] + lar[i/B]; 
    }
} dcmps[N/B+2];

int ar[N];

void upd(int i, int v) {
    if(ar[i]) 
        dcmps[i/B].upd(ar[i], -1);
    ar[i] = v;
    dcmps[i/B].upd(ar[i], 1);
}

int qry(int l, int r, int h) {
    int ans = 0;
    if(l/B == r/B) 
        iter(i, l, r+1) 
            ans += (ar[i] <= h);
    else {
        while(l % B) 
            ans += (ar[l] <= h), l++;
        while(r % B != B - 1)
            ans += (ar[r] <= h), r--;
        while(l <= r)
            ans += dcmps[l/B].qry(h), l += B;
    }
    return ans;
}

int pos[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m;
    cin >> n >> m;
    rep1(i, n) {
        int v; cin >> v;
        pos[v] = i;
    }
    rep1(i, n) {
        int v; cin >> v;
        upd(i, pos[v]);
    }
    while(m--) {
        int o; cin >> o;
        if(o == 1) {
            int la, ra, lb, rb; 
            cin >> la >> ra >> lb >> rb;
            cout << qry(lb, rb, ra) - qry(lb, rb, la-1) << endl;
        } else {
            int x, y; cin >> x >> y;
            int a = ar[x], b = ar[y];
            upd(x, b);
            upd(y, a);
        }
    }
}