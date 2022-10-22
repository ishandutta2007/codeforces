#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, m;
char a[105][105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        cin >> a[i][j];
        
        if(a[i][j] == 'C' || a[i][j] == 'M' || a[i][j] == 'Y')
        {
            cout << "#Color";
            return 0;
        }
    }
    
    cout << "#Black&White";
}