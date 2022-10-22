#include <bits/stdc++.h>
#define int long long
#define y1 iowfhjeofie
#define id long double

using namespace std;

int n, k, a[100005], c[300];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<300;i++)
        c[i]=-1;
    for(int i=0;i<n;i++)
    {
        if(c[a[i]]!=-1)
            cout << c[a[i]] << ' ';
        else
        {
            int j=a[i];
            while(j>=0 && (c[j]==-1 || a[i]-c[j]<=k-1) && a[i]-j<=k-1)
                j--;
            j++;
            for(int p=j;p<=a[i];p++)
                c[p]=j;
            cout << j << ' ';
        }
    }
}