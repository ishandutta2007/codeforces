#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
char t[1024][1024];
char tmp[1024][1024];

int dow[1024][1024];
int dseg[1024][1024];

int bans = -1;

int mvis[1024][1024];
int rim[1024][1024];
bool us[1024][1024];

void fun()
{
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (t[i][j] == '.')
            {
                dow[i][j] = 0;
            }
            else if (t[i][j] == 'X')
            {
                if (i + 1 >= n)
                    dow[i][j] = 1;
                else
                    dow[i][j] = 1 + dow[i + 1][j];
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (t[i][j] == 'X')
            {
                if (i == 0)
                    dseg[i][j] = dow[i][j];
                else
                    dseg[i][j] = max(dow[i][j], dseg[i - 1][j]);
            }
            else
                dseg[i][j] = 0;
        }
    }

    int sx, sy;
    sx = sy = -1;
    for (int i = 0; i < n && sx == -1; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (t[i][j] == 'X')
            {
                sx = i;
                sy = j;
                break;
            }
        }
    }

    if (sx == -1)
    {
        printf("-1\n");
        exit(0);
    }

    int st = dow[sx][sy];
    bool ok = true;
    memset(mvis, 0, sizeof(mvis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dow[i][j] >= st)
            {
                mvis[i][j] = 1;
            }
            if (dseg[i][j] < st && t[i][j] == 'X')
            {
                //~ printf("%d ; %d %d ; %d __ %d _ %c %c\n", dseg[i][j], i, j, st, dseg[i + 1][j], t[i][j], t[i + 1][j]);
                ok = false;
            }
        }
    }
    //~ printf("OK: %d\n", ok);
    if (ok)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            for (int i = 0; i < n; ++i)
            {
                if (!mvis[i][j])
                    rim[i][j] = 0;
                else
                {
                    if (j + 1 >= m)
                        rim[i][j] = 1;
                    else
                        rim[i][j] = 1 + rim[i][j + 1];
                }
            }
        }

        memset(us, 0, sizeof(us));
        int x, y;
        x = sx;
        y = sy;

        int miw = -1;
        int mxw = -1;
        while (1)
        {
            us[x][y] = 1;
            if (x + 1 < n && y < m && mvis[x + 1][y])
            {
                if (rim[x + 1][y] < rim[x][y])
                {
                    return;
                }
                if (miw == -1)
                    miw = rim[x][y];
                else
                {
                    miw = min(miw, rim[x][y]);
                }
                if (mxw == -1)
                    mxw = rim[x][y];
                else
                {
                    mxw = max(mxw, rim[x][y]);
                }
                x = x + 1;
            }
            else if (x < n && y + 1 < m && mvis[x][y + 1])
            {
                ++y;
            }
            else
                break;
        }
        //~ printf("MIW MXW %d %d\n", miw, mxw);
        if (miw == mxw)
        {
            bool ok2 = true;
            int cus = 0;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (mvis[i][j])
                        ++cus;
                    if (j == 0 || !mvis[i][j - 1])
                    {
                        if (mvis[i][j] && !us[i][j])
                        {
                            //~ printf("OP %d %d\n", i, j);
                            ok2 = false;
                        }
                    }
                }
            }
            if (miw == -1)
                miw = 1;
            //~ printf("OK2: %d\n", ok2);
            if (ok2)
            {
                if (bans == -1)
                    bans = miw * st;
                else
                    bans = min(bans, miw * st);
            }
            if (cus == 1)
            {
                if (bans == -1)
                    bans = 1;
                else
                    bans = min(bans, 1);
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", t[i]);
    }

    fun();
    //~ printf("F %d\n", bans);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            tmp[j][i] = t[i][j];
    }
    swap(n, m);
    memcpy(t, tmp, sizeof(t));

    fun();

    printf("%d\n", bans);
    
    return 0;
}