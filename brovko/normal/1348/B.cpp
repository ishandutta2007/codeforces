#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, k, a[105], b[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<105;i++)
            b[i]=0;
        for(int i=0;i<n;i++)
            b[a[i]]++;

        vector <int> v, u;
        for(int i=0;i<105;i++)
            if(b[i])
                u.push_back(i);
        if(u.size()>k)
            cout << "-1\n";
        else
        {
            for(int i=1;i<105;i++)
                if(u.size()<k && b[i]==0)
                    u.push_back(i);
            int x=u.size();
            int L=0;
            for(int i=0;i<n;i++)
            {
                while(u[L%x]!=a[i])
                {
                    v.push_back(u[L%x]);
                    L++;
                }
                v.push_back(u[L%x]);
                L++;
            }

            cout << v.size() << "\n";
            for(auto to:v)
                cout << to << ' ';
            cout << "\n";
        }

    }
}