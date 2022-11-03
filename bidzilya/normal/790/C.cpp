#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int LIM = 76;
const int INF = 1e9;

int n;
string s;

int distK[LIM][LIM][LIM];
int distV[LIM][LIM][LIM];
int distZ[LIM][LIM][LIM];

int kCount;
int vCount;
int zCount;

int lastK[LIM][LIM][LIM];
int lastV[LIM][LIM][LIM];
int lastZ[LIM][LIM][LIM];

void Solve() {
    kCount = vCount = zCount = 0;
    for (int i = 0; i < n; ++i) {
        kCount += (s[i] == 'K');
        vCount += (s[i] == 'V');
        zCount += (s[i] != 'K' && s[i] != 'V');
    }
    for (int i = 0; i <= kCount; ++i) {
        for (int j = 0; j <= vCount; ++j) {
            for (int t = 0; t <= zCount; ++t) {
                distK[i][j][t] = distV[i][j][t] = distZ[i][j][t] = INF;
            }
        }
    }

    for (int i = 0; i <= kCount; ++i) {
        for (int j = 0; j <= vCount; ++j) {
            for (int t = 0; t <= zCount; ++t) {
                int ri = i;
                int rj = j;
                int rt = t;

                int pos = 0;
                for (int k = 0; k < n; ++k) {
                    if (s[k] == 'K' && ri > 0) {
                        --ri;
                    } else if (s[k] == 'V' && rj > 0) {
                        --rj;
                    } else if (s[k] != 'K' && s[k] != 'V' && rt > 0) {
                        --rt;
                    } else {
                        if (ri == 0 && s[k] == 'K') {
                            distK[i][j][t] = min(distK[i][j][t], pos);
                        }
                        if (rj == 0 && s[k] == 'V') {
                            distV[i][j][t] = min(distV[i][j][t], pos);
                        }
                        if (rt == 0 && s[k] != 'K' && s[k] != 'V') {
                            distZ[i][j][t] = min(distZ[i][j][t], pos);
                        }
                        ++pos;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= kCount; ++i) {
        for (int j = 0; j <= vCount; ++j) {
            for (int t = 0; t <= zCount; ++t) {
                lastK[i][j][t] = lastV[i][j][t] = lastZ[i][j][t] = INF;
            }
        }
    }

    lastK[0][0][0] = lastV[0][0][0] = lastZ[0][0][0] = 0;
    for (int i = 0; i <= kCount; ++i) {
        for (int j = 0; j <= vCount; ++j) {
            for (int t = 0; t <= zCount; ++t) {
                if (i + 1 <= kCount) {
                    lastK[i + 1][j][t] = min(lastK[i + 1][j][t], lastK[i][j][t] + distK[i][j][t]);
                }
                if (j + 1 <= vCount) {
                    lastV[i][j + 1][t] = min(lastV[i][j + 1][t], lastK[i][j][t] + distV[i][j][t]);
                }
                if (t + 1 <= zCount) {
                    lastZ[i][j][t + 1] = min(lastZ[i][j][t + 1], lastK[i][j][t] + distZ[i][j][t]);
                }

                if (j + 1 <= vCount) {
                    lastV[i][j + 1][t] = min(lastV[i][j + 1][t], lastV[i][j][t] + distV[i][j][t]);
                }
                if (t + 1 <= zCount) {
                    lastZ[i][j][t + 1] = min(lastZ[i][j][t + 1], lastV[i][j][t] + distZ[i][j][t]);
                }

                if (i + 1 <= kCount) {
                    lastK[i + 1][j][t] = min(lastK[i + 1][j][t], lastZ[i][j][t] + distK[i][j][t]);
                }
                if (j + 1 <= vCount) {
                    lastV[i][j + 1][t] = min(lastV[i][j + 1][t], lastZ[i][j][t] + distV[i][j][t]);
                }
                if (t + 1 <= zCount) {
                    lastZ[i][j][t + 1] = min(lastZ[i][j][t + 1], lastZ[i][j][t] + distZ[i][j][t]);
                }
            }
        }
    }

    const int result = min(
        lastK[kCount][vCount][zCount],
        min(
            lastV[kCount][vCount][zCount],
            lastZ[kCount][vCount][zCount]
        )
    );

    cout << result << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    cin >> s;
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}