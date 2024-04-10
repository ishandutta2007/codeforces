#include <bits/stdc++.h>
#define db(x) cout << x << '\n';
using namespace std;
typedef long long ull;
#define mod 1000000007

int arr[300005];

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    sort(arr,arr+n);

    ull sum1=0,sum2=0,po=1;
    for(int i=0;i<n;i++)
    {
        sum1=(sum1+(po*arr[i]))%mod;
        sum2=(sum2+(po*arr[n-i-1]))%mod;
        po=(po*2)%mod;
    }

    db((sum1-sum2+mod)%mod)

    return 0;
}