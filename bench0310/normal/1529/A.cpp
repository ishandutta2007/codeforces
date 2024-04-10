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
        int m=101;
        int c=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            if(a<m)
            {
                m=a;
                c=1;
            }
            else if(a==m) c++;
        }
        cout << n-c << "\n";
    }
    return 0;
}