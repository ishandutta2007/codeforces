#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int M = 1000000007;
const int N = 51;
const int S = 2501;

void inc(int& a, int d) {
    a += d;
    if (a >= M)
        a -= M;
}

int a[N][S];
int bc[N][N][S];
int ways[N][N][N][4];

int main() {
    int n, T;
    cin >> n >> T;

    vector<int> cnts(4);
    vector<int> durs(4);

    a[0][0] = bc[0][0][0] = 1;
    forn(i, n) {
        int dur, type;
        cin >> dur >> type;
        type--;
        if (type == 0) {
            for (int cnts0 = cnts[0]; cnts0 >= 0; cnts0--)
                forn(durs0, durs[0] + 1)
                    inc(a[cnts0 + 1][durs0 + dur], a[cnts0][durs0]);
        } else {
            for (int cnts1 = cnts[1]; cnts1 >= 0; cnts1--)
                for (int cnts2 = cnts[2]; cnts2 >= 0; cnts2--)
                    forn(durs12, durs[1] + durs[2] + 1)
                        inc(bc[cnts1 + (type == 1)][cnts2 + (type == 2)][durs12 + dur],
                            bc[cnts1][cnts2][durs12]);
        }
        cnts[type]++;
        durs[type] += dur;
    }

    ways[0][0][0][3] = 1;
    vector<int> c(3);
    for (c[0] = 0; c[0] <= cnts[0]; c[0]++)
        for (c[1] = 0; c[1] <= cnts[1]; c[1]++)
            for (c[2] = 0; c[2] <= cnts[2]; c[2]++)
                forn(lst, 4)
                    if (ways[c[0]][c[1]][c[2]][lst] != 0) {
                        forn(nxt, 3)
                            if (nxt != lst && c[nxt] + 1 <= cnts[nxt]) {
                                vector<int> cn(c);
                                cn[nxt]++;
                                inc(ways[cn[0]][cn[1]][cn[2]][nxt], ways[c[0]][c[1]][c[2]][lst]);
                            }
                    }

    vector<int> f(N + 1, 1);
    forn(i, N)
        f[i + 1] = ((long long) f[i]) * (i + 1) % M;

    int result = 0;
    for (c[0] = 0; c[0] <= cnts[0]; c[0]++)
        forn(durs0, durs[0] + 1)
            if (T - durs0 >= 0)
                for (c[1] = 0; c[1] <= cnts[1]; c[1]++)
                    for (c[2] = 0; c[2] <= cnts[2]; c[2]++) {
                        long long extra = (long long)(a[c[0]][durs0]) * bc[c[1]][c[2]][T - durs0] % M;
                        forn(i, 3)
                            extra = extra * f[c[i]] % M;
                        forn(lst, 3)
                            if (c[lst] > 0)
                                inc(result, extra * ways[c[0]][c[1]][c[2]][lst] % M);
                    }
    
    cout << result << endl;
}