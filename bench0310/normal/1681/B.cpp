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
        vector<int> a(n);
        for(int &x:a) cin >> x;
        int m;
        cin >> m;
        int p=0;
        while(m--)
        {
            int b;
            cin >> b;
            p=(p+b)%n;
        }
        cout << a[p] << "\n";
    }
    return 0;
}