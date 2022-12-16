#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

struct pt {
    int x, y, z;
    pt() {}
    pt(int a, int b, int c) : x(a), y(b), z(c) {}
    inline pt operator+ (const pt& o) const { return pt(x+o.x, y+o.y, z+o.z); }
    inline pt operator- (const pt& o) const { return pt(x-o.x, y-o.y, z-o.z); }
    inline pt operator* (const int& o) const { return pt(x*o, y*o, z*o); }
    //pt operator/ (const pt& o) const { return pt(x/o, y/o, z/o); }
};

inline ll dp(const pt& a, const pt& b) {
    return (ll) a.x*b.x+(ll) a.y*b.y+(ll) a.z*b.z;
}

const int NMAX = 32300;

int n, m;

pt a, b, amb;
int amt[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    pt dir(1, 1, 1);
    a = pt(-1, 0, 1);
    b = pt(-1, 1, 0);
    amb = a-b;
    for(int i=m+1;i<=n/2+1;++i) {
        pt pi = b*(n+1) + amb*i;
        int j = n-m;
        int k = m+1;
        pt pj = a*j;
        pt pk = b*k;
        pt pji = pj-pi;
        pt pki = pk-pi;
        int cur = dp(pj-pi, pk-pi);
        int jd = -pji.x+pji.y;
        int kd = pki.x-pki.z;
        int jdlim = jd-(n-m)+(m+1);
        int kdlim = kd-(n-m)+(m+1);
        int ca = 0;
        for(;jd>=jdlim;) {
            while(cur >= 0 && kd >= kdlim /*k <= n-m */) {
                cur += jd;
                //cur += -pji.x+pji.y;
                //pki = pki + b;
                kd--;
                //k ++;
            }
            //if(k == (n-m+1)) break;
            //ans += (n-m+1)-k;
            ca += kd;//+1-kdlim;
            //j--;
            jd--;
            cur += kd;
        }
        amt[i] = ca+(n-2*m)*(1-kdlim);
    }
    ll ans = 0;
    for(int i=1;i<=n;++i) {
        int v = min(i, n+1-i);
        ans += amt[v];
    }
    cout <<  ans*3 << endl;
    

    return 0;
}