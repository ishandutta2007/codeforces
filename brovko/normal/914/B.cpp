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

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);

    int k=0;
    for(int i=0; i<n; i++)
    {
        if(i==0 || a[i]==a[i-1])
            k++;
        else
        {
            if(k%2)
            {
                cout << "Conan";
                return 0;
            }
            k=1;
        }
    }
    if(k%2)
        cout << "Conan";
    else
    cout << "Agasa";
}