#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_set>
using namespace std;

typedef long long ll;

int n;
vector<vector<int> > a;

bool solve(const vector<int>& vect)
{
    if (vect.size() <= 2) {
        return true;
    }

    int min_dist_val;
    int min_dist_v = vect[0];
    int min_dist_u = -1;
    for (int i = 1; i < (int) vect.size(); ++i) {
        int u = vect[i];
        if (min_dist_u == -1 || a[min_dist_v][u] < min_dist_val) {
            min_dist_val = a[min_dist_v][u];
            min_dist_u = u;
        }
    }

    vector<int> vect1, vect2;
    for (int i = 0; i < (int) vect.size(); ++i) {
        int w = vect[i];
        if (w != min_dist_v && w != min_dist_u) {
            if (a[w][min_dist_v] == a[w][min_dist_u]) {
                return false;
            }
            if (a[w][min_dist_v] + min_dist_val == a[w][min_dist_u]) {
                vect1.push_back(w);
            } else if (a[w][min_dist_u] + min_dist_val == a[w][min_dist_v]) {
                vect2.push_back(w);
            } else {
                return false;
            }
        } 
    }
    for (int i = 0; i < (int) vect1.size(); ++i) {
        for (int j = 0; j < (int) vect2.size(); ++j) {
            int w1 = vect1[i];
            int w2 = vect2[j];
            if (a[w1][min_dist_v] + min_dist_val + a[min_dist_u][w2] != a[w1][w2]) {
                return false;
            }
        }
    }
    vect1.push_back(min_dist_v);
    vect2.push_back(min_dist_u);
    
    return solve(vect1) && solve(vect2);
}

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(n);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (a[i][i] != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] != a[j][i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] == 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    
    vector<int> vect(n);
    for (int i = 0; i < n; ++i) {
        vect[i] = i;
    }

    if (solve(vect)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}