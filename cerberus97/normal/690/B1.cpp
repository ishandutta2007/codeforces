#include <iostream>

using namespace std;

char a[51][51];

bool findTopLeft(int &r, int &c, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == '4')
            {
                r = i;
                c = j;
                return true;
            }
        }
    }

    return false;
}

bool findBottomRight(int &r, int &c, int n)
{
    for (int i = n - 1; i  >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            if (a[i][j] == '4')
            {
                r = i;
                c = j;
                return true;
            }
        }
    }

    return false;
}

bool getAns(int n, int ctr)
{

    int r1, c1, r2, c2;

    if (!findTopLeft(r1, c1, n) or !findBottomRight(r2, c2, n))
        return false;

    int r = r2 - r1 + 1, c = c2 - c1 + 1;
    int req = r*c;

    if (r1 > 0)
        req += c;

    if (r2 < n-1)
        req += c;

    if (c1 > 0)
        req += r;

    if (c2 < n-1)
        req += r;

    if (r1 > 0 and c1 > 0)
        ++req;

    if (r1 > 0 and c2 < n-1)
        ++req;

    if (r2 < n-1 and c1 > 0)
        ++req;

    if (r2 < n-1 and c2 < n-1)
        ++req;

    if (req != ctr)
        return false;

    for (int i = max(0, r1-1); i < min(n, r2+2); ++i)
    {
        for (int j = max(0, c1-1); j < min(n, c2+2); ++j)
        {
            if ((i < r1 or i > r2) and (j < c1 or j > c2))
            {
                if (a[i][j] != '1')
                    return false;
            }

            else if ((i < r1 or i > r2) or (j < c1 or j > c2))
            {
                if (a[i][j] != '2')
                    return false;
            }

            else if (a[i][j] != '4')
                return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, ctr = 0;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];

        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] != '0')
                ++ctr;
        }
    }

    if (getAns(n, ctr))
        cout << "Yes";

    else
        cout << "No";

    return 0;
}