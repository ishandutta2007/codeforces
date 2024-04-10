#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;

}
const int max_x = 6 * max_n;
const int shift = 2 * max_n + 5;

int n, cnt[max_n][2], x[max_n], y[max_n];
string s[max_n];

//vector<int> more_add[max_x];
//vector<int> less_add[max_x];
int more_add[max_x], less_add[max_x];
//vector<int> more_del[max_x], less_del[max_x];

void clr() {
    for (int i = 0; i < max_x; ++i) {
        more_add[i] = -inf;
        less_add[i] = inf;
        //more_add[i].clear();
        //less_add[i].clear();

        //more_del[i].clear();
        //less_del[i].clear();
    }
}

int resx, resy;

bool check(int d) {
    clr();
    int lx = -inf, rx = inf;
    int ly = -inf, ry = inf;
    lx = shift;
    ly = 0;
    for (int i = 0; i < n; ++i) {
        lx = max(lx, x[i] - d);
        rx = min(rx, x[i] + d);

        ly = max(ly, y[i] - d);
        ry = min(ry, y[i] + d);
    }
    if (lx > rx || ly > ry) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        //less_add[x[i] - d].push_back(y[i] - (x[i] - d));
        //more_add[x[i]].push_back(y[i] - d - x[i]);

        less_add[x[i] - d] = min(less_add[x[i] - d], y[i] - (x[i] - d));
        more_add[x[i]] = max(more_add[x[i]], y[i] - d - x[i]);
    }
    int more = -inf, les = inf;
    for (int x = 0; x < max_x; ++x) {
        more = max(more, more_add[x]);
        les = min(les, less_add[x]);
        if (lx <= x && x <= rx) {
            int LY = max(ly, more + x);
            LY = max(LY, shift + 1 - x);
            int RY = min(ry, les + x);
            if (LY <= RY) {
                resx = x - shift;
                resy = LY;
                return true;
            }
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        s[i] = read();
        for (char c : s[i]) {
            ++cnt[i][c == 'B'];
        }
        x[i] = cnt[i][0];
        y[i] = cnt[i][1];
        x[i] += shift;
    }
    //cout << check(1) << endl;
    //return 0;
    int l = -1, r = 2 * max_n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%d\n", r);
    check(r);
    //cout << "$" << resx << " " << resy << endl;
    for (int i = 0; i < resx; ++i) {
        printf("N");
    }
    for (int i = 0; i < resy; ++i) {
        printf("B");
    }
    puts("");
    return 0;
}