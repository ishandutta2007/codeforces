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

typedef long long ll;
typedef long double ld;

const int N = 200 + 1;
const int K = N * 27 + 1;
int n;
int mt;
int dp[N][K];
ll x;
int a;
int b;

void put()
{
    a = 0;
    b = 0;
    while (x % 2 == 0)
    {
        x /= 2;
        a++;
    }
    while (x % 5 == 0)
    {
        x /= 5;
        b++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> mt;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            dp[i][j] = -(1 << 30);
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        put();
        for (int t = mt - 1; t >= 0; t--)
        {
            for (int j = 0; j + b < K; j++)
            {
                dp[t + 1][j + b] = max(dp[t + 1][j + b], dp[t][j] + a);
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < K; j++)
    {
        ans = max(ans, min(dp[mt][j], j));
    }
    cout << ans << "\n";
}