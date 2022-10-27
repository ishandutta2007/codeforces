#define  _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:6031)
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<bitset>
using namespace std;
 
typedef  long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<int, pair<int, int>> PIII;
typedef pair<double, double>pdd;
#define PI acos(-1)
 
int infinity1 = 0x7fffffff, infinity2 = 0x3f3f3f3f;
//double memset max:0x42,min:0xc2
//int const  P = 131;
 
 
double eps = 1e-9;
const int N = 1010, M = 2010, MOD = 998244353;
 
 
int g[N][N];
bitset<M>f[2][N];
int main()
{
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++)
            for (int j = 1; j <= m; j++) {
                scanf("%d", &g[i][j]);
            }
        int base = 1000;
        for (int j = 1; j <= m; j++) {
            f[0][j].reset();
        }
        f[0][1][base] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) {
                if (g[i][j] == 1)f[i & 1][j] = (f[i & 1][j - 1]>>1) | (f[i - 1 & 1][j]>>1);
                else  f[i & 1][j] = (f[i & 1][j - 1] << 1) | (f[i - 1 & 1][j] << 1);
            }
        }
        if (f[n & 1][m][base])puts("YES");
        else puts("NO");
    }
 
 
}