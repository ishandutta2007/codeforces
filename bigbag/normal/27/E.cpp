#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const long long inf = 1000000000000000000LL;
const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

long long n, ans;
vector <int> v;

void gener(vector <int> v) {
    int cnt = 0;
    long long ret = 1;
    for (int i = v.size() - 1; i >= 0; --i) {
        //cout << v[i] << ' ';
        for (int j = 1; j < v[i]; ++j) {
            if (ret > inf / p[cnt]) {
                ret = inf;
                break;
            }
            ret *= p[cnt];
        }
        ++cnt;
    }
    ans = min(ans, ret);
    if (v.size() == 1) {
        return;
    }
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (i != j) {
                vector <int> v1;
                v1.push_back(v[i] * v[j]);
                for (int k = 0; k < v.size(); ++k) {
                    if (k != i && k != j) {
                        v1.push_back(v[k]);
                    }
                }
                sort(v1.begin(), v1.end());
                gener(v1);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    long long k = n;
    for (int i = 2; i <= n; ++i) {
        if (k == 1) break;
        while (k % i == 0) {
            v.push_back(i);
            k /= i;
        }
    }
    ans = inf;
    gener(v);
    cout << ans << endl;
    return 0;
}