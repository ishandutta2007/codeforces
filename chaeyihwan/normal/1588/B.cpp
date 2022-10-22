#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ask(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    ll ret; cin >> ret;
    return ret;
}

void ok(int i, int j, int k)
{
    cout << "! " << i << " " << j << " " << k << endl;
}

ll len(ll x)
{
    ll l = 1, r = 1000000000;
    while(l < r)
    {
        ll mid = (l + r)/2;
        ll R = mid * (mid-1) / 2;
        if(R == x) return mid;
        else if(R < x) l = mid + 1;
        else r = mid;
    }
    return l;
}

void asdf(int i, int k, ll M)
{
    int L = k - i + 1;
    ll l = 2, r = L/2;
    while(l < r)
    {
        ll mid = (l + r)/2;
        ll X = mid*(mid-1)/2 + (L-mid)*(L-mid-1)/2;
        if(X > M) l = mid + 1;
        else r = mid;
    }

    if(ask(i+l-1, i+l) == 0) ok(i, i+l, k);
    else ok(i, k-l+1, k);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        ll M = ask(1, n);
        ll x = 0, y = 0, l = 1, r = n;
        while(l < r)
        {
            y = (l + r)/2;
            x = ask(1, y);
            if(x == 0) l = y + 1;
            else if(x == M) r = y;
            else break;
        }
        ll xx = ask(1, y-1);

        ll K = x - xx;
        if(K * (K+1) / 2 == x)
        {
            int i, k; i = y - K;
            l = i;
            while(l < r)
            {
                ll mid = (l + r)/2;
                ll A = ask(i, mid);
                if(A == M) r = mid;
                else l = mid + 1;
            }
            k = l;
            asdf(i, k, M);
            continue;
        }
        int i, j, k;
        j = y - K;
        ll L = len(x - K*(K+1)/2);
        i = j - L ;
        ll R = len(M - L*(L-1)/2);
        k = j + R - 1;
        ok(i, j, k);
    }
}