#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[7005], b[7005];
vector <int> v;

map <int, int> k;

bool bad(int x, int y)
{
    return (x&y)==x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<n;i++)
        {
            cin >> a[i];
            k[a[i]]++;
            if(k[a[i]]==2)
                v.push_back(a[i]);
        }
    for(int i=0;i<n;i++)
        cin >> b[i];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int f=0;
        for(auto to:v)
            if(bad(a[i], to))
            f=1;
        ans+=f*b[i];
    }
    cout << ans;
}