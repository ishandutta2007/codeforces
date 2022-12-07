#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<iomanip>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
    const int maxn = 131072;
    static char buf[maxn],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
    int res(0);
    char c = getchar();
    while(c < '0') c = getchar();
    while(c >= '0') {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}

inline LL fastpo(LL x, LL n, LL mod) {
    LL res(1);
    while(n) {
        if(n & 1) {
            res = res * (LL)x % mod;
        }
        x = x * (LL) x % mod;
        n /= 2;
    }
    return res;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

inline string itoa(int x, int width = 0) {
    string res;
    if(x == 0) res.push_back('0');
    while(x) {
        res.push_back('0' + x % 10);
        x /= 10;
    }
    while((int)res.size() < width) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
    fwrite(buf, 1, _bl, stdout);
    _bl = 0;
}
__inline void _putchar(char c) {
    if(_bl == _B) flush();
    buf[_bl++] = c;
}
inline void print(LL x, char c) {
    static char tmp[20];
    int l = 0;
    if(!x) tmp[l++] = '0';
    else {
        while(x) {
            tmp[l++] = x % 10 + '0';
            x /= 10;
        }
    }
    for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
    _putchar(c);
}
struct P {
    D x, y;
};
const int N = 1550055;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int stmp;
struct E {
    int y, next;
} e[N * 2];
vector<int> pts[N];
int idx[N], is_bip[N], vst[N], col[N], q[N], blg[N];
vector<pair<int, pair<int, int> > > cnnts[N];
int l;
void build(int x, int y) {
    e[++l].y = y;
    e[l].next = idx[x];
    idx[x] = l;
}
bool bfs(int v) {
    int cl = 0;
    q[cl++] = v;
    vst[v] = stmp;
    col[v] = v * 2 + n;
    for(int op = 0; op < cl; op++) {
        int v = q[op];
        for(int p = idx[v]; p; p = e[p].next) {
            int y = e[p].y;
            if(blg[y] == blg[v] && stmp != vst[y]) {
                col[y] = col[v] ^ 1;
                vst[y] = stmp;
                q[cl++] = y;
            }else if(blg[y] == blg[v] && stmp == vst[y]) {
                if(col[y] != (col[v] ^ 1)) {
                    return false;
                }
            }else if(v <= n && blg[y] != blg[v] && stmp == vst[y]) {
                cnnts[blg[v]].pb({blg[y], {col[v], col[y]}});
                cnnts[blg[y]].pb({blg[v], {col[v], col[y]}});
                
                //build(col[v], col[y]);
                //build(col[y], col[v]);
            }
        }
    }
    return true;
}
int main() {
    l = 0;
    int k;
    n = getInt();
    m = getInt();
    k = getInt();
    for(int i = 1; i <= n; i++) {
        blg[i] = getInt();
        pts[blg[i]].pb(i);
    }
    for(int i = 1; i <= m; i++) {
        int x, y;
        x = getInt();
        y = getInt();
        build(x, y);
        build(y, x);
    }
    LL ans = 0, totbip = 0;
    stmp = 1;
    for(int i = 1; i <= k; i++) {
        is_bip[i] = true;
        for(int j = 0; j < (int)pts[i].size(); j++) {
            int v = pts[i][j];
            if(stmp != vst[v]) {
                is_bip[i] &= bfs(v);
            }
        }
        totbip += is_bip[i];
    }
    ans = (totbip * (totbip - 1)) / 2;
    for(int i = 1; i <= n; i++) {
        build(i * 2 + n, (i * 2 + n) ^ 1);
        build((i * 2 + n) ^ 1, i * 2 + n);
    }
    for(int i = 1; i <= k; i++) {
        int gp = i;
        if(is_bip[gp] == false) continue;
        sort(all(cnnts[i]));
        for(int j = 0, l; j < (int)cnnts[i].size(); j = l) {
            for(l = j; l < (int)cnnts[i].size() && cnnts[i][j].fi == cnnts[i][l].fi; l++);
            int smaller_gp = cnnts[i][j].fi;
            if(smaller_gp > gp || !is_bip[smaller_gp]) continue;
            stmp++;
            bool ok = true;
            static vector<pair<int, int> > bak;
            bak.clear();
            int bakl = ::l;
            for(int _ = j; _ < l; _++) {
                int x = cnnts[i][_].se.fi;
                int y = cnnts[i][_].se.se;
                bak.pb({x, idx[x]});
                bak.pb({y, idx[y]});
                build(x, y);                
                build(y, x);
            }
            for(int _ = j; _ < l; _++) {
                int x = cnnts[i][_].se.fi;
                int y = cnnts[i][_].se.se;
                if(vst[x] != stmp) {
                    ok &= bfs(x);
                }
                if(vst[y] != stmp) {
                    ok &= bfs(y);
                }
            }
            for(int _ = (int)bak.size() - 1; _ >= 0; _--) {
                idx[bak[_].fi] = bak[_].se;
            }
            ::l = bakl;
            if(!ok) {
                ans--;
            }
        }
    }
    cout << ans << endl;

}