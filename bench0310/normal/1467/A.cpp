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
        if(n==1) cout << "9\n";
        else
        {
            cout << "98";
            n-=2;
            for(int i=9;n--;i=(i+1)%10) cout << i;
            cout << "\n";
        }
    }
    return 0;
}