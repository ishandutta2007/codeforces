#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 10;
int n, s, t, l, r, mid, A[MXN];
int Solve(int c)
{
    if (abs(s - t) > c)
        return (0);
    set < int > S;
    S.insert(s);
    S.insert(t);
    for (int i = 1; i <= n; i++)
    {
        while (S.size() > 0 && abs(A[i] - *S.begin()) > c)
            S.erase(S.begin());
        while (S.size() > 0 && abs(A[i] - *S.rbegin()) > c)
            S.erase(*S.rbegin());
        if (S.size() == 0)
            return (0);
        S.insert(A[i]);
    }
    return (1);
}
int main()
{
    scanf("%d%d%d", &n, &s, &t);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    l = -1;
    r = 1e9;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        if (Solve(mid) == 1)
            r = mid;
        else
            l = mid;
    }
    printf("%d", r);
    return (0);
}