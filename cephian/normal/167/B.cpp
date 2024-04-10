#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<double> p_bag;
vector<int> bag_cap;
vector<double> p_tro;

double dp1[205][205][205];
double dp2[205][205];

double A(int x, int y, int z) {
    if(z <= 0) z = 0;
    if(x < 0) return y == 0 && z == 0;
    if(y < 0 || y > x+1) return 0;
    if(dp1[x][y][z] == -1)
        dp1[x][y][z] = A(x-1, y, z) *(1-p_bag[x]) + A(x-1, y-1, z - bag_cap[x]) * p_bag[x];
    // cout << x << "," << y << "," << z << " -> " << dp1[x][y][z] << "\n";
    return dp1[x][y][z];
}

double B(int x, int y) {
    if(x < 0) return y == 0;
    if(y < 0 || y > x+1) return 0;
    if(dp2[x][y] == -1)
        dp2[x][y] = B(x-1, y) * (1-p_tro[x]) + B(x-1, y-1) * p_tro[x];
    return dp2[x][y];
}

int n, l, k;
double p[205];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> l >> k;
    for(int i = 0; i < n; ++i)
        cin >> p[i];

    for(int i = 0; i < 205; ++i)
        for(int j = 0; j < 205; ++j)
            for(int k = 0; k < 205; ++k)
                dp1[i][j][k] = dp2[i][j] = -1;

    for(int i = 0; i < n; ++i) {
        int cap;
        cin >> cap;
        p[i] /= 100.0;
        if(cap == -1)
            p_tro.push_back(p[i]);
        else {
            p_bag.push_back(p[i]);
            bag_cap.push_back(cap);
        }
    }
    double ans = 0;
    for(int win = l; win <= n; ++win) {
        for(int tro_win = max(0, win - (int)p_bag.size()); tro_win <= min(win, (int)p_tro.size()); ++tro_win) {
            double p1 = B(p_tro.size()-1, tro_win);
            double p2 = p1 * A(p_bag.size()-1, win - tro_win, tro_win - k);
                        // cout << win << " and " << tro_win << " makes " << p2 << endl;
            ans += p2;
        }
    }
    cout << setprecision(15) << fixed;
    cout << ans << "\n";
    return 0;
}