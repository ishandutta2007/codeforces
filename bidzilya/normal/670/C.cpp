#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, int> count;
    for (int i = 0; i < n; ++i) {
        ++count[a[i]];
    }

    int m;
    cin >> m;
    int result = -1;
    pair<int, int> resultScore;

    vector<int> x(m);
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
    }
    vector<int> y(m);
    for (int i = 0; i < m; ++i) {
        cin >> y[i];
    }

    for (int i = 0; i < m; ++i) {
        int cx = count[x[i]];
        int cy = count[y[i]];

        pair<int, int> score = make_pair(cx, cy);

        if (result == -1 || score > resultScore) {
            result = i;
            resultScore = score;
        }
    }

    cout << result + 1 << endl;

    return 0;
}