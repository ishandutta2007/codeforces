#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <bitset>
#define int228 long long
#define mp make_pair
#define pb push_back
#define POVAR 1488228228
#define X first
#define Y second
using namespace std;

int228 dp[5010][5010];
int n, m, k;
int228 p[5010], sum[5010], inf=1E18;

int main()
{
    cin >>n >> m >> k;
    for (int i=1; i<=n; i++) cin>> p[i], sum[i]=sum[i-1] + p[i];
    for (int i=0; i<5010; i++)
        for (int j=0; j<5010; j++)
            dp[i][j]=-inf;
    for (int i=0; i<=n; i++) dp[0][i]=0;
    for (int i=1; i<=k; i++)
    {
        for (int j=i*m; j<=n; j++)
            dp[i][j]=    max(dp[i][j-1], dp[i-1][j-m]+sum[j]-sum[j-m]);
    }
    cout<<  dp[k][n]<<  endl;
    return 228/1488;
}