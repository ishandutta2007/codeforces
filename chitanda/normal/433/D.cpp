#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define oo (1 << 30)

const int maxn = 1010;
int a[maxn][maxn], o, x, y;
int n, m, q, L[maxn][maxn], R[maxn][maxn], U[maxn][maxn], D[maxn][maxn];

int main(){
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", a[i] + j);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            L[i][j] = a[i][j] ? L[i][j - 1] + 1 : 0;
        for(int j = m; j >= 1; j--)
            R[i][j] = a[i][j] ? R[i][j + 1] + 1 : 0;
    }
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++)
            U[i][j] = a[i][j] ? U[i - 1][j] + 1 : 0;
        for(int i = n; i >= 1; i--)
            D[i][j] = a[i][j] ? D[i + 1][j] + 1 : 0;
    }
    for(int i = 1; i <= q; i++){
        scanf("%d %d %d", &o, &x, &y);
        if (o == 1){
            a[x][y] ^= 1;
            for(int j = 1; j <= m; j++)
                L[x][j] = a[x][j] ? L[x][j - 1] + 1 : 0;
            for(int j = m; j >= 1; j--)
                R[x][j] = a[x][j] ? R[x][j + 1] + 1 : 0;
                
            for(int i = 1; i <= n; i++)
                U[i][y] = a[i][y] ? U[i - 1][y] + 1 : 0;
            for(int i = n; i >= 1; i--)
                D[i][y] = a[i][y] ? D[i + 1][y] + 1 : 0;
        }else{
            if (!a[x][y]) printf("0\n");else{
                int up = oo, down = oo, ans = 0;
                for(int j = y; j >= 1; j--){
                    up = min(U[x][j], up), down = min(D[x][j], down);
                    ans = max(ans, (up + down - 1) * (y - j + 1));
                }
                
                up = oo, down = oo;
                for(int j = y; j <= m; j++){
                    up = min(U[x][j], up), down = min(D[x][j], down);
                    ans = max(ans, (up + down - 1) * (j - y + 1));
                }
                
                int left = oo, right = oo;
                for(int i = x; i >= 1; i--){
                    left = min(left, L[i][y]), right = min(right, R[i][y]);
                    ans = max(ans, (left + right - 1) * (x - i + 1));
                }
                        
                left = oo, right = oo;
                for(int i = x; i <= n; i++){
                    left = min(left, L[i][y]), right = min(right, R[i][y]);
                    ans = max(ans, (left + right - 1) * (i - x + 1));
                }       
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}