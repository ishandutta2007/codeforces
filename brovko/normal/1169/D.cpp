#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;
int n, ans, Min;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> s;
    n=s.size();
    for(int i=0;i<n-2;i++)
        {
            Min=1000000000;
            for(int x=i;x<i+8;x++)
                for(int k=1;k<=4;k++)
            {
                if(x+2*k<n && s[x]==s[x+k] && s[x]==s[x+2*k])
                    Min=min(Min, x+2*k);
            }
            ans+=max(0ll, n-Min);
        }
    cout << ans;
}