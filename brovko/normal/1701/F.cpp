#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

using li = long long;

using namespace std;
const int N = 2e5 + 5;
const int Q = 400;
const int K = N / Q + 5;

li s[K], sqr[K], add[K], cnt[K], val[N], used[N];
int d;

li get()
{
//    cout << s[0] << ' ' << sqr[0] << ' ' << add[0] << ' ' << cnt[0] << endl;

    li ans = 0;

    for(int i = 0; i < K; i++)
        ans += (sqr[i] - s[i]);

    return ans / 2;
}

void update(int x)
{
    if(used[x])
    {
        used[x] = 0;
        li v = val[x] + add[x / Q];

        s[x / Q] -= v;
        sqr[x / Q] -= v * v;

        cnt[x / Q]--;

        int L = x + 1, R = min(N, x + d + 1);

        while(L < R)
        {
            if(L % Q == 0 && L + Q <= R)
            {
                add[L / Q]--;
                s[L / Q] -= cnt[L / Q];
                sqr[L / Q] -= 2 * s[L / Q] + cnt[L / Q];
                L += Q;
            }
            else
            {
                val[L]--;

                if(used[L])
                {
                    s[L / Q]--;
                    sqr[L / Q] -= 2 * (val[L] + add[L / Q]) + 1;
                }

                L++;
            }
        }
    }
    else
    {
        used[x] = 1;
        li v = val[x] + add[x / Q];

//        cout << "v " << v << endl;

        s[x / Q] += v;
        sqr[x / Q] += v * v;

        cnt[x / Q]++;

        int L = x + 1, R = min(N, x + d + 1);

        while(L < R)
        {
            if(L % Q == 0 && L + Q <= R)
            {
                add[L / Q]++;
                sqr[L / Q] += 2 * s[L / Q] + cnt[L / Q];
                s[L / Q] += cnt[L / Q];
                L += Q;
            }
            else
            {
                if(used[L])
                    sqr[L / Q] += 2 * (val[L] + add[L / Q]) + 1;

                val[L]++;

                if(used[L])
                    s[L / Q]++;

                L++;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q >> d;

    vector <int> a(q);

    for(int i = 0; i < q; i++)
        cin >> a[i];

    for(int i = 0; i < q; i++)
    {
        update(a[i]);
        cout << get() << "\n";
    }
}