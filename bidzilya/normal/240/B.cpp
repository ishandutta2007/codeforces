#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;
const int MAX_INT = 1e9;

int n;
int h[201];
int s[201];
int a,b;
int dp[201][40001][2];

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> n >> a >> b;
    h[0] = 0;
    for (int i=1;i<=n;i++)
        cin >> h[i];
    s[0] = 0;
    for (int i=1;i<=n;i++)
        s[i] = s[i-1]+h[i];
    for (int i=0;i<=n;i++)
        for (int j=0;j<=a;j++)
            for (int k=0;k<2;k++)
                dp[i][j][k] = MAX_INT;
    dp[0][a][0]=dp[0][a][1]=0;
    for (int i=1;i<=n;i++)
        for (int aa=0;aa<=a;aa++)
            for (int pr_cl=0;pr_cl<2;pr_cl++)
                if (dp[i-1][aa][pr_cl]!=MAX_INT){
                    int bb = b - (s[i-1] - (a - aa));
                    int dh = min(h[i-1],h[i]);
                    if (bb>=h[i])
                        dp[i][aa][1] = min(dp[i][aa][1], min(dp[i-1][aa][0] + dh, dp[i-1][aa][1]));
                    if (aa>=h[i])
                        dp[i][aa-h[i]][0] = min(dp[i][aa-h[i]][0], min(dp[i-1][aa][0], dp[i-1][aa][1] + dh));
                }
    int res = MAX_INT;
    for (int i=0;i<=a;i++)
        res = min(res, min(dp[n][i][0], dp[n][i][1]));
    if (res==MAX_INT)
        cout << -1;
    else
        cout << res;
    cout << endl;
    return 0;
}