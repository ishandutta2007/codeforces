#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge
{
    int a, b, i;
};

bool operator < (const Edge& lhs, const Edge& rhs)
{
    return lhs.a < rhs.a;
}

bool Pick(int n, int& top, vector<int>& last, int& from, int& to)
{
    while (top < n) {
        if (last[top] < n) {
            from = top;
            to = last[top];
            ++last[top];
            return true;
        } else {
            ++top;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> e(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        e[i] = Edge{a, b, i};
    }

    vector<pair<int, int>> ans(m);

    sort(e.begin(), e.end());

    vector<int> last(n);
    for (int i = 0; i < n; ++i) {
        last[i] = i + 1;
    }
    int top = 1;
    int curN = 1;
    for (int i = 0; i < m; ++i) {
        int j = i;
        while (j + 1 < m && e[j + 1].a == e[i].a) {
            ++j;
        }

        for (int t = i; t <= j; ++t) {
            if (e[t].b) {
                ans[e[t].i].first = 0;
                ans[e[t].i].second = curN;
                ++curN;
                top = 1;
            }
        }
        
        for (int t = i; t <= j; ++t) {
            if (!e[t].b) {
                int from, to;
                if (Pick(curN, top, last, from, to)) {
                    ans[e[t].i].first = from;
                    ans[e[t].i].second = to;
                } else {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        i = j;
    }


    for (int i = 0; i < m; ++i) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }

    return 0;
}