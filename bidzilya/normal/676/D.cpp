#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include <cassert>
using namespace std;

const int INF = 1e9;

inline int GetBit(int mask, int num) {
    return (mask >> num) & 1;
}

const int DIR_COUNT = 4;
const int DX[DIR_COUNT] = {-1, 0, 0, 1};
const int DY[DIR_COUNT] = {0, -1, 1, 0};
const int DOPPOSITE[DIR_COUNT] = {3, 2, 1, 0};
const int DROTATE[DIR_COUNT] = {2, 0, 3, 1};
//const int DROTATE[DIR_COUNT] = {1, 3, 0, 2};
const char DCHAR[DIR_COUNT] = {'U', 'L', 'R', 'D'};
const int DMASK[DIR_COUNT] = {1, 2, 4, 8};

inline int GetMask(const string& s) {
    int result = 0;
    for (int i = 0; i < 4; ++i) {
        if (s[i] == '1') {
            result += DMASK[i];
        }
    }
    return result;
}

inline int CharToMask(char c) {
    if (c == '+') {
        return GetMask("1111");
    } else if (c == '-') {
        return GetMask("0110");
    } else if (c == '|') {
        return GetMask("1001");
    } else if (c == '^') {
        return GetMask("1000");
    } else if (c == '>') {
        return GetMask("0010");
    } else if (c == '<') {
        return GetMask("0100");
    } else if (c == 'v') {
        return GetMask("0001");
    } else if (c == 'L') {
        return GetMask("1011");
    } else if (c == 'R') {
        return GetMask("1101");
    } else if (c == 'U') {
        return GetMask("0111");
    } else if (c == 'D') {
        return GetMask("1110");
    } else if (c == '*') {
        return GetMask("0000");
    }
    assert(false);
}

int n, m;
vector<vector<int>> gMask;

struct TCoord {
    int X;
    int Y;
    int R;
};

int CoordToVert(const TCoord& c) {
    return c.R * n * m + c.X * m + c.Y;
}

TCoord VertToCoord(int vert) {
    int r = vert / (n * m);
    vert %= (n * m);
    int x = vert / m;
    int y = vert % m;
    return TCoord{x, y, r};
}

int GetRotatedMask(int mask) {
    int result = 0;
    for (int i = 0; i < 4; ++i) {
        if (GetBit(mask, i)) {
            result += (1 << DROTATE[i]);
        }
    }
    return result;
}

int GetRotatedMask(int mask, int count) {
    for (int i = 0; i < count; ++i) {
        mask = GetRotatedMask(mask);
    }
    return mask;
}

bool Check(int m1, int m2, int d) {
    return GetBit(m1, d) && GetBit(m2, DOPPOSITE[d]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    gMask.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            gMask[i][j] = CharToMask(s[j]);
        }
    }

    int sx, sy;
    int fx, fy;
    cin >> sx >> sy >> fx >> fy;
    --sx;
    --sy;
    --fx;
    --fy;

    TCoord start{sx, sy, 0};

    int startVert = CoordToVert(start);

    vector<int> dist(4 * n * m, INF);

    queue<int> q;
    q.push(startVert);
    dist[startVert] = 0;
    while (!q.empty()) {
        int vert = q.front();
        q.pop();

        TCoord c = VertToCoord(vert);

        int m1 = GetRotatedMask(gMask[c.X][c.Y], c.R);

        for (int d = 0; d < 4; ++d) {
            int nx = c.X + DX[d];
            int ny = c.Y + DY[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                TCoord nc{nx, ny, c.R};
                int nvert = CoordToVert(nc);

                int m2 = GetRotatedMask(gMask[nx][ny], c.R);

                if (Check(m1, m2, d) && dist[nvert] == INF) {
                    dist[nvert] = dist[vert] + 1;
                    q.push(nvert);
                }
            }
        }

        {
            ++c.R;
            if (c.R == 4) {
                c.R = 0;
            }

            int newVert = CoordToVert(c);

            if (dist[newVert] == INF) {
                dist[newVert] = dist[vert] + 1;
                q.push(newVert);
            }

            --c.R;
            if (c.R < 0) {
                c.R += 4;
            }
        }
    }

    int minDist = INF;
    for (int r = 0; r < 4; ++r) {
        TCoord c{fx, fy, r};
        int vert = CoordToVert(c);

        minDist = min(minDist, dist[vert]);
    }

    if (minDist == INF) {
        cout << -1 << endl;
    } else {
        cout << minDist << endl;
    }

    return 0;
}