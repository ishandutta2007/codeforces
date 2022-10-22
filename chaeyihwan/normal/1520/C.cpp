#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int v[102][102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        if(n == 1)
        {
            cout << "1\n";
            continue;
        }
        if(n == 2)
        {
            cout << "-1\n";
            continue;
        }
        int x = 1, y = 1;
        for(int i=1;i<=n*n;i+=2)
        {
            v[x][y] = i;
            y++;
            if(y > n) y -= n, x++;
        }
        for(int i=2;i<=n*n;i+=2)
        {
            v[x][y] = i;
            y++;
            if(y > n) y -= n, x++;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }
}