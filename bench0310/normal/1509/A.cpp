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
        vector<int> a[2];
        for(int i=0;i<n;i++)
        {
            int b;
            cin >> b;
            a[b%2].push_back(b);
        }
        for(int i=0;i<2;i++) for(int b:a[i]) cout << b << " ";
        cout << "\n";
    }
    return 0;
}