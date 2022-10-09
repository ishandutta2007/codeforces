#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

#define maxn 301010
int n;
pair<llong, int> s[maxn];
llong t[maxn];

vector<tuple<int, int, llong>> steps;
void do_move(int u, int v, llong d) {
    // clog << "do move " << u << ' ' << v << ' ' << d << endl;
    int i = s[u].yy; 
    int j = s[v].yy;
    s[u].xx += d;
    s[v].xx -= d;
    steps.emplace_back(i, j, d);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) {
        cin >> s[i].xx;
        s[i].yy = i + 1;
    }
    rep(i, n) cin >> t[i];
    sort(s, s + n);
    sort(t, t + n);
    // rep(i, n) clog << s[i].xx << ':' << t[i] << ' ';
    // clog << endl;
    int move_left = 0, move_right = 0;

    while (true) {
        while (move_left < n and s[move_left].xx <= t[move_left]) ++ move_left;
        while (move_right < n and s[move_right].xx >= t[move_right]) ++ move_right;
        if (move_left == n or move_right == n) break;
        if (move_left < move_right) break;
        // clog << s[move_left].xx << ' ' << t[move_left] << endl;
        do_move(move_right, move_left, min(s[move_left].xx - t[move_left], t[move_right] - s[move_right].xx));
    }

    if (move_left != n or move_right != n) 
        cout << "NO";
    else {
        cout << "YES\n";
        cout << len(steps) << '\n';
        for (auto i: steps) {
            cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << '\n';
        }
    }

    return 0;
}