#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<int> fi(MAXN), f(MAXN);

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &f[x]);
        fi[f[x]] = x;
    }
    vector<int> ff, ffi;
    for (int x = 1; x <= n; x++)
    {
        if (f[x] == 0)
            ff.push_back(x);
        if (fi[x] == 0)
            ffi.push_back(x);
    }
    if (!ff.empty())
    {
        for (int x = 0; x < ff.size(); x++)
        {
            if (ff[x] == ffi[x])
            {
                if (!x)
                    swap(ff[x], ff[x+1]);
                else
                    swap(ff[x], ff[x-1]);
            }
        }
        for (int x = 0; x < ffi.size(); x++)
            f[ff[x]] = ffi[x];
    }
    for (int x = 1; x <= n; x++)
        printf("%i ", f[x]);
    printf("\n");
}