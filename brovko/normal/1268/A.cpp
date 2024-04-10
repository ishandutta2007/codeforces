#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, k, a[200005];
char c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> c;
        a[i]=c-'0';
    }
    int f=0;
    for(int i=k;i<n;i++)
        if(f==0)
    {
        if(a[i]>a[i-k])
            f=1;
        if(a[i]<a[i-k])
            f=-1;
    }
    if(f==1)
    {
        int j=k-1;
        while(a[j]==9)
            {
                a[j]=0;
                j--;
            }
        a[j]++;
    }
    cout << n << endl;
    for(int i=0;i<n;i++)
        cout << a[i%k];
}