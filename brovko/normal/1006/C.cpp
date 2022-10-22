#include <iostream>

using namespace std;
int n, a[200000], l, m, r;
long long sum1[200000], sum3[200000], s;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    s=0;
    for(int i=0;i<n;i++)
        {
            s=s+a[i];
            sum1[i]=s;
        }
    s=0;
    for(int i=n-1;i>=0;i--)
    {
        s=s+a[i];
        sum3[i]=s;
    }
    for(int i=1;i<n;i++)
    {
        l=0;
        r=i;
        while(r-l>1)
        {
            m=(l+r)/2;
            if(sum1[m]>sum3[i])
                r=m;
            else l=m;
        }
        if(sum1[l]==sum3[i])
        {
            cout << sum1[l];
            return 0;
        }
    }
    cout << 0;
    return 0;
}