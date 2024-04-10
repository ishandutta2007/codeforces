#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int x=0;
        for(int i=0;i<n;i++)
        {
            int m;
            cin >> m;
            int y=0;
            for(int j=0;j<30;j++) if(((x>>j)&1)==1&&((m>>j)&1)==0) y|=(1<<j);
            cout << y << " \n"[i==n-1];
            x=(m^y);
        }
    }
    return 0;
}