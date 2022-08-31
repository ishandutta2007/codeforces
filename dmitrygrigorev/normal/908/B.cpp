#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    char matrix[n][m];
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    string s;
    cin >> s;
    vector<int> v;
    for (int i=0; i < 4; i++) v.push_back(i);
    int ans = 0;
    int x, y;
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            if (matrix[i][j] == 'S'){
                x=i, y=j;
            }
        }
    }
    int X = x, Y = y;
    do {
           x = X;
           y = Y;
            for (int i=0; i < s.size(); i++){
                int num = s[i] - '0';
                int r = v[num];
               // cout << r << endl;
                if (r == 0){
                    y--;
                }
                if (r == 1) y++;
                if (r == 2) x--;
                if (r == 3) x++;
                if (x < 0 || x >= n || y < 0 || y >= m) break;
                if (matrix[x][y] == '#') break;
                if (matrix[x][y] == 'E'){
                    ans++;
                    break;
                }
            }
            //cout << endl;
        } while(std::next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}