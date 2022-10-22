#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int t, n, s, l[200005], r[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        vector <pair <int, int> > v;

        cin >> n >> s;
        for(int i=0;i<n;i++)
        {
            cin >> l[i] >> r[i];
            s-=l[i];
            v.push_back({l[i], r[i]});
        }
        sort(v.begin(), v.end());

        int L=0;
        int R=1e18;
        while(R-L>1)
        {
            int M=(L+R)/2;
            int x=s;
            int k=0;

            for(int i=n-1;i>=0;i--)
            {
                if(v[i].first>=M)
                    k++;
                else if(v[i].second>=M && x+v[i].first-M>=0)
                {
                    k++;
                    x-=M-v[i].first;
                }
            }

            if(k>n/2)
                L=M;
            else R=M;
        }
        cout << L << "\n";
    }
}