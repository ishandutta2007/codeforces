#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string POSSIBLE = "Possible";
const string IMPOSSIBLE = "Impossible";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> signs;

    int n;
    while (true) {
        char c;
        cin >> c;

        if (c == '=') {
            cin >> n;
            break;
        }

        if (c == '?') {
            signs.push_back(1);
        } else if (c == '+') {
            signs.push_back(1);
            cin >> c;
        } else if (c == '-') {
            signs.push_back(-1);
            cin >> c;
        }
    }

    int m = signs.size();

    vector<int> lf(m + 1);
    vector<int> rg(m + 1);

    lf[0] = rg[0] = 0;
    for (int i = 0; i < m; ++i) {
        int cl;
        int cr;
        if (signs[i] == -1) {
            cl = -n;
            cr = -1;
        } else {
            cl = 1;
            cr = n;
        }

        lf[i + 1] = lf[i] + cl;
        rg[i + 1] = rg[i] + cr;
    }

    if (!(n >= lf[m] && n <= rg[m])) {
        cout << IMPOSSIBLE << endl;
        return 0;
    }

    cout << POSSIBLE << endl;
    vector<int> vals(m);

    int v = n;
    for (int i = m - 1; i >= 0; --i) {
        int cl;
        int cr;
        if (signs[i] == -1) {
            cl = -n;
            cr = -1;
        } else {
            cl = 1;
            cr = n;
        }
        int nvl = v - rg[i];
        int nvr = v - lf[i];

        nvl = max(nvl, cl);
        nvr = min(nvr, cr);

        vals[i] = nvl;

        v = v - vals[i];

        vals[i] = abs(vals[i]);
    }

    cout << vals[0] << " ";
    for (int i = 1; i < m; ++i) {
        if (signs[i] == -1) {
            cout << "- ";
        } else {
            cout << "+ ";
        }
        cout << vals[i] << " ";
    }
    cout << "= " << n << endl;

    return 0;
}