#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;

int n, a[MAXN];
string s[3];
int fen[MAXN];

void add_fen(int v, int val) {
    for (; v < MAXN; v+=v&-v)
        fen[v] += val;
}

int get_fen(int v) {
    int res = 0;
    for (; v; v-=v&-v)
        res += fen[v];
    return res;
}

int sec[MAXN], tl[MAXN], tr[MAXN], q, ans[MAXN];
int ugh[] = {0, 1, 1, 1, 1, 2, 1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < 3; i++) cin >> s[i];
    for (int c = 0; c < n; c++)
        a[c] = (s[0][c]-'0') | (s[1][c]-'0')<<1 | (s[2][c]-'0')<<2;
 
    cin >> q;
    for (int i = 0; i < q; i++)
        cin >> tl[i] >> tr[i], tl[i]--;
    iota(sec, sec + q, 0);
    sort(sec, sec + q, [](int q1, int q2) {
            return tr[q1] < tr[q2];
            });

    int cur = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        add_fen(i+1, ugh[a[i]]);
        add_fen(i+2, -ugh[a[i]]);
        if (i) {
            int common = __builtin_popcount(a[i] & a[i-1]);
            if (!common) {
                add_fen(1, ugh[a[i]]);
                add_fen(i+1, -ugh[a[i]]);
            } else {
                int me = __builtin_popcount(a[i]);
                if (me == 3) {
                    if(cnt == 0) {
                        ;
                    } else if (i-cnt-1 >= 0 && a[i-cnt-1] == 7) {
                        add_fen(i-cnt+1, -1);
                        add_fen(i+1, 1);
                    } else {
                        add_fen(1, -1);
                        add_fen(i+1, 1);
                    }
                } else if (a[i] == 5) {
                    if (common == 1) {
                        add_fen(1, 1);
                        add_fen(i+1, -1);
                    }
                }
            }
        }
        if (a[i] == 5)
            cnt++;
        else
            cnt = 0;
        
        while (cur < q && tr[sec[cur]] == i+1) {
            int x = sec[cur++];
            ans[x] = get_fen(tl[x] + 1);
        }
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
    return 0;
}