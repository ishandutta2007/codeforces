#include <iostream>

using namespace std;
int n, M, a[100010], gorit[100010], g, Max;

int main()
{
    cin >> n >> M;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    a[0]=0;
    n++;
    a[n]=M;
    gorit[0]=0;
    g=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
            g=g+a[i]-a[i-1];
        gorit[i]=g;
    }
    Max=gorit[n];
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            if(a[i+1]-a[i]>1 || a[i]-a[i-1]>1)
                Max=max(Max, 2*gorit[i]+a[n]-gorit[n]-a[i]-1);
        }
    }
    cout << Max;
    return 0;
}