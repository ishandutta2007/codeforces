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
        int s=1+((n%3)!=1);
        while(n>0)
        {
            cout << s;
            n-=s;
            s=3-s;
        }
        cout << "\n";
    }
    return 0;
}