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
        int n,m,k;
        cin >> n >> m >> k;
        int b=(n%m)*((n+m-1)/m);
        int s=0;
        while(k--)
        {
            int x=s;
            for(int i=0;i<m;i++)
            {
                int sz=((i<(n%m))?(n+m-1)/m:n/m);
                cout << sz << " ";
                for(int j=1;j<=sz;j++)
                {
                    cout << x+1 << " \n"[j==sz];
                    x=(x+1)%n;
                }
            }
            s=(s+b)%n;
        }
    }
    return 0;
}