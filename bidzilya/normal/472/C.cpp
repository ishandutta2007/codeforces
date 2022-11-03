#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

typedef long long ll;

int n;
vector<string> a[2];
vector<int> p;
vector<bool> is_a[2];

int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < 2; ++i) {
        a[i].resize(n);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> a[j][i];
        }
    }
    
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    
    for (int i = 0; i < 2; ++i) {
        is_a[i].assign(n, false);
    }
    
    is_a[0][0] = is_a[1][0] = true;
    
    for (int i = 1; i < n; ++i) {
        for (int pj = 0; pj < 2; ++pj) {
            if (is_a[pj][i - 1]) {
                for (int nj = 0; nj < 2; ++nj) {
                    int id0 = p[i - 1];
                    int id1 = p[i];
                    
                    if (a[pj][id0] < a[nj][id1]) {
                        is_a[nj][i] = true;
                    }
                }
            }
        }
    }
    
    if (is_a[0][n - 1] || is_a[1][n - 1]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}