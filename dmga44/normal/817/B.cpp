#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef unsigned long long ull;
#define MAXN 300005

int arr[MAXN];
ull f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    sort(arr,arr+n);

    ull res=1;
    int l=arr[0],p=0,x=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=l)
            l=arr[i],f[x]=p,p=0,x++;
        p++;
    }
    f[x]=p;
    x++;
    int sum=0;
    for(int i=0;i<x;i++)
    {
        if(sum<3 && sum+f[i]>=3)
        {
            if(sum==0)
                res=(f[i]*(f[i]-1)*(f[i]-2))/6;
            else if(sum==1)
                res=(f[i]*(f[i]-1))/2;
            else
                res=f[i];
            break;
        }
        sum+=f[i];
    }
    db(res)
    return 0;
}