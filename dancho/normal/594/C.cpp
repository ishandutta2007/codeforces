#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

struct ema {
    long long val;
    int id;
    bool operator<(const ema &el) const {
        return val < el.val;
    }
};

struct emi {
    long long val;
    int id;
    bool operator<(const emi &el) const {
        return val > el.val;
    }
};

int n, k;

struct po { 
    long long x, y, id;
};

po in[1 << 20];
vector<int> v;
int mxxt, mxyt, mixt, miyt;
vector<ema> mxx, mxy;
vector<emi> mix, miy;

bool us[1 << 20];

void fixup() {
    while (us[mxx[mxxt].id]) {
        --mxxt;
    }
    while (us[mxy[mxyt].id]) {
        --mxyt;
    }
    while (us[mix[mixt].id]) {
        --mixt;
    }
    while (us[miy[miyt].id]) {
        --miyt;
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        long long mx, my;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        mx = x1 + x2;
        my = y1 + y2;
        
        ema eM;
        eM.val = mx;
        eM.id = i;
        mxx.push_back(eM);
        
        eM.val = my;
        mxy.push_back(eM);

        emi em;
        em.val = mx;
        em.id = i;
        mix.push_back(em);
        
        em.val = my;
        miy.push_back(em);
        in[i].x = mx;
        in[i].y = my;
    }
    sort(mix.begin(), mix.end());
    sort(mxx.begin(), mxx.end());
    sort(miy.begin(), miy.end());
    sort(mxy.begin(), mxy.end());
    mixt = mxxt = miyt = mxyt = n - 1;

    memset(us, 0, sizeof(us));
    long long bar = (1LL << 60);
    for (int ma = 0; ma < (1 << (k * 2)); ++ma) {
        int x = ma;
        v.clear();
        for (int i = 0; i < k; ++i) {
            if (x % 4 == 0) {
                us[mxx[mxxt].id] = 1;
                v.push_back(mxx[mxxt].id);
            } else if (x % 4 == 1) {
                us[mxy[mxyt].id] = 1;
                v.push_back(mxy[mxyt].id);
            } else if (x % 4 == 2) {
                us[mix[mixt].id] = 1;
                v.push_back(mix[mixt].id);
            } else if (x % 4 == 3) {
                us[miy[miyt].id] = 1;
                v.push_back(miy[miyt].id);
            }
            fixup();
            x /= 4;
        }
        // printf("AA %lld %lld\n", mxx[mxxt].val, mix[mixt].val);
        long long wi = (mxx[mxxt].val - mix[mixt].val + 1) / 2;
        long long he = (mxy[mxyt].val - miy[miyt].val + 1) / 2;
        // wi = -wi;
        // he = -he;
        if (wi <= 0) {
            wi = 1;
        }
        if (he <= 0) {
            he = 1;
        }
        bar = min(bar, wi * he);
        for (int i = 0; i < (int) v.size(); ++i) {
            us[v[i]] = 0;
            long long mx = in[v[i]].x;
            long long my = in[v[i]].y;
        }
        mxxt = mxyt = mixt = miyt = n - 1;
    }
    printf("%lld\n", bar);
    return 0;
}