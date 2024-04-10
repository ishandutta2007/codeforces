#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200000 + 7;
const int INF = (int)1e9;
int n;
int a[N];
int l[N];
int r[N];
int stk[N];
int top;

int ur[N][40];
int nt[N][40];

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        cin >> n;
        for(int i = 1; i <= n; i++)
                cin >> a[i];

        top = 0;
        stk[top] = 0;

        for(int i = 1; i <= n; i++)
        {
                while(top && a[i] >= a[stk[top]])
                        top--;
                l[i] = stk[top] + 1;
                stk[++top] = i;
        }

        top = 0;
        stk[top] = n + 1;

        for(int i = n; i >= 1; i--)
        {
                while(top && a[i] > a[stk[top]])
                        top--;
                r[i] = stk[top] - 1;
                stk[++top] = i;
        }

        for(int x = 0; x <= 30; x++)
                ur[n + 1][x] = INF;
        for(int i = n; i >= 1; i--)
                for(int x = 0; x <= 30; x++)
                        if(a[i] & (1 << x))
                                ur[i][x] = i;
                        else
                                ur[i][x] = ur[i + 1][x];

        for(int x = 0; x <= 30; x++)
                nt[0][x] = -INF;
        for(int i = 1; i <= n; i++)
                for(int x = 0; x <= 30; x++)
                        if(a[i] & (1 << x))
                                nt[i][x] = i;
                        else
                                nt[i][x] = nt[i - 1][x];

        ll sol = 0;

        for(int i = 1; i <= n; i++)
        {
                int st = -INF, dr = INF;
                for(int x = 0; x <= 30; x++)
                        if(!(a[i] & (1 << x)))
                        {
                                st = max(st, nt[i][x]);
                                dr = min(dr, ur[i][x]);
                        }
                if(st < l[i])
                        st = l[i] - 1;
                if(dr > r[i])
                        dr = r[i] + 1;
                if(st <= dr)
                        sol += (r[i] - i + 1) * (ll)(i - l[i] + 1) - (i - st) * (ll)(dr - i);
        }
        cout << sol << "\n";

        return 0;
}