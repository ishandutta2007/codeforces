#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

#define MM 501

int n;
vi a;

int m1[MM][MM], m2[MM][MM], m3[MM][MM];
stack<ii> s1, s2;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

#define iiii pair<ii, ii>
queue<iiii> qu;

int& get(int a[MM][MM], int r, int c) {
    return a[r + MM / 2][c + MM / 2];
}

void leftrot() {
    for (int i = 0; i < MM; ++i)
    for (int f = 0; f < MM; ++f)
        m3[f][MM - i - 1] = m2[i][f];
}

void rightrot() {
    for (int i = 0; i < MM; ++i)
    for (int f = 0; f < MM; ++f)
        m3[MM - f - 1][i] = m2[i][f];
}

void print(int a[MM][MM]) {
//    for (int i = 0; i < MM; ++i) {
//        for (int f = 0; f < MM; ++f) {
//            clog << (a[i][f] ? '*' : '.');
//        }
//        clog << endl;
//    }
//    clog << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    memset(m1, 0, sizeof(m1));
    if (n & 1) {
        for (int i = 0; i < a.back(); ++i) get(m1, -i, 0) = 1;
        a.pop_back();
    }

    for (int i = sz(a) - 2; i >= 0; i -= 2) {
        memcpy(m2, m1, sizeof(m1));
        memset(m1, 0, sizeof(m1));
//        print(m1);
        print(m2);

        qu.push(iiii(ii(0, 0), ii(i, 0)));
        for (; qu.size(); qu.pop()) {
            int r = qu.front().xx.xx, c = qu.front().xx.yy;
            int id = qu.front().yy.xx, dir = qu.front().yy.yy;
            if (id == i + 2) break;
            for (int f = 0; f < a[id]; ++f) {
                get(m1, r, c) = 1;
                r += dr[dir];
                c += dc[dir];
            }
            r -= dr[dir], c -= dc[dir];
            for (int f = -1; f <= 1; f += 2) {
                int g = (dir + f + 8) % 8;
                qu.push(iiii(ii(r + dr[g], c + dc[g]), ii(id + 1, g)));
            }
        }
        for (; qu.size(); qu.pop()) {
            int r = qu.front().xx.xx, c = qu.front().xx.yy;
            int dir = qu.front().yy.yy;
            if (dir == 0) memcpy(m3, m2, sizeof(m2));
            else if (dir == 6) rightrot();
            else if (dir == 2) leftrot();
//            clog << dir << ' ' << r << ' ' << c << endl;
            print(m1);
            print(m3);
            for (int i = -MM / 2; i < MM / 2; ++i)
            for (int f = -MM / 2; f < MM / 2; ++f) {
                if (i + r < - MM / 2 or i + r >= MM / 2) continue;
                if (f + c < - MM / 2 or f + c >= MM / 2) continue;
                get(m1, i + r, f + c) |= get(m3, i, f);
            }
            print(m1);
        }
    }

    print(m1);

    long ans = 0;
    for (int i = 0; i < MM; ++i) {
        for (int f = 0; f < MM; ++f) {
            ans += m1[i][f];
        }
    }

    cout << ans;

    return 0;
}