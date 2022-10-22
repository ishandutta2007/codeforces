#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[100002], b[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        sort(a+1, a+n+1);
        sort(b+1, b+n+1);
        reverse(a+1, a+n+1);
        reverse(b+1, b+n+1);
        for(int i=2;i<=n;i++)
        {
            a[i] += a[i-1];
            b[i] += b[i-1];
        }

        for(int i=0;i<=n;i++)
        {
            int k = n + i;
            int d = k - k/4;

            if(100 * i + a[min(d-i, n)] >= b[min(d, n)])
            {
                cout << i << "\n";
                break;
            }
        }
    }
}