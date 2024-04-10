#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <int> val;

vector <int> pos, hp;
vector <int> who;
int n, m;

void check(vector <int> order, int st) {
    assert(order.size() == m);
    for (int x : order) {
        int now = pos[x];
        int hpn = hp[x];
        while (now > st) {
            hpn += val[now];
            val[now] = 0;
            now--;
            if (hpn < 0) {
                cout << "WRONG!\n";
                for (int x : order) {
                    cout << x << " ";
                }
                cout << "\n" << st << "\n";
                exit(0);
            }
        }
        while (now < st) {
            hpn += val[now];
            val[now] = 0;
            now++;
            if (hpn < 0) {
                cout << "WRONG!\n";
                for (int x : order) {
                    cout << x << " ";
                }
                cout << "\n" << st << "\n";
                exit(0);
            }
        }
        hpn += val[st];
        val[st] = 0;
        if (hpn < 0) {
            cout << "WRONG!\n";
            for (int x : order) {
                cout << x << " ";
            }
            cout << "\n" << st << "\n";
            exit(0);
        }
    }
}

void solve() {
    cin >> n >> m;
    pos.resize(m);
    hp.resize(m);
    who.resize(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> pos[i] >> hp[i];
        pos[i]--;
        who[pos[i]] = i;
    }
    val.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int id = 0; id < n; id++) {
        vector <bool> used(m, 0);
        int hnow = 0;
        bool al = false;
        vector <int> lt;
        int fl = 0;
        for (int i = 0; i < id; i++) {
            if (who[i] != -1) {
                al = true;
                if (hp[who[i]] > hnow) {
                    lt.push_back(who[i]);
                    used[who[i]] = true;
                    hnow = hp[who[i]];
                }
            } else if (al && val[i] + hnow < 0) {
                fl = -1;
                break;
            } else if (!al) continue;
            hnow += val[i];
        }
        if (fl == -1) continue;
        if (hnow + val[id] >= 0) {
            fl = 1;
        }
        hnow = 0;
        vector <int> rt;
        al = false;
        for (int i = n - 1; i > id; i--) {
            if (who[i] != -1) {
                al = true;
                if (hp[who[i]] > hnow) {
                    rt.push_back(who[i]);
                    hnow = hp[who[i]];
                    used[who[i]] = true;
                }
            } else if (al && val[i] + hnow < 0) {
                fl = -1;
                break;
            } else if (!al) continue;
            hnow += val[i];
        }
        if (fl == -1) continue;
        if (hnow + val[id] >= 0) {
            fl = 2;
        }
        if (!fl) continue;
        cout << id + 1 << "\n";
        reverse(lt.begin(), lt.end());
        reverse(rt.begin(), rt.end());
        if (fl == 2) swap(lt, rt);
        for (int x : rt) {
            lt.push_back(x);
        }
        for (int i = 0; i < m; i++) {
            if (!used[i]) lt.push_back(i);
        }
        for (int x : lt) {
            cout << x + 1 << " ";
        }
        return;
    }
    cout << -1;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    solve();
}