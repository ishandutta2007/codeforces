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

const int N = 100 + 7;
int n;
int m;
int a[N][N];

vector<int> best(vector<int> a, vector<int> b)
{
    if ((int) a.size() < (int) b.size())
    {
        return a;
    }
    else
    {
        return b;
    }
}

void print(vector<int> a)
{
    cout << (int) a.size() << "\n";
    sort(a.begin(), a.end());
    for (auto &x : a)
    {
        cout << x << " ";
    }
    cout << "\n";
}

vector<int> sol;
int x[N];
int y[N];
int id[N];

bool cmp(int i, int j)
{
    return x[i] - y[i] > x[j] - y[j];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    sol.resize(1007);
    for (int col = 1; col < m; col++)
    {
        vector<int> now;
        for (int i = 1; i <= n; i++)
        {
            x[i] = a[i][col];
            y[i] = a[i][m];
            id[i] = i;
        }
        sort(id + 1, id + n + 1, cmp);
        int curs = 0;
        for (int j = 1; j <= n; j++)
        {
            int i = id[j];
            if (curs + x[i] - y[i] >= 0)
            {
                curs += x[i] - y[i];
            }
            else
            {
                now.push_back(i);
            }
        }

        sol = best(sol, now);
    }
    print(sol);
}