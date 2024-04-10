#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 doijwfojeoif

using namespace std;

int n, s, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
        s+=a[i];

    int x=0;
    for(int i=0;i<n;i++)
    {
        x+=a[i];
        if(2*x>=s)
        {
            cout << i+1;
            return 0;
        }
    }
}