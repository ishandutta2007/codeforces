#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int n, k, a[5005], b[5005];
double s_a, Max;

int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    b[0]=0;
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
    for(int i=1;i<=n-k+1;i++)
    {
        for(int j=i+k-1;j<=n;j++)
            {
                s_a=(double)(b[j]-b[i-1])/(j-i+1);
                Max=max(Max, s_a);
            }
    }
    cout <<  setprecision(16) << Max;
    return 0;
}