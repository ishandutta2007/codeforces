#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e5 + 10;
const int LOG = 19;

#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define tm lkajsdf

typedef pair<int, int> pii;

int sz;

struct SuffixTree {
    enum { N = MAXN + 10, C = 27 }; // N ~ 2*maxlen+10
    int toi(char c) { return c - 'a'; }
    string a; // v = cur node, q = cur position
    int t[N][C],l[N],r[N],p[N],s[N],v=0,q=0,m=2;
    int mp[2][N];
    int start[N], end[N], tm, depth[MAXN];
    int par[LOG][MAXN];

    void ukkadd(int i, int c) { suff:
        if (r[v]<=q) {
            if (t[v][c]==-1) { t[v][c]=m;  l[m]=i;
                p[m++]=v; v=s[v]; q=r[v];  goto suff; }
            v=t[v][c]; q=l[v];
        }
        if (q==-1 || c==toi(a[q])) q++; else {
            l[m+1]=i;  p[m+1]=m;  l[m]=l[v];  r[m]=q;
            p[m]=p[v];  t[m][c]=m+1;  t[m][toi(a[q])]=v;
            l[v]=q;  p[v]=m;  t[p[m]][toi(a[l[m]])]=m;
            v=s[p[m]];  q=l[m];
            while (q<r[m]) { v=t[v][toi(a[q])];  q+=r[v]-l[v]; }
            if (q==r[m])  s[m]=v;  else s[m]=m+2;
            q=r[v]-(q-r[m]);  m+=2;  goto suff;
        }
    }

    SuffixTree(string a) : a(a) {
        memset(mp, -1, sizeof(mp));
        memset(par, -1, sizeof(par));
        fill(r,r+N,sz(a));
        memset(s, 0, sizeof s);
        memset(t, -1, sizeof t);
        fill(t[1],t[1]+C,0);
        s[0] = 1; l[0] = l[1] = -1; r[0] = r[1] = p[0] = p[1] = 0;
        rep(i,0,sz(a)) ukkadd(i, toi(a[i]));
    }

    void calc_mappings(int v = 0, int ln = 0) {
        for (int w = 1; w < LOG; w++)
            if (~par[w-1][v])
                par[w][v] = par[w-1][par[w-1][v]];
            else
                par[w][v] = -1;

        start[v] = tm++;
        sz = max(sz, v + 1);
        if (v)
            ln += r[v] - l[v];
        depth[v] = ln;
        bool has_kids = false;
        for (int w = 0; w < C; w++)
            if (t[v][w] > 0) {
                par[0][t[v][w]] = v;
                has_kids = true, calc_mappings(t[v][w], ln);
            }

        if (!has_kids) {
            int suf = a.size() - ln;
            mp[0][suf] = v;
            mp[1][v] = suf;
        }
        end[v] = tm;
    }

    int get_anc(int v, int common) {
        assert(common <= depth[v]);
        assert(common > 0);
        for (int w = LOG-1; ~w; w--)
            if (~par[w][v] && depth[par[w][v]] >= common)
                v = par[w][v];
        return v;
    }
};

int n;
string s;
SuffixTree *st;
pii seg[MAXN<<2];

void upd_range(int v, int b, int e, int l, int r, pii val) {
    if (l <= b && e <= r) {
        seg[v] = max(seg[v], val);
        return;
    }
    if (r <= b || e <= l) return;

    int mid = b + e >> 1;
    upd_range(v<<1, b, mid, l, r, val);
    upd_range(v<<1^1, mid, e, l, r, val);
}

pii get_pos(int v, int b, int e, int pos, pii cur = {0, 0}) {
    cur = max(cur, seg[v]);
    if (e-b == 1)
        return cur;

    int mid = b + e >> 1;
    if (pos < mid)
        return get_pos(v<<1, b, mid, pos, cur);
    return get_pos(v<<1^1, mid, e, pos, cur);
}

int seg_min[MAXN<<2];
void upd_min(int v, int b, int e, int pos, int val) {
    if (e - b == 1) {
        seg_min[v] = val;
        return;
    }
    
    int mid = b + e >> 1;
    if (pos < mid)
        upd_min(v<<1, b, mid, pos, val);
    else
        upd_min(v<<1^1, mid, e, pos, val);
    seg_min[v] = min(seg_min[v<<1], seg_min[v<<1^1]);
}

int get_min(int v, int b, int e, int l, int r) {
    if (l <= b && e <= r) return seg_min[v];
    if (r <= b || e <= l) return 1e9;

    int mid = b + e >> 1;
    return min(get_min(v<<1, b, mid, l, r), get_min(v<<1^1, mid, e, l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(seg_min, seg_min+(MAXN<<2), (int)1e9);

    cin >> n >> s;
    s += char('z' + 1), n++;

    st = new SuffixTree {s};
    st->calc_mappings();
    int ans = 1;
    for (int i = n-1; ~i; i--) {
        int v = st->mp[0][i];
        auto [best_depth, ln] = get_pos(1, 0, sz, st->start[v]);
        ln = -ln;
        int my_best = best_depth + 1, shortest;
        if (best_depth == 0)
            shortest = 1;
        else {
            int anc = st->get_anc(v, ln);
            int mn = get_min(1, 0, sz, st->start[anc], st->end[anc]);
            assert(mn < 1e8);
            shortest = (mn + ln) - i;
        }

        ans = max(ans, my_best);
        upd_min(1, 0, sz, st->start[v], i);
        int anc = st->get_anc(v, shortest);
        upd_range(1, 0, sz, st->start[anc], st->end[anc], {my_best, -shortest});
    }
    cout << ans << "\n";
    return 0;
}