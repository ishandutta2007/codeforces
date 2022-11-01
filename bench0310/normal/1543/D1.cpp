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
        int n,k;
        cin >> n >> k;
        int x=0;
        for(int i=0;i<n;i++)
        {
            cout << (i^x) << "\n";
            cout.flush();
            int r;
            cin >> r;
            if(r==1) break;
            if(r==-1) exit(0);
            x^=(x^i);
        }
    }
    return 0;
}