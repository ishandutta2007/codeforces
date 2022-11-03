#include <iostream>
#include <algorithm>
#include <vector>

#include <cstring>
#include <cassert>
using namespace std;

typedef long long ll;

const int max_n = 111;

char a[max_n][max_n];
int n, m;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

char get_char(int x, int y)
{
    for (char c = 'A'; c <= 'Z'; ++c) {
        bool good = true;
        for (int i = 0; i < 4; ++i)
            if (a[x - dx[i]][y - dy[i]] == c) {
                good = false;
                break;
            }
        if (good) return c;
    }
    return '?';
}

int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < max_n; ++i)
        for (int j = 0; j < max_n; ++j)
            a[i][j] = '.';
            
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == '.') {
                a[i][j] = get_char(i, j);
                int len = 1;
                while (true) {
                    if (i + len > n || j + len > m) break;
                    if (get_char(i, j + len) < a[i][j]) break;
                    if (a[i - 1][j + len] == a[i][j]) break;
                    if (a[i + len][j - 1] == a[i][j]) break;
                    bool good = true;
                    for (int ni = i; ni <= i + len; ++ni)
                        if (a[ni][j + len] != '.' || a[ni][j + len + 1] == a[i][j]) {
                            good = false;
                            break;
                        }
                    for (int nj = j; nj <= j + len; ++nj)
                        if (a[i + len][nj] != '.' || a[i + len + 1][nj] == a[i][j]) {
                            good = false;
                            break;
                        }
                    if (!good) break;
                    for (int ni = i; ni <= i + len; ++ni)
                        a[ni][j + len] = a[i][j];
                    for (int nj = j; nj <= j + len; ++nj)
                        a[i + len][nj] = a[i][j];
                    ++len;
                }
            }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) 
            printf("%c", a[i][j]);
        printf("\n");
    }
    return 0;
}