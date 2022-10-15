#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 7;
const int C = 2 * N;

int aib[C];

void add(int p, int x)
{
        p += N;
        for (int i = p; i < C; i += i & (-i))
                aib[i] += x;
}

int prefix(int p)
{
        p += N;
        int r = 0;
        for (int i = p; i > 0; i -= i & (-i))
                r += aib[i];
        return r;
}

struct Point
{
        int x;
        int y;
        int i;
};

bool operator < (Point a, Point b)
{
        return a.y < b.y;
}

int cnt_vert;
Point in[N], out[N];

struct Segment
{
        int y;
        int x1, x2;
};

bool operator < (Segment a, Segment b)
{
        return a.y < b.y;
}

int cnt_orz;
Segment orz[N];

bool used[N];

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        int all;
        cin >> all;

        for (int i = 1; i <= all; i++)
        {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                if (x1 == x2)
                {
                        cnt_vert++;
                        in[cnt_vert] = {x1, min(y1, y2), cnt_vert};
                        out[cnt_vert] = {x2, max(y1, y2), cnt_vert};
                }
                else
                        orz[++cnt_orz] = {y1, min(x1, x2), max(x1, x2)};
        }
        sort(in + 1, in + cnt_vert + 1);
        sort(out + 1, out + cnt_vert + 1);
        sort(orz + 1, orz + cnt_orz + 1);

        ll sol = 0;
        for (int i = 1; i <= cnt_orz; i++)
        {
                for (int j = 0; j < C; j++)
                        aib[j] = 0;
                for (int j = 1; j <= cnt_vert; j++)
                        if (in[j]. y <= orz[i].y)
                                used[in[j].i] = 1, add(in[j].x, 1);
                        else
                                used[in[j].i] = 0;
                int cur_out = 1;
                for (int j = i + 1; j <= cnt_orz; j++)
                {
                        while (cur_out <= cnt_vert && out[cur_out].y < orz[j].y)
                        {
                                if (used[out[cur_out].i])
                                        add(out[cur_out].x, -1);
                                cur_out++;
                        }
                        int st = max(orz[i].x1, orz[j].x1);
                        int dr = min(orz[i].x2, orz[j].x2);
                        if (st <= dr)
                        {
                                ll x = prefix(dr) - prefix(st - 1);
                                sol += x * (x - 1) / 2;
                        }
                }
        }
        cout << sol << "\n";

        return 0;
}