#include <iostream>

using namespace std;
int n, l[300000], r[300000], Max, Min, ans, c, d;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> l[i] >> r[i];
    Max=0;
    Min=0;
    for(int i=1;i<n;i++)
    {
        if(l[i]>l[Max])
            Max=i;
        if(r[i]<r[Min])
            Min=i;
    }
    c=Max;
    d=Min;
    Max=-1;
    Min=2000000000;
    for(int i=0;i<n;i++)
    {
        if(l[i]>Max && i!=c)
            Max=l[i];
        if(r[i]<Min && i!=c)
            Min=r[i];
    }
    ans=max(0, Min-Max);
    c=d;
    Max=-1;
    Min=2000000000;
    for(int i=0;i<n;i++)
    {
        if(l[i]>Max && i!=c)
            Max=l[i];
        if(r[i]<Min && i!=c)
            Min=r[i];
    }
    ans=max(ans, Min-Max);
    cout << ans;
    return 0;
}