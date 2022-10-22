#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n;
string s[100005], t;
vector <pair <ld, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x=0;
        int y=0;
        cin >> s[i];
        for(auto to:s[i])
        {
            if(to=='s')
                x++;
            else y++;
        }
        ld z;
        if(x==0)
            z=1e18;
        else z=(ld)y/x;

        v.push_back({z, i});
    }
    sort(v.begin(), v.end());
    for(auto to:v)
    {
        t+=s[to.second];
    }

    int k=0;
    int ans=0;
    for(auto to:t)
    {
        if(to=='s')
            k++;
        else ans+=k;
    }
    cout << ans;
}