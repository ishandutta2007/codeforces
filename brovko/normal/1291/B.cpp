#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

int t, n, a[300005];

int32_t main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        int f=0;
        for(int i=0;i<n-1;i++)
            if(a[i]>=a[i+1])
                f=1;
        int f1=0;
        for(int i=0;i<n-1;i++)
            if(a[i]<=a[i+1])
            f1=1;
        if(f==0 || f1==0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            int j=0;
            while(a[j]>=j)
                j++;
            int k=n-1;
            while(a[k]>=n-k-1)
                k--;
            j--;
            k++;
            if(k-j<=1 && (k<=j || a[k]!=a[j] || a[k]!=n-k-1 || a[j]!=j))
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}