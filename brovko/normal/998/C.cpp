#include <iostream>

using namespace std;
long long n, a[300000], x, y, k, ans;
char c;

int main()
{
    cin >> n >> x >> y;
    for(int i=0;i<n;i++)
    {
        cin >> c;
        if(c=='1')
            a[i]=1;
        else a[i]=0;
        if(a[i]==0 && (i==0 || a[i-1]==1))
            k++;
    }
    if(x>y)
        ans=k*y;
    else ans=x*(k-1)+y;
    if(k==0)
        ans=0;
    cout << ans;
    return 0;
}