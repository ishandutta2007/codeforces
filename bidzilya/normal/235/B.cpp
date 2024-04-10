#include <iostream>
#include <iomanip>
using namespace std;

int n;
double p,c,ans;

int main()
{
    ans = c = 0.0;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> p;
        ans = ans + p*(1+2*c);
        c = (c+1)*p;
    }
    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}