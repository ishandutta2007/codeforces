#include <iostream>
using namespace std;
int main()
{
    int a[110],n;
    cin >> n;
    int ma = -1, man = 0,
        mi = 101, min = 0;
    for(int k = 0; k < n; k++)
    {
        cin >> a[k];
        if(a[k] <= mi)
        {
            mi = a[k];
            min = k;
        }
        if(a[k] > ma)
        {
            ma = a[k];
            man = k;
        }
    }
    int ans = man + (n-1-min);
    if(man > min)
    {
        ans--;
    }
    cout << ans << endl;
    return 0;
}