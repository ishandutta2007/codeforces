#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[20];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int d = 0, m = n, L;
        bool flag = false;
        while(m)
        {
            a[d++] = m%10;
            if(m < 10) L = m;
            m /= 10;
        }

        int ans = (d - 1) * 9 + L;
        for(int i=d-1;i>=0;i--)
        {
            if(a[i] > L) break;
            if(a[i] < L) { ans--; break; }
        }

        cout << ans << "\n";
    }
}