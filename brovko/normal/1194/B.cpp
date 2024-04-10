#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int q, n, m, x[50005], y[50005];
string s[50005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> q;
    while(q--)
    {

        cin >> n >> m;
        for(int i=0;i<n;i++)
            cin >> s[i];
            
        for(int i=0;i<n;i++)
            x[i]=0;
        for(int j=0;j<m;j++)
            y[j]=0;

        int Maxx=0, Maxy=0;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(s[i][j]=='*')
        {
            x[i]++;
            y[j]++;
        }

        for(int i=0;i<n;i++)
            Maxx=max(Maxx, x[i]);
        for(int j=0;j<m;j++)
            Maxy=max(Maxy, y[j]);

        int Max=0;
        for(int i=0;i<n;i++)
            if(x[i]>=Maxx-1)
            for(int j=0;j<m;j++)
            if(y[j]>=Maxy-1)
        {
            int c=x[i]+y[j];
            if(s[i][j]=='.')
                c++;
            Max=max(Max, c);
        }

        cout << m+n-Max << "\n";
        
        for(int i=0;i<n;i++)
            s[i]="";
    }
}