#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;

typedef long long lli;

int n,m;
int a[222222],b[222222],t[222222],c[222222];;

int main()
{
    m=0;
    cin >> n;
    int ans = 0;
    for (int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        t[m]=a[i];
        m++;
        if (a[i]!=b[i])
        {
                       t[m]=b[i];
                       m++;
        }
    }
    sort(t,t+m);
    int j=0;
    c[0]=1;
    for (int i=1;i<m;i++)
        if (t[i]==t[j])
           c[j]++;
        else
        {
            j++;
            t[j]=t[i];
            c[j]=1;
        }
    int need = (n+1)/2;
    ans = -1;
    for (int i=0;i<=j;i++)
        if (c[i]>=need)
        {
                       int k = t[i];
                       int cnt = 0;
                       for (int j=0;j<n;j++)
                           if (a[j]==k)
                              cnt++;
                       if (cnt>=need)
                          cnt = 0;
                       else
                           cnt = need - cnt;
                       if (ans==-1 || cnt<ans)
                          ans = cnt;
        }
    cout << ans;
    return 0;
}