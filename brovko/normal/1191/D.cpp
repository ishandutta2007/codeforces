#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005];

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

    if(a[n-1]==0)
    {
        cout << "cslnb" << endl;
        return 0;
    }

    int f=0;
    for(int i=0;i<n-1;i++)
        if(a[i]==a[i+1] && f==0)
            {
                if(a[i])
                    a[i]--;
                f=1;
            }
    if(f)
        for(int i=0;i<n-1;i++)
            if(a[i]==a[i+1])
            {
                cout << "cslnb" << endl;
                return 0;
            }

    int s=f;
    for(int i=0;i<n;i++)
        s+=a[i];
    if((s-n*(n-1)/2)%2==0)
        cout << "cslnb";
    else cout << "sjfnb";
}