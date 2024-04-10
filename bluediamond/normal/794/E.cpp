#include <bits/stdc++.h>

using namespace std;

const int N=300000+7;
int n, a[N], kek1=-(int) 1e9, kek2=kek1;

int f(int a, int b, int c)
{
        return (b>=a&&b>=c)?max(a, c):b;
}

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        cin>>n;
        for (int i=1; i<=n; i++)
                cin>>a[i];
        for (int k=0; k<n-1; k++)
                if ((n-k+1)&1)
                {
                        kek1=max(kek1, max(a[n/2-k/2], a[n/2-k/2+1]));
                        kek1=max(kek1, max(a[(n+1)/2+k/2], a[(n+1)/2+k/2+1]));
                        cout<<kek1<<" ";
                }
                else
                {
                        kek2=max(kek2, f(a[(n+1)/2-k/2-1], a[(n+1)/2-k/2], a[(n+1)/2-k/2+1]));
                        kek2=max(kek2, f(a[(n+2)/2+k/2-1], a[(n+2)/2+k/2], a[(n+2)/2+k/2+1]));
                        cout<<kek2<<" ";
                }
        cout<<*max_element(a+1, a+n+1)<<"\n";
}