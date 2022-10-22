#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], Min;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a, a+n);

    int s=0;

    for(int i=0;i<n;i++)
        s+=a[i];

    Min=s;

    for(int i=1;i<n;i++)
        for(int j=2;j<a[i];j++)
            if(a[i]%j==0)
                Min=min(Min, s-a[i]-a[0]+a[0]*j+a[i]/j);
    cout << Min;
}