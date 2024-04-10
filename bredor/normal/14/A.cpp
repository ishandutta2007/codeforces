//  228

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define PI acos(-1)
#define EPS 1e-9
#define debug cerr <<
#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define case(tc) cout << "Case " << tc << ": ";
#define close << "\n";



int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifdef necromancer
    freopen("../input.txt", "r", stdin);
#endif

    int n,m;
    cin >> n >> m;
    char grid[n][m];
    char grid2[m][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            grid2[j][i] = grid[i][j];
        }
    }

    int up_down = 0;
    for (int i = 0; i < n; ++i) {
        bool contains = false;
        for (int j = 0; j < m; ++j) {
            if(grid[i][j] == '*'){
                contains = true;
                break;
            }
        }
        if(contains){
            up_down = i;
            break;
        }
    }

    int down_up = 0;
    for (int i = n-1; i >= 1; --i) {
        bool contains = false;
        for (int j = 0; j < m; ++j) {
            if(grid[i][j] == '*'){
                contains = true;
                break;
            }
        }
        if(contains){
            down_up = i;
            break;
        }
    }

    int left_right = 0;
    for (int i = 0; i < m; ++i) {
        bool contains = false;
        for (int j = 0; j < n; ++j) {
            if(grid2[i][j] == '*'){
                contains = true;
                break;
            }
        }
        if(contains){
            left_right = i;
            break;
        }
    }

    int right_left = 0;
    for (int i = m-1; i >= 1; --i) {
        bool contains = false;
        for (int j = 0; j < n; ++j) {
            if(grid2[i][j] == '*'){
                contains = true;
                break;
            }
        }
        if(contains){
            right_left = i;
            break;
        }
    }


    for (int i = up_down; i <= down_up; ++i) {
        for (int j = left_right; j <= right_left; ++j) {
            cout << grid[i][j];
        }
        cout close
    }


}