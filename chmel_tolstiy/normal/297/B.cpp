#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int  main() {
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> F;
    for (int i = 0; i < n; ++i)
    {
        int x; scanf("%d", &x);
        ++F[x];
    }
    for (int i = 0; i < m; ++i)
    {
        int x; scanf("%d", &x);
        --F[x];
    }
    vector<pii> V(F.begin(), F.end());
    reverse(V.begin(), V.end());

    int sum = 0;
    for (int i = 0; i < V.size(); ++i) {
        sum += V[i].second;
        if (sum > 0) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}