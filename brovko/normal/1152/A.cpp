#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, m, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int j=0;j<m;j++)
        cin >> b[j];

    int x1=0, y1=0, x2=0, y2=0;

    for(int i=0;i<n;i++)
        if(a[i]%2)
            x1++;
        else y1++;

    for(int i=0;i<m;i++)
        if(b[i]%2)
            x2++;
        else y2++;
    cout << min(x1, y2)+min(x2, y1);
}