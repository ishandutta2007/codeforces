#include <iostream>
#include <cstdlib>
using namespace std;

int n,m;
long long a[100001];

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    cin >> m;
    int lw;
    for (int i=0; i<m; i++)
    {
        int w,h;
        cin >> w >> h;
        long long ans = a[w];
        if (i!=0)ans = max(ans, a[lw]);
        cout << ans << endl;
        a[w] = ans+h;
        lw = w;
    }

    return 0;
}