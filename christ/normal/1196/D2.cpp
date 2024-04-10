#include <bits/stdc++.h>

using namespace std;

const string RGB = "RGB";

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int q;
    cin>>q;
    while (q--)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        int ans = INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            vector<int> arr(n);
            for (int x = 0; x < n; x++)
                arr[x] = (x ? arr[x-1] : 0) + (s[x] != RGB[(i+x)%3]);
            for (int x = 0; x+k <= n; x++)
                ans = min(ans, arr[x+k-1] - (x ? arr[x-1] : 0));
        }
        printf("%i\n", ans);
    }
}