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
        for(int i=1;i<=k;i++)
        {
            int r=i;
            if(i>=2*k-n) r=k-(i-(2*k-n));
            cout << r << " \n"[i==k];
        }
    }
    return 0;
}