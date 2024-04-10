#include <bits/stdc++.h>
using namespace std;
const int si=1e5+10;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int mx = 0,sum = 0;
    for(int i=0;i<n;++i)
    {
        sum += a[i];
        if(sum < 0)
            sum = 0;
        mx = max(mx, sum);
    }
    sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
    }
    cout << 2*mx-sum;
    return 0;
}