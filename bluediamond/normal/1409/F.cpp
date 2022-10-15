#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200 + 7;
int n;
int k;
int mx[N][N][N]; 
string s;
string t;

void upd(int &x, int val)
{
    x = max(x, val);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> k >> s >> t;
    s = " " + s;
    t = " " + t;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                mx[i][j][k] = -(int) 1e9;
            }
        }
    }
    mx[0][0][0] = 0;
    if (t[1] == t[2])
    {
        int eq = 0, nt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == t[1])
            {
                eq++;
            }
            else
            {
                nt++;
            }
        }
        eq += min(nt, k);
        cout << eq * (eq - 1) / 2 << "\n";
        return 0;
    }
    for (int pos = 0; pos < n; pos++)
    {
        for (int c = 0; c <= pos; c++)
        {
            for (int reps = 0; reps <= pos; reps++)
            {
                int val = mx[pos][c][reps];
                if (s[pos + 1] != t[1] && s[pos + 1] != t[2])
                {
                    upd(mx[pos + 1][c][reps], val);
                }
                if (s[pos + 1] == t[1])
                {
                    upd(mx[pos + 1][c + 1][reps], val);
                }
                if (s[pos + 1] == t[2])
                {
                    upd(mx[pos + 1][c][reps], val + c);
                }
                upd(mx[pos + 1][c + 1][reps + 1], val);
                upd(mx[pos + 1][c][reps + 1], val + c);
            }
        }
    }
    int sol = 0;
    for (int c = 0; c <= n; c++)
    {
        for (int reps = 0; reps <= k; reps++)
        {
            sol = max(sol, mx[n][c][reps]);
        }
    }
    cout << sol << "\n";
}