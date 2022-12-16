#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

#define en (1<<3)
#define di (1<<4)
#define fl (1<<5)

struct segtree {
    vector<int> tag;
    int n, h;
    string name;
    segtree() {}
    segtree(int sz, string nn) {
        name = nn;
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        tag = vector<int>(n<<1, 0);
    }
    inline void apply(int x, int t) {
        if(t == fl) {
            if(tag[x] == en) {
                tag[x] = di;
            } else if(tag[x] == di) {
                tag[x] = en;
            } else if(tag[x] == fl) {
                tag[x] = 0;
            } else {
                tag[x] = fl;
            }
        } else {
            tag[x] = t;
        }
    }
    inline void pushh(int x) {
        if(tag[x]) {
            apply(x<<1, tag[x]);
            apply(x<<1|1, tag[x]);
            tag[x] = 0;
        }
    }
    inline void push(int x) {
        for(int l=h;l>0;--l) {
            pushh(x>>l);
        }
    }
    inline void assign(int l, int r, int t) {
        if(l >= r) return;
        //cerr << " " << name << ": tag " << l << " to " << r << " with " << (t == en ? "ENABLE" : (t == di ? "DISABLE" : "FLIP")) << endl;
        l+= n, r+= n;
        push(l); push(r-1);
        for(;l<r;l/=2, r/=2) {
            if(l%2) apply(l++, t);
            if(r%2) apply(--r, t);
        }
    }
    inline int get(int x) {
        push(x+n);
        return tag[x+n];
    }
};

int n, q;

const int NMAX = 100100;

int pos[NMAX]; //pos[i] = first location which is >= i;
vector<int> at[NMAX]; // indices which have absolute value of this.
vector<int> nat[NMAX]; // indices which have absolute value of this.
int ans[NMAX];
int cc = 0;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for(int i=0;i<n;++i) {
        int x;
        cin >> x;
        if(x >= 0) {
            at[abs(x)].push_back(i);
        }
        else {
            nat[abs(x)].push_back(i);
        }
    }
    pos[100001] = n;
    pos[100002] = n;
    segtree ne(n+1, "ne");
    for(int i=1;i<=1e5;++i) {
        pos[i] = cc;

        cc += at[i].size();
        ne.assign(pos[i], pos[i]+at[i].size(), di);

        cc += nat[i].size();
        ne.assign(pos[i]+at[i].size(), pos[i]+at[i].size()+nat[i].size(), en);
    }

    for(int i=0; i<q; ++i) {
        string s; int b;
        cin >> s >> b;
        if(s[0] == '>') {
            if(b >= -1) {
                //cerr << "type A" << endl;
                ne.assign(pos[b+1], n, en);
            } else if(b < -1) {
                ne.assign(0, pos[-b], fl);

                ne.assign(pos[-b], n, en);
            }
        } else {
            if(b <= 1) {
                ne.assign(pos[-b+1], n, di);
            }  else if(b > 1) {
                ne.assign(0, pos[b], fl);

                ne.assign(pos[b], n, di);
            }
        }
    }

    int cp = 0;
    for(int i=1;i<=1e5;++i) {
        for(auto& j : at[i]) {
            //cerr << " ! " << j << endl;
            ans[j] = i;
            //cerr << "  " << ne.get(cp) << " " << po.get(cp) << endl;
            if(ne.get(cp) == en) ans[j] *= -1;
            //cerr << " tag on ne(" << cp << ") = " << ne.get(cp) << "->" << i*(ne.get(cp) == en ? -1 : 1) << " " << ans[j] << endl;
        }
        cp += at[i].size();
        for(auto& j : nat[i]) {
            //cerr << " ! " << j << endl;
            ans[j] = i;
            //cerr << "  " << ne.get(cp) << " " << po.get(cp) << endl;
            if(ne.get(cp) == en) ans[j] *= -1;
            //cerr << " tag on ne(" << cp << ") = " << ne.get(cp) << "->" << i*(ne.get(cp) == en ? -1 : 1) << " " << ans[j] << endl;
        }
        cp += nat[i].size();
    }
    for(int i=0;i<n;++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}