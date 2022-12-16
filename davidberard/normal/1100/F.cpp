#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int LMAX = 21;

/*
struct basis {
    const int LMAX = 21;
    int cc;
    vector<int> v;
    basis() : v(LMAX, 0), cc(0) {}
    basis operator= (const basis& o) {
        v = o.v;
        cc=o.cc;
        return *this;
    }
    ~basis() {}
    void add(int n) {
        if(cc == LMAX) return;
        ////cerr << " !! "; for(int i=LMAX-1;i>=0;--i) //cerr << v[i] << " "; //cerr << endl;
    }
    void add(const basis& o) {
        for(int i=0;i<LMAX;++i) {
            if(o.v[i]) add(o.v[i]);
        }
    }
    int gmax() const {
        if(cc == LMAX) return (1<<LMAX)-1;
        int ans = 0;
        for(int i=LMAX-1;i>=0;--i) {
            if(!(ans&(1<<i))) {
                ans ^= v[i];
            }
        }
        return ans;
    }
};
*/

const int NMAX = 500500;

/*
 * Divind and conquer.
 * l[i] is the left point of query i
 * r[i] is the right point of query i
 * ans[i] is the answer to query i
 * lb[i] is the basis from i to mid, rb[i] is the basis from mid to i
 */
int l[NMAX], r[NMAX], ans[NMAX], v[NMAX];
int lb[NMAX][LMAX], rb[NMAX][LMAX], b[LMAX];

void add(int *v, int n) {
    for(int i=LMAX-1;i>=0;--i) {
        if(n&(1<<i)) {
            if(v[i]) {
                n ^= v[i];
            } else {
                v[i] = n;
                return;
            }
        }
    }
}
void add(int *v, int *u) {
    for(int i=0;i<LMAX;++i) {
        if(u[i]) add(v, u[i]);
    }
}
void copy(int *arr1, int *arr2) {
    for(int i=0;i<LMAX;++i) {
        arr2[i] = arr1[i];
    }
}
void clear(int *arr1) {
    for(int i=0;i<LMAX;++i) {
        arr1[i] = 0;
    }
}
int gmax(int *v) {
    int ans = 0;
    for(int i=LMAX-1;i>=0;--i) {
        if(!(ans&(1<<i))) {
            ans ^= v[i];
        }
    }
    return ans;
}

void solve(int L, int R, vector<int> queries, int minl, int maxr) {
    //cerr << " solve " << L << " " << R << " with "; for(auto& x : queries) //cerr << x << " "; //cerr << endl;
    if(R-L == 0) {
        for(auto& i : queries) {
            ans[i] = v[L];
        }
        return;
    }
    assert(R-L > 0);
    int m = (L+R+1)/2;
    vector<int> ql, qr;
    clear(lb[m-1]);
    clear(rb[m]);
    add(lb[m-1], v[m-1]);
    add(rb[m], v[m]);
    int minll = NMAX, maxrl=0, minlr = NMAX, maxrr = 0;
    for(int i=m-2;i>=minl;--i) {
        //cerr << " !!! " << i << endl;
        copy(lb[i+1], lb[i]);
        add(lb[i], v[i]);
    }
    for(int i=m+1;i<=maxr;++i) {
        //cerr << " !!! " << i << endl;
        copy(rb[i-1], rb[i]);
        add(rb[i], v[i]);
    }
    for(auto& i : queries) {
       if(l[i] >= m) {
            qr.push_back(i);
            minlr = min(minlr, l[i]);
            maxrr = max(maxrr, r[i]);
       } else if(r[i] < m) {
            ql.push_back(i);
            minll = min(minll, l[i]);
            maxrl = max(maxrl, r[i]);
       } else {
            copy(lb[l[i]], b);
            add(b, rb[r[i]]);
            //cerr << "b.gmax " << b.gmax() << endl;
            ans[i] = gmax(b);
       }
    }
    solve(L, m-1, ql, minll, maxrl);
    solve(m, R, qr, minlr, maxrr);
}

char get() {
    static char buf[100000], *S=buf, *T=buf;
    if(S==T) {
        T = (S=buf) + fread(buf, 1, 100000, stdin);
        if(S==T) return EOF;
    }
    return *S++;
}

void read(int& x) {
    static char c; x = 0;
    for(c=get();c<'0' || c>'9';c=get());
    for(;c >='0' && c <='9';c=get()) x = x*10+c-'0';
}

int n, q;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    read(n);
    for(int i=1;i<=n;++i) {
        read(v[i]);
    }
    read(q);
    vector<int> qu;
    int minl = NMAX, maxr = 0;
    for(int i=1;i<=q;++i) {
        read(l[i]);
        read(r[i]);
        minl = min(minl, l[i]);
        maxr = max(maxr, r[i]);
        qu.push_back(i);
    }
    solve(1, n, qu, minl, maxr);
    for(int i=1;i<=q;++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}