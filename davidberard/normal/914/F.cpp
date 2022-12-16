#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 101000;
const int SQRT=320;
const int COUNT=N/SQRT+20;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

struct SuffixTree {
	enum { M = SQRT*2+20, ALPHA = 27 }; // N ~ 2*maxlen+10
	int toi(char c) { return c - 'a'; }
	//string a; // v = cur node, q = cur position
    char a[M];
	int t[M][ALPHA],l[M],r[M],p[M],s[M],v=0,q=0,m=2,cnt[M], asz;

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

    int mark_cnt(int x) {
        for (int i=0; i<ALPHA; ++i) {
            if (t[x][i] != -1) {
                cnt[x] += mark_cnt(t[x][i]);
            }
        }
        if (cnt[x] == 0) cnt[x] = 1;
        //cerr << " mark cnt " << x << " " << cnt[x] << endl;
        return cnt[x];
    }

    void build_b(const char *str, int lv, int rv) {
        //cerr << "! BUILD B " << endl;
	    v=0,q=0,m=2;
        for (int i=lv; i<rv; ++i) {
            a[i-lv] = str[i];
        }
        a[rv-lv] = 'z'+1;
        a[rv-lv+1] = 0;
        int asz = rv-lv+1;
		fill(r,r+M,asz);
		memset(s, 0, sizeof s);
		memset(t, -1, sizeof t);
        memset(cnt, 0, sizeof cnt);
		fill(t[1],t[1]+ALPHA,0);
		s[0] = 1; l[0] = l[1] = -1; r[0] = r[1] = p[0] = p[1] = 0;
		rep(i,0,asz) ukkadd(i, toi(a[i]));
        mark_cnt(0);
    }

    const char *bak_str;
    int bak_lv, bak_rv;
    bool lazy = 0;
    void build(const char *str, int lv, int rv) {
        lazy = 1;
        bak_str = str;
        bak_lv = lv;
        bak_rv = rv;
    }

    SuffixTree() {}

    void prepare() {
        if (lazy) {
            build_b(bak_str, bak_lv, bak_rv);
            lazy = 0;
        }
    }

    int count(const char* str) {
        prepare();
        int x = 0;
        int i = 0;
        while (str[i]) {
            x = t[x][toi(str[i])];
            if (x == -1) return 0;
            for (int j=l[x]; j<r[x]; ++j) {
                if (a[j] != str[i]) return 0;
                if (str[++i] == 0) return cnt[x];
            }
        }
        assert(false);
        return -1;
    }
};

SuffixTree st[COUNT];
char s[N]; // should be 0 ended
char t[N];
int n, m;
int fail[N];

void prep() {
    fail[0] = 0;
    ////cerr << " fail[0] = " << fail[0] << endl;
    for (int i=1; i<m; ++i) {
        int p = fail[i-1];
        while (p && t[p] != t[i]) {
            p = fail[p-1];
        }
        if (t[p] == t[i]) ++p;
        fail[i] = p;
        ////cerr << " fail[" << i << "] = " << fail[i] << endl;
    }
    fail[m] = 0;
}

int kmp(int l, int r) {
    ////cerr << " kmp " << l << " " << r << ": ";
    int p = 0;
    int ans = 0;
    for (int i=l; i<r; ++i) {
        while (p && s[i] != t[p]) {
            p = fail[p-1];
        }
        if (s[i] == t[p]) ++p;
        ////cerr << i << ":" << p << " ";
        if (p == m) ++ans;
    }
    ////cerr << endl;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    /*
    string za, zb;
    cin >> za >> zb;
    SuffixTree mst;
    mst.build(za.c_str(), 0, za.size());
    cerr << mst.count(zb.c_str()) << endl;
    return 0;
    */
    ////cerr << " ! " << sizeof(SuffixTree) << endl;
    cin >> s;
    n = strlen(s);
    for (int i=0; i<(n+SQRT-1)/SQRT; ++i) {
        st[i].build(s, i*SQRT, min(n, i*SQRT+SQRT));
    }
    int q;
    cin >> q;
    //cerr << "Q = " << q << endl;
    int x; char z[5];
    while (q--) {
        ////cerr << "? " << q << endl;
        int tt;
        cin >> tt;
        if (tt == 1) {
            cin >> x >> z;
            s[x-1] = z[0];
            int sec = (x-1)/SQRT;
            int y = (sec+1)*SQRT;
            char old = s[y];
            s[y] = 0;
            st[sec].build(s, sec*SQRT, min(sec*SQRT+SQRT, n));
            s[y] = old;
        } else if (tt == 2) {
            int l, r;
            cin >> l >> r >> t;
            --l;
            m = strlen(t);
            prep();

            if (m >= SQRT) {
                cout << kmp(l, r) << "\n";
            } else {
                int ans = 0;
                int beg = (l+SQRT-1)/SQRT;
                int lim = (r-1)/SQRT;
                if (beg < lim) {
                    //cerr << " beg lim " << beg << " " << lim << " : " << l << " " << r << endl;
                    for (int j=beg; j<lim; ++j) {
                        ans += st[j].count(t);
                        if (j != beg) {
                            ans += kmp(j*SQRT-m+1, j*SQRT+m-1);
                        }   
                    }
                    ans += kmp(l, min(SQRT*beg+m-1, n));
                    ans += kmp(max(lim*SQRT-m+1, 0), r);
                } else {
                    ans = kmp(l, r);
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}