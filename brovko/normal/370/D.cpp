#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m;
char a[2005][2005];

bool f(int A, int B, int C, int D, int i, int j)
{
    return ((i == A || i == C) && j >= B && j <= D || (j == B || j == D) && i >= A && i <= C);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int A = n, B = m, C = 0, D = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 'w')
            {
                A = min(A, i);
                B = min(B, j);
                C = max(C, i);
                D = max(D, j);
            }

    bool L = 1, R = 1, U = 1, d = 1;

    for(int i = A + 1; i < C; i++)
        if(a[i][B] == 'w')
            L = 0;

    for(int i = A + 1; i < C; i++)
        if(a[i][D] == 'w')
            R = 0;

    for(int i = B + 1; i < D; i++)
        if(a[A][i] == 'w')
            U = 0;

    for(int i = B + 1; i < D; i++)
        if(a[C][i] == 'w')
            d = 0;

    if(A == C)
    {
        if(A > n - 1 - C)
            U = 1;
        else d = 1;
    }

    if(B == d)
    {
        if(B > m - 1 - d)
            L = 1;
        else R = 1;
    }

    while(L && B > 0 && D - B < C - A)
        B--;

    while(R && D < m - 1 && D - B < C - A)
        D++;

    while(U && A > 0 && C - A < D - B)
        A--;

    while(d && C < n - 1 && C - A < D - B)
        C++;

    if(C - A != D - B)
    {
        cout << -1;
        return 0;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            bool F = f(A, B, C, D, i, j);

            if(F && a[i][j] == '.')
                a[i][j] = '+';

            if(!F && a[i][j] == 'w')
            {
                cout << -1;
                return 0;
            }
        }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << a[i][j];

        cout << "\n";
    }
}