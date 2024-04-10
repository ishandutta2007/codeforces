//  228

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;

ll n, k, x;
ll a[N];

int check(ll now)
{
    ll move = 0;

    for(ll i = 1; i <= n; i++)
        move += min(a[i], now);
    if(move <= k)
        return 1;
    return 0;
}

int bs(ll l, ll r)
{
    ll mid, res=  0;
    while(l < r)
    {
        mid = (l + r + 1) >> 1;
        if(check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    return l;
}

int main(void)
{
    ll sum = 0;
    cin >> n >> k;
    
    for(ll i = 1; i <= n; i++)
    {
        scanf("%I64d", a + i);
        sum += a[i];
    }

    if(sum < k)
    {
        cout << -1;

        return 0;
    }

    ll turn = bs(0, 1e9 + 1);
    ll done = 0;

    for(int i = 1; i <= n; i++)
    {
        done += min(turn, a[i]);
        a[i] = max(0ll, a[i] - turn);
    }
    k -= done;
    vector <ll> s, e;

    for(ll i = 1; i <= n; i++)
    {
        if(a[i] > 0)
        {
            if(k > 0)
            {
                k--;
                if(a[i] > 1)
                    e.push_back(i);
            }
            else
            {
                s.push_back(i);
            }
        }
    }

    for(auto i : s)
        cout << i << ' ';
    for(auto i : e)
        cout << i << ' ';

    return 0;   
}