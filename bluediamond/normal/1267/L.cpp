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

const int N = 1000 + 7;
int n;
int ln;
int k;
int f[26];
string s;
int ans[N][N];
bool eq[N];
int np;
int np2 = 25;

int gmn()
{
    while (f[np] == 0)
    {
        np++;
    }
    return np;
}

int gmx()
{
    while (f[np2] == 0)
    {
        np2--;
    }
    return np2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> ln >> k >> s;
    for (auto &ch : s)
    {
        int x = ch - 'a';
        f[x]++;
    }
    for (int i = 1; i < n; i++)
    {
        eq[i] = 1;
    }
    /// are they still equal????
    for (int itr = 1; itr <= ln; itr++)
    {
        vector<pair<int, int>> intvs;
        int i = 1;
        while (i <= n)
        {
            int j = i;
            while (j < n && eq[j])
            {
                j++;
            }
            if (j < n && eq[j])
            {
                j++;
            }
            intvs.push_back({i, j});
            i = j + 1;
        }
        for (auto &it : intvs)
        {
            int l = it.first;
            int r = it.second;
            if (l <= k && k <= r)
            {
                for (int i = l; i <= k; i++)
                {
                    ans[i][itr] = gmn();
                    f[gmn()]--;
                }
                for (int i = r; i > k; i--)
                {
                    ans[i][itr] = gmx();
                    f[gmx()]--;
                }
            }
            else
            {
                for (int i = r; i >= l; i--)
                {
                    ans[i][itr] = gmx();
                    f[gmx()]--;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (eq[i] && ans[i][itr] != ans[i + 1][itr])
            {
                eq[i] = 0;
            }
        }
    }
  //  return 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= ln; j++)
        {
            cout << (char) (ans[i][j] + 'a');
        }
        cout << "\n";
    }

}