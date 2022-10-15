#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9;
const int N = 35;
const int W = 55;

int mn[N][N][W];


int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                        for (int k = 0; k < W; k++)
                                if (i * j == k || k == 0)
                                        mn[i][j][k] = 0;
                                else
                                        mn[i][j][k] = INF;


        for (int k = 1; k < W; k++)
                for (int i = 0; i < N; i++)
                        for (int j = 0; j < N; j++)
                                for (int k1 = 0; k1 <= k; k1++)
                                {
                                        int k2 = k - k1;
                                        for (int i1 = 0; i1 <= i; i1++)
                                        {
                                                int i2 = i - i1;
                                                mn[i][j][k] = min(mn[i][j][k], j * j + mn[i1][j][k1] + mn[i2][j][k2]);
                                        }
                                        for (int j1 = 0; j1 <= j; j1++)
                                        {
                                                int j2 = j - j1;
                                                mn[i][j][k] = min(mn[i][j][k], i * i + mn[i][j1][k1] + mn[i][j2][k2]);
                                        }
                                }

        int q;
        cin >> q;

        while (q--)
        {
                int i, j, k;
                cin >> i >> j >> k;
                cout << mn[i][j][k] << "\n";
        }


}