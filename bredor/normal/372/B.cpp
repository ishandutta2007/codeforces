#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <bitset>
#define int228 long long
#define mp make_pair
#define pb push_back
#define POVAR 1488228228
using namespace std;

int tp[50][50][50][50];
int s[50][50];

int main(){
    ios_base::sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    s[0][0] = a[0][0] == '1';
    for (int i = 1; i < n; ++i)
        s[i][0] = s[i - 1][0] + (a[i][0] == '1');
    for (int j = 1; j < m; ++j)
        s[0][j] = s[0][j - 1] + (a[0][j] == '1');
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j] - '0';

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            int p0 = tp[i][j][i][j] = a[i][j] == '0';
            for (int k = i + 1; k < n; ++k)
            {
                if (a[k][j] == '0')
                    ++p0;
                else
                    p0 = 0;
                tp[i][j][k][j] = tp[i][j][k - 1][j] + p0;
            }
            p0 = a[i][j] == '0';
            for (int k = j + 1; k < m; ++k)
            {
                if (a[i][k] == '0')
                    ++p0;
                else
                    p0 = 0;
                tp[i][j][i][k] = tp[i][j][i][k - 1] + p0;
            }
                for (int c = i + 1; c < n; ++c)
                    for (int d = j + 1; d < m; ++d){
                        tp[i][j][c][d] = tp[i][j][c - 1][d] + tp[i][j][c][d - 1] - tp[i][j][c - 1][d - 1];
                        int r = j;
                        if (a[c][d] == '1')
                            continue;
                        for (int h = c; h >= i; h--)
                        {
                            while (s[c][d] - ( r > 0 ? s[c][r - 1] : 0) - ( h > 0 ? s[h - 1][d] : 0) + ( (h > 0 && r > 0) ? s[h - 1][r - 1] : 0) )
                                r++;
                            if (r <= d)
                                tp[i][j][c][d] += d - r + 1;
                        }
                    }
        }
    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << tp[a - 1][b - 1][c - 1][d - 1] << endl; 
    }
    return 228 / 1488;   
}