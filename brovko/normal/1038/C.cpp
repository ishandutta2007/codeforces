#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, a[100005], b[100005], d;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int j=0;j<n;j++)
        cin >> b[j];

    sort(a, a+n);
    sort(b, b+n);

    int r1=n-1;
    int r2=n-1;

    for(int i=0;i<n;i++)
    {
        int c1=-1e9;
        int c2=-1e9;
        if(r1>=0)
            c1=a[r1];
        if(r2>=0)
            c2=b[r2];
        if(c1>c2)
        {
            r1--;
            d+=c1;
            //cout << "L";
        }
        else
        {
            r2--;
           // cout << "R";
        }

        c1=-1e9;
        c2=-1e9;
        if(r1>=0)
            c1=a[r1];
        if(r2>=0)
            c2=b[r2];
        if(c1>c2)
        {
            r1--;
     //       cout << "L";
        }
        else
        {
            r2--;
            d-=c2;
     //       cout << "R";
        }
    }
    cout << d;
}