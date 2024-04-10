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
        int s=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            s+=a;
        }
        int res=0;
        if(s==n) res=0;
        else if(s<n) res=1;
        else res=s-n;
        cout << res << "\n";
    }
    return 0;
}