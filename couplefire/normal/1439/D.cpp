#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, m, md, dp1[N], dp2[N], dp3[N][N], dp4[N][N], C[N][N];

int sum(int _x, int _y){
    _x += _y;
    if (_x >= md)
        _x -= md;
    return _x;
}

int mult(int _x, int _y) { return (1ll * _x * _y) % md; }

int arith(int x){
    return (x * (x + 1) / 2) % md;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> md;

    int mod = md;

    C[0][0] = 1;

    for (int i = 1; i < N; i++){
        C[i][0] = C[i][i] = 1;

        for (int j = 1; j < i; j++)
            C[i][j] = sum(C[i - 1][j], C[i - 1][j - 1]);
    }

    dp1[0] = 1;
    dp2[0] = 0;

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= i; j++){
            dp1[i] = sum(dp1[i], mult(C[i - 1][j - 1], mult(dp1[j - 1], dp1[i - j])));

            dp2[i] = sum(dp2[i], mult(mult(i + 1, C[i - 1][j - 1]), sum(mult(dp1[j - 1], dp2[i - j]), mult(dp2[j - 1], dp1[i - j]))));
            dp2[i] = sum(dp2[i], mult(mult(C[i - 1][j - 1], mult(dp1[j - 1], dp1[i - j])), sum(arith(j - 1), arith(i - j))));
        }

        dp1[i] = mult(i + 1, dp1[i]);
    }

    for (int j = 0; j <= m; j++)
    for (int i = j; i <= n; i++)
        if (i == j){
            dp3[i][j] = dp1[i];
            dp4[i][j] = dp2[i];
        } else {
            for (int l = 0; l <= j; l++){
                dp3[i][j] = sum(dp3[i][j], mult(mult(dp1[l], dp3[i - l - 1][j - l]), C[j][l]));

                dp4[i][j] = sum(dp4[i][j], mult(C[j][l], sum(mult(dp2[l], dp3[i - l - 1][j - l]), mult(dp1[l], dp4[i - l - 1][j - l]))));
            }
        }

    cout << dp4[n][m];

    return 0;
}