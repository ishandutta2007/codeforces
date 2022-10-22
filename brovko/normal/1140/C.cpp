#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, k, t[300005], b[300005], s[300005], c[1000005];
vector <pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> t[i] >> b[i];
        v.push_back({b[i], t[i]});
    }
    sort(v.begin(), v.end());

    c[0]=k;
    int L=0;
    for(int i=n-1;i>=0;i--)
    {
        while(c[L]==0)
            L++;
        s[i]=s[i+1];
        if(L<v[i].second)
        {
            s[i]+=v[i].second-L;
            c[L]--;
            c[v[i].second]++;
        }
    }

    int Max=0;
    for(int i=0;i<n;i++)
        Max=max(Max, s[i]*v[i].first);
    cout << Max;
}