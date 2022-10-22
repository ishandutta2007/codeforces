#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int a[200002], b[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=0;i<n;i++) cin >> a[i] >> b[i];
        int l = 1, r = n;
        while(l < r)
        {
            int mid = (l + r + 1)/2;
            int cnt = 0;
            for(int i=0;i<n;i++)
            {
                if(b[i] >= cnt && a[i] >= mid - cnt - 1) cnt++;
            }
            if(cnt >= mid) l = mid;
            else r = mid - 1;
        }
        cout << l << "\n";
    }
}