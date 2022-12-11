#include <iostream>

using namespace std;

char tb[500][500];
//int up[500][500];
//int down[500][500];
int lefts[500][500];
int downs[500][500];

int main()
{
    int h, w, i, j, q;
    cin >> h >> w;
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            cin >> tb[i][j];
            lefts[i][j] = 0;
            downs[i][j] = 0;
        }
    }
    for (i = 0; i < h - 1; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (tb[i][j] == '.' && tb[i + 1][j] == '.')
                downs[i][j] = 1;
        }
    }
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w - 1; j++)
        {
            if (tb[i][j] == '.' && tb[i][j + 1] == '.')
                lefts[i][j] = 1;
        }
    }
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (i > 0)
                downs[i][j] += downs[i - 1][j], lefts[i][j] += lefts[i - 1][j];
            if (j > 0)
                downs[i][j] += downs[i][j - 1], lefts[i][j] += lefts[i][j - 1];
            if (i > 0 && j > 0)
                downs[i][j] -= downs[i - 1][j - 1], lefts[i][j] -= lefts[i - 1][j - 1];
        }
    }
    cin >> q;
    int r1, c1, r2, c2;
    for (i = 0; i < q; i++)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        int sum = 0;
        if (r2 > 0)
        {
            sum += downs[r2 - 1][c2];
            if (r1 > 0)
                sum -= downs[r1 - 1][c2];
            if (c1 > 0)
                sum -= downs[r2 - 1][c1 - 1];
            if (r1 > 0 && c1 > 0)
                sum += downs[r1 - 1][c1 - 1];
        }
        if (c2 > 0)
        {
            sum += lefts[r2][c2 - 1];
            if (r1 > 0)
                sum -= lefts[r1 - 1][c2 - 1];
            if (c1 > 0)
                sum -= lefts[r2][c1 - 1];
            if (r1 > 0 && c1 > 0)
                sum += lefts[r1 - 1][c1 - 1];
        }
        cout << sum << endl;
    }
    return 0;
}