#include <iostream>
using namespace std;
int a[200010],n;
int f(int x,int y)
{
    int res = 0;
    for(int k = x; k < n; k+= y)
    {
        res += a[k];
    }
    return res;
}
int main()
{
    int ans = 0;
    cin >> n;
    for(int k =0 ; k < n; k++)
    {
        cin >> a[k];
        ans += a[k];
    }
    for(int k = 1; k <= n/2; k++)
    {
        if(n % k == 0 && n/k >= 3)
        {
            for(int j = 0; j < k; j++)
            {
                ans = max(ans, f(j,k));
            }
        }
    }
    cout << ans << endl;
    return 0;
}