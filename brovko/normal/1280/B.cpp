#include <bits/stdc++.h>
//#define int long long
#define pb push_back

using namespace std;

int t, r, c;
char a[100][100];

int32_t main()
{
    cin >> t;
    while(t--)
    {
        cin >> r >> c;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin >> a[i][j];
        int ans=1e9;
        int f=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(a[i][j]=='P')
                    f=1;
        if(f==0)
            ans=0;
        if(a[0][0]=='A' || a[r-1][c-1]=='A' || a[0][c-1]=='A' || a[r-1][0]=='A')
            ans=min(ans, 2);
        for(int i=0;i<r;i++)
        {
            f=0;
            for(int j=0;j<c;j++)
                if(a[i][j]=='P')
                    f=1;
            if(f==0)
                if(i==0 || i==r-1)
                    ans=min(ans, 1);
                else ans=min(ans, 2);
        }

        for(int j=0;j<c;j++)
        {
            f=0;
            for(int i=0;i<r;i++)
                if(a[i][j]=='P')
                    f=1;
            if(f==0)
                if(j==0 || j==c-1)
                    ans=min(ans, 1);
                else ans=min(ans, 2);
        }

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(a[i][j]=='A')
        {
            if(i==0 || j==0 || i==r-1 || j==c-1)
                ans=min(ans, 3);
            else ans=min(ans, 4);
        }

        if(ans==1e9)
            cout << "MORTAL\n";
        else cout << ans << "\n";
    }
}