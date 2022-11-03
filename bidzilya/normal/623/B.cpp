#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;

const long long INF = 1e18;

vector<int> GetPrimeDels(int x) {
    vector<int> result;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            result.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        result.push_back(x);
    }
    return result;
}

void Merge(const vector<int>& from, vector<int>& to) {
    for (int x : from) {
        to.push_back(x);
    }
}

long long GetElemCost(int elem, int d, long long elemCost) {
    if (elem % d == 0) {
        return 0;
    }
    if ((elem + 1) % d == 0 || (elem - 1) % d == 0) {
        return elemCost;
    }
    return INF;
}

long long GetResult(const vector<int>& a, long long segCost, long long elemCost, int d) {
    int n = a.size();
    static vector<vector<long long>> result;
    result.assign(n + 1, vector<long long>(3, INF));
    result[0][0] = result[0][1] = result[0][2] = 0;
    for (int i = 1; i <= n; ++i) {
        int elem = a[i - 1];

        result[i][2] = min(result[i][2], result[i - 1][2] + GetElemCost(elem, d, elemCost));
        result[i][2] = min(result[i][2], result[i - 1][1] + GetElemCost(elem, d, elemCost));

        result[i][1] = min(result[i][1], result[i - 1][0] + segCost);
        result[i][1] = min(result[i][1], result[i - 1][1] + segCost);

        result[i][0] = min(result[i][0], result[i - 1][0] + GetElemCost(elem, d, elemCost));
    }
    return min(min(result[n][0], result[n][1]), result[n][2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int segCost;
    int elemCost;
    scanf("%d%d%d", &n, &segCost, &elemCost);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<int> dels;
    for (int dx = -1; dx <= 1; ++dx) {
        Merge(GetPrimeDels(a[0] + dx), dels);
        Merge(GetPrimeDels(a[n - 1] + dx), dels);
    }

    sort(dels.begin(), dels.end());
    dels.resize(unique(dels.begin(), dels.end()) - dels.begin());

    long long result = INF;
    for (int d : dels) {
        result = min(result, GetResult(a, segCost, elemCost, d));
    }

    cout << result << endl;

    return 0;
}