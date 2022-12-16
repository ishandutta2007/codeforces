#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int LG = 19;
const int N = 400400;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int par[N];
ll w[N];
ll pre[LG][N];
ll sum[LG][N];
int cnt = 1;

ll queries;

inline char get() {
    static char buf[100000], *S=buf, *T=buf;
    if (S == T) {
        T=(S=buf)+fread(buf, 1, 100000, stdin);
        if (S == T) return EOF;
    }
    return *S++;
}

void read(ll& x) {
    static char c; x = 0;
    for (c=get(); c<'0' || c>'9'; c=get());
    for (; c>='0' && c<='9'; c=get()) x = x*10+c-'0';
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    par[1] = 0;
    w[0] = INFLL;
    for (int i=0; i<LG; ++i) {
        sum[i][1] = INFLL;
    }

    read(queries);
    ll last = 0;

    for (int i=0; i<queries; ++i) {
        ll t, p, q;
        read(t); read(p); read(q);

        if (t == 1) {
            ll r = p^last;
            ll tw = q^last;

            int u = ++cnt;

            par[u] = r;
            w[u] = tw;

            int z = par[u];
            ll cur = 0;
            for (int h=LG-1; h>=0; --h) {
                if (w[pre[h][z]] < w[u]) {
                    z = pre[h][z];
                }
            }

            if (w[z] < w[u]) {
                z = pre[0][z];
            }

            pre[0][u] = z;
            for (int h=0; h<LG-1; ++h) {
                pre[h+1][u] = pre[h][pre[h][u]];
            }

            //cerr << " pre 0 " << u << " : " << pre[0][u] << endl;

            sum[0][u] = w[z];
            for (int h=0; h<LG-1; ++h) {
                sum[h+1][u] = min(INFLL, sum[h][u] + sum[h][pre[h][u]]);
                //cerr << " sum " << h+1 << " " << u << " : " << sum[h+1][u] << endl;
            }
        } else if (t == 2) {
            //cerr << " p last " << p << " " << last << endl;
            ll r = p^last;
            ll x = q^last;
            //cerr << "r x " << r << " " << x << endl;
            //cerr << " :: " << r << " " << w[r] << " " << x << endl;

            if (w[r] > x) {
                last = 0;
                cout << "0\n";
                continue;
            }

            ll len = 1;
            ll cur = w[r];

            for (int h=LG-1; h>=0; --h) {
                if (cur+sum[h][r] <= x) {
                    cur += sum[h][r];
                    len += (1<<h);
                    r = pre[h][r];
                }
            }

            last = len;
            cout << last << "\n";
        }

    }
    return 0;
}