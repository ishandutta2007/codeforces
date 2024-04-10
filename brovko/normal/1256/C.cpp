#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, m, d, a[1005], b[1005];

void f()
{
    int j=0;
    for(int i=1;i<=n;i++)
        if(b[i]==0)
        j=i;
    for(int i=j;i<=n;i++)
        b[i]=b[i+1];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> d;
    for(int i=0;i<m;i++)
        cin >> a[i];
    int s=0;
    for(int i=0;i<n;i++)
        s+=a[i];
    if((m+1)*d+s-m<n+1)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    int j=d;
    for(int i=0;i<m;i++)
    {
        while(a[i]--)
        {
            while(j>n)
            {
                f();
                j--;
            }
            b[j]=i+1;
            j++;
        }
        j+=d-1;
    }
    for(int i=1;i<=n;i++)
        cout << b[i] << ' ';
}