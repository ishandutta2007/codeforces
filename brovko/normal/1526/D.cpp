#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, a[128];
string s, p, q;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    cin >> t;

    while(t--)
    {
        cin >> s;

        int n = s.size();

        string t = "ANTO";

        int ans = 0;

        for(a['A'] = 0; a['A'] < 4; a['A']++)
            for(a['N'] = 0; a['N'] < 4; a['N']++)
            for(a['T'] = 0; a['T'] < 4; a['T']++)
            for(a['O'] = 0; a['O'] < 4; a['O']++)
                if((1 << a['A']) + (1 << a['N']) + (1 << a['T']) + (1 << a['O']) == 15)
                {
                    int z = 0;

                    int k[4] = {0, 0, 0, 0};

                    for(int i = 0; i < n; i++)
                    {
                        k[a[s[i]]]++;

                        for(int j = a[s[i]] + 1; j < 4; j++)
                            z += k[j];
                    }

                    vector <pair <int, int> > v;

                    for(int i = 0; i < n; i++)
                        v.pb({a[s[i]], s[i]});

                    sort(v.begin(), v.end());

                    q = "";

                    for(int i = 0; i < n; i++)
                        q += alf.substr(v[i].y - 'A', 1);

                    if(z >= ans)
                    {
                        ans = z;
                        p = q;
                    }
                }

        cout << p << "\n";
    }
}