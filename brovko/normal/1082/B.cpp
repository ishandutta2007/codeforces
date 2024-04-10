#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> s;
    n++;
    s+="S";
    int ans=0;
    for(int i=0;i<n;i++)
        if(s[i]=='S')
        {
            int x=i-1;
            int z=1;
            while(x>=0 && s[x]=='G')
            {
                z++;
                x--;
            }

            int y=i+1;
            while(y<n && s[y]=='G')
            {
                z++;
                y++;
            }
            ans=max(ans, z);
        }

    int kg=0;
    for(int i=0;i<n;i++)
        if(s[i]=='G')
        kg++;
    ans=min(ans, kg);

    cout << ans;
}