#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        vector<pair<int, int>> b;
        vector<bool> has(n, false);
        for (int i = 0; i < n; ++i) {
            int pos = a[i].find(c);
            if (pos != string::npos) {
                b.push_back(make_pair(i, pos));
                has[i] = true;
            }
        }
        if (b.empty()) {
            continue;
        }
        int maxLeft;
        int maxLeftIndex = -1;
        int maxRight;
        int maxRightIndex = -1;
        for (int i = 0; i < (int) b.size(); ++i) {
            int curLeft = b[i].second;
            int curRight = a[b[i].first].length() - b[i].second;

            if (maxLeftIndex == -1 || (curLeft > maxLeft)) {
                maxLeft = curLeft;
                maxLeftIndex = b[i].first;
            }
            if (maxRightIndex == -1 || (curRight > maxRight)) {
                maxRight = curRight;
                maxRightIndex = b[i].first;
            }
        }

        vector<string> newA;
        for (int i = 0; i < n; ++i) {
            if (!has[i]) {
                newA.push_back(a[i]);
            }
        }
        string withC;
        {
            int id = maxLeftIndex;
            for (int i = 0, end = a[id].find(c); i < end; ++i) {
                withC.push_back(a[id][i]);
            }
        }
        {
            int id = maxRightIndex;
            for (int i = a[id].find(c); i < (int) a[id].length(); ++i) {
                withC.push_back(a[id][i]);
            }
        }
        newA.push_back(withC);

        swap(a, newA);
        n = a.size();
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << endl;

    return 0;
}