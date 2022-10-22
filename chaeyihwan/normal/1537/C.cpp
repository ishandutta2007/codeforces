#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll h[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> h[i];

        sort(h+1, h+n+1);
        int opt = 1;
        for(int i=2;i<n;i++)
        {
            if(h[i+1] - h[i] < h[opt+1] - h[opt]) opt = i;
        }

        cout << h[opt] << " ";
        for(int i=opt+2;i<=n;i++)
        {
            cout << h[i] << " ";
        }
        for(int i=1;i<opt;i++)
        {
            cout << h[i] << " ";
        }
        cout << h[opt+1] << "\n";
    }
}