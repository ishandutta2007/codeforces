#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;
vector<vector<int>> s22(vector<vector<int>> p){
    if(p[0][0] == 0 and
       p[0][1] == 0 and
       p[1][0] == 0 and
       p[1][1] == 0){
        return {};
    }
    if(p[0][0] == 0 and
       p[0][1] == 1 and
       p[1][0] == 1 and
       p[1][1] == 1){
        return {{0, 1, 1, 0, 1, 1}};
    }
    if(p[0][0] == 1 and
       p[0][1] == 0 and
       p[1][0] == 1 and
       p[1][1] == 1){
        return {{0, 0, 1, 0, 1, 1}};
    }
    if(p[0][0] == 1 and
       p[0][1] == 1 and
       p[1][0] == 0 and
       p[1][1] == 1){
        return {{0, 1, 0, 0, 1, 1}};
    }
    if(p[0][0] == 1 and
       p[0][1] == 1 and
       p[1][0] == 1 and
       p[1][1] == 0){
        return {{0, 1, 1, 0, 0, 0}};
    }
    vector<vector<int>> x;
    if(p[0][0] == 1 and
       p[0][1] == 1 and
       p[1][0] == 1 and
       p[1][1] == 1){
        x = {{0, 1, 1, 0, 1, 1}};
        p[0][1] = 0;
        p[1][0] = 0;
        p[1][1] = 0;
        vector<vector<int>> y = s22(p);
        x.insert(x.end(), y.begin(), y.end());
        return x;
    }
    if(p[0][0] == 1 and
       p[0][1] == 1 and
       p[1][0] == 0 and
       p[1][1] == 0){
        x = {{0, 1, 1, 0, 1, 1}};
        p[0][1] = 0;
        p[1][0] = 1;
        p[1][1] = 1;
        vector<vector<int>> y = s22(p);
        x.insert(x.end(), y.begin(), y.end());
        return x;
    }
    if(p[0][0] == 1 and
       p[0][1] == 0 and
       p[1][0] == 1 and
       p[1][1] == 0){
        x = {{0, 1, 1, 0, 1, 1}};
        p[0][1] = 1;
        p[1][0] = 0;
        p[1][1] = 1;
        vector<vector<int>> y = s22(p);
        x.insert(x.end(), y.begin(), y.end());
        return x;
    }
    if(p[0][0] == 0 and
       p[0][1] == 1 and
       p[1][0] == 0 and
       p[1][1] == 1){
        x = {{0, 1, 1, 0, 0, 0}};
        p[0][1] = 0;
        p[1][0] = 1;
        p[0][0] = 1;
        vector<vector<int>> y = s22(p);
        x.insert(x.end(), y.begin(), y.end());
        return x;
    }
    if(p[0][0] == 0 and
       p[0][1] == 0 and
       p[1][0] == 1 and
       p[1][1] == 1){
        x = {{0, 1, 1, 0, 0, 0}};
        p[0][1] = 1;
        p[1][0] = 0;
        p[0][0] = 1;
        vector<vector<int>> y = s22(p);
        x.insert(x.end(), y.begin(), y.end());
        return x;
    }
    if(p[0][0] == 1 and
       p[0][1] == 0 and
       p[1][0] == 0 and
       p[1][1] == 1){
        x = {{0, 1, 1, 0, 0, 0}};
        p[0][1] = 1;
        p[1][0] = 1;
        p[0][0] = 0;
        vector<vector<int>> y = s22(p);
        x.insert(x.end(), y.begin(), y.end());
        return x;
    }
    if(p[0][0] == 0 and
       p[0][1] == 1 and
       p[1][0] == 1 and
       p[1][1] == 0){
        x = {{0, 1, 1, 1, 0, 0}};
        p[0][1] = 0;
        p[1][1] = 1;
        p[0][0] = 1;
        vector<vector<int>> y = s22(p);
        x.insert(x.end(), y.begin(), y.end());
        return x;
    }
    if(p[0][0] == 1 and
       p[0][1] == 0 and
       p[1][0] == 0 and
       p[1][1] == 0){
        x = {{0, 0, 0, 1, 1, 1}};
        p[0][0] = 0;
        p[0][1] = 1;
        p[1][1] = 1;
        vector<vector<int>> y = s22(p);
        x.insert(x.end(), y.begin(), y.end());
        return x;
    }
    if(p[0][0] == 0 and
       p[0][1] == 1 and
       p[1][0] == 0 and
       p[1][1] == 0){
        x = {{0, 0, 0, 1, 1, 1}};
        p[0][0] = 1;
        p[0][1] = 0;
        p[1][1] = 1;
        vector<vector<int>> y = s22(p);
        x.insert(x.end(), y.begin(), y.end());
        return x;
    }
    if(p[0][0] == 0 and
       p[0][1] == 0 and
       p[1][0] == 1 and
       p[1][1] == 0){
        x = {{0, 0, 0, 1, 1, 0}};
        p[0][0] = 1;
        p[0][1] = 1;
        p[1][0] = 0;
        vector<vector<int>> y = s22(p);
        x.insert(x.end(), y.begin(), y.end());
        return x;
    }
    x = {{0, 0, 0, 1, 1, 1}};
    p[0][0] = 1;
    p[0][1] = 1;
    p[1][1] = 0;
    vector<vector<int>> y = s22(p);
    x.insert(x.end(), y.begin(), y.end());
    return x;
}
void oper1(vector<vector<int>> &ans, vector<vector<int>> &a, int x1, int y1, int x2, int y2, int x3, int y3){
    ans.push_back({x1,y1,x2,y2,x3,y3});
    a[x1][y1] = 1 - a[x1][y1];
    a[x2][y2] = 1 - a[x2][y2];
    a[x3][y3] = 1 - a[x3][y3];
}
void PolnalyubviTop(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(auto &i : a) for(auto &j : i) {
            char k;
            cin >> k;
            j = k - '0';
        }
    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1){
                if (j + 1 < m) { oper1(ans, a, i, j, i + 1, j, i + 1, j + 1); }
                else { oper1(ans, a, i, j, i + 1, j, i + 1, j - 1); }
            }
        }
    }
    for (int j = 0; j < m - 2; ++j) {
        for (int i = n-2; i < n; ++i) {
            if (a[i][j] == 1){
                oper1(ans, a, i, j, n - 1, j + 1, n - 2, j + 1);
            }
        }
    }
    vector<vector<int>> p = {{a[n-2][m-2], a[n-2][m-1]}, {a[n-1][m-2], a[n-1][m-1]}};
    vector<vector<int>> q = s22(p);
    for (auto & i : q) {
        for (int j = 0; j < 6; ++j) {
            if(j % 2 == 0)
                i[j] += n - 2;
            else
                i[j] += m - 2;
        }
    }
    ans.insert(ans.end(), q.begin(), q.end());
    cout << ans.size() << '\n';
    for(auto i : ans)
        cout << i[0] + 1 << ' ' << i[1] + 1 << ' ' << i[2] + 1 << ' ' << i[3] + 1 << ' ' << i[4] + 1 << ' ' << i[5] + 1 << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}