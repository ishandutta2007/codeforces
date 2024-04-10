#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int k, x, n, m;

int fib(int a, int b)
{
    for(int i = 3; i <= k; i++)
    {
        a += b;
        swap(a, b);
    }

    return b;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> x >> n >> m;

    int s = fib(1, 0);
    int t = fib(0, 1);
    int st = s;

    int a = 0, b = 0;

    for(int i = 4; i <= k; i++)
    {
        a += b + 1 - i % 2;
        swap(a, b);
    }

    int ts = b, tt = a;

    for(int ks = 0; ks <= n / 2; ks++)
        for(int kt = 0; kt <= m / 2; kt++)
            for(int kst = 0; kst < 2; kst++)
                for(int kts = 0; kts < 2; kts++)
                    for(int ktt = 0; ktt < 2; ktt++)
                        if(ks * s + kt * t + kst * st + kts * ts + ktt * tt == x)
                        {
                            string s1, s2;

                            for(int i = 0; i < n; i++)
                                s1 += 'B';

                            for(int i = 0; i < m; i++)
                                s2 += 'B';

                            if(kst)
                            {
                                s1[n - 1] = 'A';
                                s2[0] = 'C';
                            }

                            if(kts)
                            {
                                s2[m - 1] = 'A';
                                s1[0] = 'C';
                            }

                            if(ktt)
                            {
                                s2[m - 1] = 'A';
                                s2[0] = 'C';
                            }

                            int z = 0, F = 1;

                            for(int i = 0; i < ks; i++)
                            {
                                while(z < n && s1[z] != 'B')
                                    z++;

                                if(z >= n - 1)
                                    F = 0;
                                else
                                {
                                    s1[z] = 'A';
                                    s1[z + 1] = 'C';
                                }
                            }

                            z = 0;

                            for(int i = 0; i < kt; i++)
                            {
                                while(z < m && s2[z] != 'B')
                                    z++;

                                if(z >= m - 1)
                                    F = 0;
                                else
                                {
                                    s2[z] = 'A';
                                    s2[z + 1] = 'C';
                                }
                            }

                            if(F == 0)
                                continue;

                            if(kst && (s1[n - 1] != 'A' || s2[0] != 'C') || kst == 0 && s1[n - 1] == 'A' && s2[0] == 'C')
                                continue;

                            if(kts && (s2[m - 1] != 'A' || s1[0] != 'C') || kts == 0 && s2[m - 1] == 'A' && s1[0] == 'C')
                                continue;

                            if(ktt && (s2[m - 1] != 'A' || s2[0] != 'C') || ktt == 0 && s2[m - 1] == 'A' && s2[0] == 'C')
                                continue;

//                            cout << ks << ' ' << kt << ' ' << kst << ' ' << kts << ' ' << ktt << endl;

                            cout << s1 << "\n" << s2;

                            return 0;
                        }

    cout << "Happy new year!";
}