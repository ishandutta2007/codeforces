#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    int a[m],sz = 0,tmp;
    for(int k = 0; k < m; k++)
    {
        cin >> tmp;
        if(tmp < 0)
        {
            a[sz++] = tmp;
        }
    }
    sort(a,a+sz);
    int ans = 0;
    for(int k = 0; k < sz && k < n; k++)
    {
        ans -= a[k];
    }
    cout << ans << endl;
    return 0;
}