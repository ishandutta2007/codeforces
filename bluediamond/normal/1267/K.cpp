/**
The snow glows white on the mountain tonight
Not a footprint to be seen
A kingdom of isolation
And it looks like I'm the queen
The wind is howling like this swirling storm inside
Couldn't keep it in, heaven knows I've tried
Don't let them in, don't let them see
Be the good girl you always have to be
Conceal, don't feel, don't let them know
Well, now they know
Let it go, let it go
Can't hold it back anymore
Let it go, let it go
Turn away and slam the door
I don't care what they're going to say
Let the storm rage on
The cold never bothered me anyway
Let it go, let it go
Can't hold it back anymore
Let it go, let it go
Turn away and slam the door
Let it go (go, go, go go, go go, go go, go, go, go go)
Let it go
Let it go
Let it go
It's funny how some distance makes everything seem small
And the fears that once controlled me can't get to me at all
It's time to see what I can do
To test the limits and break through
No right, no wrong, no rules for me
I'm free
Let it go, let it go
I am one with the wind and sky
Let it go, let it go
You'll never see me cry
Here I stand and here I stay
Let the storm rage on
My power flurries through the air into the ground
My soul is spiraling in frozen fractals all around
And one thought crystallizes like an icy blast
I'm never going back, the past is in the past
Let it go
The cold never bothered me anyway
Let it go, let it go
And I'll rise like the break of dawn
Let it go, let it go
That perfect girl is gone
Here I stand in the light of day
Let the storm rage on
**/
#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

vector<ll> get(ll x)
{
    vector<ll> ans;
    for (ll i = 2; x; i++)
    {
        ans.push_back(x % i);
        x /= i;
    }
    return ans;
}

void print(vector<ll> a)
{
    for (auto &x : a)
    {
        cout << x << " ";
    }
    cout << "\n";
}

bool ok(vector<ll> a)
{
    if (a.back() == 0)
    {
        return 0;
    }
    for (ll i = 0; i < (ll) a.size(); i++)
    {
        if (a[i] > i + 1)
        {
            return 0;
        }
    }
    return 1;
}

ll dumb(ll x)
{
    vector<ll> a = get(x);
    sort(a.begin(), a.end());
    ll ans = 0;
    ans += ok(a);
    while (next_permutation(a.begin(), a.end()))
    {
        ans += ok(a);
    }
    return ans;
}

ll f[30];

ll when(ll x)
{
    if (x <= 1)
    {
        return 1;
    }
    else
    {
        return x;
    }
}

ll fct[100];

ll smart(ll x)
{
    if (x == 1)
    {
       // return 0;
    }
    vector<ll> a = get(x);
    for (ll i = 0; i < 30; i++)
    {
        f[i] = 0;
    }
    for (auto &x : a)
    {
        f[x]++;
    }
    /**cout << " ---> ";
    for (auto &x : a)
    {
        cout << x << " ";
    }
    cout << "\n";**/
    ll sz = (ll) a.size();
    ll ans = 0;
    for (ll ls = 1; ls <= 30; ls++)
    {
       // cout << "# " << ls << "\n";
        ll now = 1;
        if (f[ls] == 0)
        {
            continue;
        }
        now = f[ls];
        f[ls]--;
        /// 0 de la 1
        /// 1 de la 1
        /// 2 de la 2
        /// 3 de la 3
        if (ls == 2)
        {
      //      cout << "hello\n";
        }
        ll cur = 1;
        for (ll i = 1; i < sz; i++)
        {
            ll r = i;
            ll l = i;
            if (i == 1)
            {
                l--;
            }
            cur--;
            for (ll j = l; j <= r; j++)
            {
                cur += f[j];
            }
            if (ls == 2)
            {
             //   cout << i << " and " << sz << "\n";
            }
           // cout << i << " and " << cur << "\n";
            if (cur <= 0)
            {
                now = 0;
            }
           // cout << i << " and " << cur << "\n";
            now *= cur;
        }
        f[ls]++;
        ans += now;
    }
  //  cout << " = "
    for (ll i = 0; i < 30; i++)
    {
        ans /= fct[f[i]];
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fct[0] = 1;
    for (ll i = 1; i < 100; i++)
    {
        fct[i] = fct[i - 1] * i;
    }


    ll t;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        cout << smart(x) - 1 << "\n";
    }
}