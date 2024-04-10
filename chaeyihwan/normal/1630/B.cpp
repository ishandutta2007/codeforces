#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int a[200002], cnt[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cnt[i] = 0;
        for(int i=1;i<=n;i++) cnt[a[i]]++;
        for(int i=2;i<=n;i++) cnt[i] += cnt[i-1];

        int optx = 0, opty = 10*n;
        for(int x=1;x<=n;x++)
        {
            int l = x, r = n+1;
            while(l < r)
            {
                int mid = (l + r)/2;
                if(2*(cnt[mid] - cnt[x-1]) >= n+k) r = mid;
                else l = mid+1;
            }
            if(l == n+1) continue;
            if(l - x < opty - optx)
            {
                opty = l;
                optx = x;
            }
        }

        cout << optx << " " << opty << "\n";
        int now = 0;
        for(int i=1,j=1,cnt=0;i<=n;i++)
        {
            if(cnt == k-1) { cout << i << " " << n << "\n"; break; }
            if(optx <= a[i] && a[i] <= opty) now++;
            else now--;
            if(now > 0)
            {
                cout << j << " " << i << "\n";
                cnt++;
                now = 0;
                j = i + 1;
            }
        }
    }
}