#include <bits/stdc++.h>

using namespace std;

int V[500005];

int main() {
    int n;
    long long k;
    scanf("%d %I64d", &n, &k);

    if(n == 1) {
        cout << 0;
        return 0;
    }

    for(int i = 1; i <= n; ++i)
        scanf("%d", &V[i]);
    sort(V + 1, V + n + 1);

    int b = 1, e = n;
    int c1 = 1, c2 = 1;
    long long needup = V[2] - V[1], needdown = V[n] - V[n - 1], hasup = 0, hasdown = 0;

    long long s = 0;
    for(int i = 1; i <= n; ++i) {
        s += V[i];
    }
    int xxx;
    if(s % n == 0) xxx = 0;
    else xxx = 1;

    while(e - b >= 2) {

        if(needup < needdown) {
            if(k < needup)
                break;

            c1 += 1;
            b += 1;
            needdown -= needup;
            hasdown += needup;
            k -= needup;

            needup = 1LL * c1 * (V[b + 1] - V[b]);
            hasup = 0;
        } else {
            if(k < needdown)
                break;

            c2 += 1;
            e -= 1;
            needup -= needdown;
            hasup += needdown;
            k -= needdown;

            needdown = 1LL * c2 * (V[e] - V[e - 1]);
            hasdown = 0;
        }
    }

    assert(k >= 0);
    //Acum e - b == 1
    int first = V[b], last = V[e];
    first += (k + hasup) / c1;
    last -= (k + hasdown) / c2;
    cout << max(xxx, last - first);

    return 0;
}