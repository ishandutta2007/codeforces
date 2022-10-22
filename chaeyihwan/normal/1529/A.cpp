#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        int m = 1000;
        for(int i=1;i<=n;i++) m = min(m, a[i]);
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(a[i] > m) cnt++;
        }
        cout << cnt << "\n";
    }
}