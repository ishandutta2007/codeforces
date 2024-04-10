#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 60;
const int MX[4] = {-1, 1, 0, 0};
const int MY[4] = {0, 0, -1, 1};
const int INF = 1000000007;
const double PI = acos(-1.0);

string x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int xs, ys, xt, yt;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        for (int j = 0; j < x[i].size(); ++j) {
            if (x[i][j] == 'S') {
                xs = i;
                ys = j;
                x[i][j] = '.';
            }
            if (x[i][j] == 'E') {
                xt = i;
                yt = j;
                x[i][j] = '.';
            }
        }
    }
    string Q;
    cin >> Q;
    vector<int> D;
    for (int i = 0; i < 4; ++i) D.push_back(i);

    int ans = 0;
    do {
        int a = xs, b = ys;
        for (int i = 0; i < Q.size(); ++i) {
            a += MX[D[Q[i] - '0']];
            b += MY[D[Q[i] - '0']];
            if (a < 0 || a >= N || b < 0 || b >= M || x[a][b] == '#') break;
            if (a == xt && b == yt) {
                ++ans;
                break;
            }
        }
    } while (next_permutation(D.begin(), D.end()));
    cout << ans << endl;
    return 0;
}