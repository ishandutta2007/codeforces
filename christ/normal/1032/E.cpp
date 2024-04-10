#include <bits/stdc++.h>
using namespace std;
using i128 = long long;
const int MN = 103, MA = 1e4 + 3;
i128 all[MN][MA], freq[MN], ree[MN][MA];
int main() {
    int n,sum = 0,dis=0;
    scanf ("%d",&n); all[0][0] = 1;
    for (int i = 1; i <= 100; i++) ree[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf ("%d",&a); sum += a;
        if (++freq[a]==1) ++dis;
        for (int k = freq[a]*a; k >= a; k-=a) ree[a][k] += ree[a][k-a];
        for (int j = i; j >= 1; j--)
            for (int k = sum; k >= a; k--) all[j][k] += all[j-1][k-a];
    }
    if (dis <= 2) return !printf ("%d\n",n);
    int ret = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= freq[i]; j++) {
            if (all[j][j*i] == ree[i][j*i] || all[n-j][sum-j*i] == ree[i][j*i]) {
                ret = max(ret,j);
            }
        }
    }
    printf ("%d\n",ret);
    return 0;
}