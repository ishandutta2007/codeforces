#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;
int ans;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();

    for(int i=0; i<n; i++)
    {
        int x = 0;
        int y = 0;
        int f = 1;

        for(int j=i; j<n; j++)
        {
            if(s[j]=='(')
                x++;
            else if(s[j]==')')
                x--;
            else y++;

            if(x+y<0)
                f=0;

            while(y>x)
            {
                y--;
                x++;
            }

            if(f==1 && x-y<=0 && (x+y)%2==0)
                ans++;
        }
    }
    cout << ans;
}