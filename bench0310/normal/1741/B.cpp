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
        if(n==2) cout << "2 1\n";
        else if(n==3) cout << "-1\n";
        else
        {
            cout << n-1 << " " << n << " ";
            for(int i=1;i<=n-2;i++) cout << i << " \n"[i==n-2];
        }
    }
    return 0;
}