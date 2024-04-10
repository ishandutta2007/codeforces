#include <iostream>
#include <iomanip>
using namespace std;

typedef long long lli;

int main()
{
    int n;
    cin >> n;
    int prev = 1;
    lli ans = 0;
    for (int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        if (a<prev)
                   ans += prev-a;
        prev = a;
    }
    cout << ans;
    return 0;
}