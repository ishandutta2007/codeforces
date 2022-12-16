#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 5005000;

char s[N], t[N], ans[N], con[N*2];

char prv[N], srv[N], prv1[N], prv2[N];
int zfn[N*2];
int n;
int k;
vector<int> pos;
vector<int> is_pre;
vector<int> eq;

void duval() {
    int z=0;
    while (z<n) {
        int i=z, j=z+1;
        while (t[i] <= t[j]) {
            if (t[i] < t[j]) {
                i = z;
            } else if (t[i] == t[j]) {
                ++i;
            }
            ++j;
        }
        while (z<=i) {
            /*
            for (int q=z; q<z+j-i; ++q) {
                ////////cerr << t[q];
            }
            ////////cerr << "|";
            */
            //////////cerr << "  : " << z << " (" << n-z-1 << ")" << " " << i << " " << j << endl;
            pos.push_back(z);
            ////////cerr << " :: " << pos.back() << endl;
            eq.push_back(0);
            is_pre.push_back(0);
            z += j-i;
        }
    }
    //////////cerr << endl;
    for (int i=1; i<pos.size(); ++i) {
        int f1 = pos[i-1], f2 = pos[i], f3 = (i+1 == pos.size() ? n : pos[i+1]);
        if (f3-f2 <= f2-f1) {
            is_pre[i] = 1;
            for (int j=0; j<f3-f2; ++j) {
                if (t[j+f1] != t[j+f2]) {
                    is_pre[i] = 0;
                    break;
                }
            }
        }
        //if (f2-f1 != f3-f2) continue;
        eq[i] = is_pre[i] && (f2-f1 == f3-f2);
        /*
        for (int j=0; j<f3-f2; ++j) {
            if (t[j+f1] != t[j+f2]) {
                eq[i] = 0;
                break;
            }
        } */
    }
}

void insert_norm(int x, int l, int r) {
    for (int i=x, j=r-1; j>=l; --j, ++i) {
        ans[i] = t[j];
    }
}

void insert_rev(int x, int l, int r, char *str = ans){
    for (int i=x, j=l; j<r; ++j, ++i) {
        str[i] = t[j];
    }
}

void gen_zfn(const char* str, int m) {
    zfn[0] = 0;
    int l=0, r=0;
    for (int i=1; i<m; ++i) {
        if (i <= r) {
            zfn[i] = min(zfn[i-l], r-i+1);
        }
        while (i+zfn[i] < m && str[i+zfn[i]] == str[zfn[i]]) ++zfn[i];
        if (i+zfn[i]-1 > r) {
            l = i;
            r = i + zfn[i]-1;
        }

        // ////////cerr << " zfn " << i << " " << zfn[i] << endl;
    }
}

int compare(int m) {
    for (int i=0, j=n-m; i<m; ++i, ++j) {
        if (t[i] < s[j]) return -1;
        if (t[i] > s[j]) return 1;
    }
    return 0;
}

void solve_one(int m) {
    int r = compare(m);
    if (r > 0) {
        for (int i=n-m; i<n; ++i) {
            ans[i] = s[i];
        }
    } else {
        for (int i=n-m, j=0; i<n; ++i, ++j) {
            ans[i] = t[j];
        }
    }
}

void prv_fill(char *str, int x, int fin, int m) {
    insert_rev(0, x, fin, str);
    //cerr << " " << x << " " << str << endl;
    x = fin-x;
    if (x) {
        int r = compare(m-x);

        if (r > 0) {
            for (int i=x, j=n-m+x; j<n; ++i, ++j) {
                str[i] = s[j];
            }
        } else {
            for (int i=x, j=0; i<m; ++i, ++j) {
                str[i] = t[j];
            }
        }
    }
    str[m] = 0;
    //cerr << " : " << str << endl;
}

void solve_prv(int m) {
    int q = 0;
    while (q<pos.size()) {
        if (pos[q] == m) break;
        ++q;
    }

    int fin = (q == pos.size() ? n : pos[q]);
    --q;
    prv_fill(prv1, pos[q], fin, m);
    if (fin-pos[q] == 1) {
        while (eq[q]) --q;
    }

    if (is_pre[q]) --q;
    while (eq[q]) --q;
    prv_fill(prv2, pos[q], fin, m);

    int r = strcmp(prv1, prv2);
    if (r < 0) {
        strcpy(prv, prv1);
    } else {
        strcpy(prv, prv2);
    }
}

pair<int, char> suf_comp(int x, int m) { // returns size of shared match
    int z = zfn[m+1+x];
    //////////cerr << " : " << x << " : "<< z << " , " << z+m+1+x << " : '" << con[z] << "' '" << con[m+1+z+x] << "'" << " :: " << con[x] << endl;
    if (z+m+1+x == 2*m+1) return pair<int, char>(-1, '$');
    if (con[z] > con[m+1+z+x]) return pair<int, char>(-1, '$');
    return pair<int, char>(z, con[z]);
}

void solve_srv(int m) {
    //vector<int> best({int(1e9), 100, -1});
    int y = 0;
    for (int i=m-1; i>=0; --i) {
        int len = m-i;
        int z = zfn[m+1+i];
        ////cerr << " " << len << " ? " << z << endl;
        if (len - z - 1 >= y) {
            if (con[z] < con[m*2+1-len+z]) {
                y = len;
            }
        } else {
            int zz = zfn[len-y];
            ////cerr << " : " << zz << endl;
            if (zz < y && con[zz+len-y] < con[zz]) {
                y = len;
            }
        }
        /*
        auto pr = suf_comp(i, m);
        int r = pr.first;
        //////////cerr << " : " << r << endl;
        if (r < 0) continue;
        //best = min(best, vector<int>({i+r, pr.second, i}));
        best = min(best, pii((ll) (i+r)*256+pr.second, i));
        //////cerr << " : " << i+r << " " << pr.second << " " << i <<<endl;
        */
    }

    //int y = best[2];
    y = m-y;

    ////cerr << " : y " << y << endl;

    if (y == 0) {
        ////////cerr << " m = " << m << endl;
        for (int i=0, j=n-m; j<n; ++j, ++i) {
            srv[i] = s[j];
        }
        srv[m] = 0;
        return;
    }

    for (int i=0, j=n-m; i<y; ++i, ++j) {
        srv[i] = s[j];
    }
    for (int i=y, j=0; i<m; ++i, ++j) {
        srv[i] = t[j];
    }
    srv[m] = 0;

    ////cerr << "   SRV " << srv << endl;
}

void solve_two(int m) {
    for (int i=0; i<m; ++i) {
        con[i] = t[i];
    }
    con[m] = '$';
    for (int i=m+1, j=m-1; j>=0; --j, ++i) {
        con[i] = t[j];
    }
    gen_zfn(con, m*2+1);

    solve_prv(m);
    solve_srv(m);

    ////////cerr << "  PRV " << prv << endl;
    ////////cerr << "  SRV " << srv << endl;
    
    int r = strcmp(prv, srv);
    ////////cerr << " r = " << r << endl;
    char *src;
    if (r < 0) {
        //cerr << " USE PRV " << endl;
        src = prv;
    } else {
        //cerr << " USE SRV " << endl;
        src = srv;
    }
    
    for (int i=n-m, j=0; j<m; ++i, ++j) {
        ans[i] = src[j];
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    cin >> k;
    ////cerr << " : " << k << endl;
    n = strlen(s);
    for (int i=0; i<n; ++i) {
        t[i] = s[n-i-1];
    }

    duval();

    int q = pos.size();
    int x = 0;
    int dir = 0;
    for (int i=0; i<k-2 && q > 0; ++i) {
        int r = q;
        int fin = (q == pos.size() ? n : pos[q]);
        --q;
        int len = fin-pos[q];
        if (len == 1) {
            while (q>0 && pos[q]-pos[q-1]==1) {
                --q;
            }

            if (q == 0) {
                q = r;
                break;
            }

            insert_norm(x, pos[q], fin);
            x += fin-pos[q];
            continue;
        }

        while (eq[q]) --q;

        if (q == 0) {
            q = r;
            break;
        } else {
            insert_rev(x, pos[q], fin);
            x += fin-pos[q];
        }
    }

    assert (q != 0);
    if (k == 1) {
        //////////cerr << " !!!! " << endl;
        solve_one(q == pos.size() ? n : pos[q]);
    } else {
        //////////cerr << " :: s2" //<< endl;
        solve_two(q == pos.size() ? n : pos[q]);
    }
    ans[n] = 0;
    cout << ans << "\n";

    //cerr << " :: k = " << k << endl;

    /*
    const char * sixtyeight = "aaabehbieifhdddbieaiciiagfdciicaifeghbbfgfiadfac";
    //const char * sixtyseven = "aaaaaaabccbbcacbccabaacbacbccaaaacabaaabacbcbcbababbbb";
    int w = strlen(sixtyeight);
    s[w] = 0;
    if (strcmp(sixtyeight, s) == 0) return 1;
    */

    return 0;
}