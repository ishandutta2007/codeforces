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

struct frozen
{
    int f;
    int x;
    int y;
    int X;
    int Y;
};

frozen upd(frozen a, int r, int c)
{
    a.f++;
    if (a.f == 1)
    {
        a.x = a.X = r;
        a.y = a.Y = c;
        return a;
    }
    a.x = min(a.x, r);
    a.X = max(a.X, r);
    a.y = min(a.y, c);
    a.Y = max(a.Y, c);
    return a;
}

int elsa(frozen a)
{
    return (a.X - a.x + 1) * (a.Y - a.y + 1);
}

int quix(frozen a)
{
    return a.X - a.x;
}

const int N = 100 + 7;
int n;
int m;
frozen r;
frozen g;
frozen b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            if (s[j - 1] == 'R') r = upd(r, i, j);
            if (s[j - 1] == 'G') g = upd(g, i, j);
            if (s[j - 1] == 'B') b = upd(b, i, j);
        }
    }
    if (r.f == g.f && g.f == b.f && elsa(r) == r.f && elsa(g) == g.f && elsa(b) == b.f && quix(r) == quix(b) && quix(b) == quix(g))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}