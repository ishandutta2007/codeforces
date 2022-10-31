#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int k=0;k<n;k++)
        cin >> a[k];
    int ans = min(a[0],a[n-1]);
    for(int k=1;k<n;k++)
    {
        if(a[k] >= a[k-1] && a[k] < ans)
            ans = a[k];
        if(a[k] <= a[k-1] && a[k-1] < ans)
            ans = a[k-1];
    }
    cout << ans;
    return 0;
}