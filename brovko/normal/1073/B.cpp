#include <bits/stdc++.h>
#define int long long
#define y1 uwiegewiug

using namespace std;

int n, a[200005], b[200005], used[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];
    int L=0;
    for(int i=0;i<n;i++)
        {
            int k=0;
            while(used[b[i]]==0)
            {
                used[a[L]]=1;
                L++;
                k++;
            }
            cout << k << ' ';
        }
}