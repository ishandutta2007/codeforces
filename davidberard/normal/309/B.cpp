#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 1001000;

int pfx[NMAX];
int f[NMAX][20]; // number of forward words, including current
string s[NMAX];
int n, r, c;

void buildf() {
    // i is first included
    int j = 1; // first excluded after i
    for(int i=1;i<=n;++i) {
        while(j<=n && pfx[j]-pfx[i-1]-1 <= c) {
            ++j;
        }
        f[i][0] = j;
        //cerr << "!! f " << i << " = " << f[i][0] << endl;
    }
    f[n+1][0] = n+1;
    for(int l=1;l<20;++l) {
        for(int i=1;i<=n+1;++i) {
            f[i][l] = f[f[i][l-1]][l-1];
        }
    }
}

void swim(int& x, int h) {
    for(int i=0;i<20;++i) {
        if(h&1) x = f[x][i];
        h>>=1;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> r >> c;
    for(int i=1;i<=n;++i) {
        cin >> s[i];
    }
    pfx[0] = 0;
    for(int i=1;i<=n;++i) {
        pfx[i] = pfx[i-1]+s[i].size()+1;
    }
    buildf();
    pii best(0, 0);
    for(int i=1;i<=n;++i) {
        int j=i;
        swim(j, r);
        //cerr << " -- " << i << " " << j << endl;
        best = max(best, pii(j-i, i));
    }
    //cerr << "!! " << best.first << endl;
    int p = best.second;
    int sz = 0;
    for(int i=0;i<r && sz < best.first;+i, p=f[p][0]) {
        for(int j=p;j<f[p][0]-1;++j) {
            cout << s[j] << " ";
            ++sz;
        }
        cout << s[f[p][0]-1] << "\n";
        ++sz;
    }
    return 0;
}