#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string a[2];
int n,ans=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a[0]>>a[1];
    n=a[0].size();
    for(int i=0;i<n;i++)
    {
        if(a[0][i]=='0' && a[1][i]=='0')
        {
            if(i>=1 && a[0][i-1]=='0')
            {
                ans++;
                a[0][i]=a[1][i]=a[0][i-1]='1';
                continue;
            }
            if(i>=1 && a[1][i-1]=='0')
            {
                ans++;
                a[0][i]=a[1][i]=a[1][i-1]='1';
                continue;
            }
            if(i<n-1 && a[0][i+1]=='0')
            {
                ans++;
                a[0][i]=a[1][i]=a[0][i+1]='1';
                continue;
            }
            if(i<n-1 && a[1][i+1]=='0')
            {
                ans++;
                a[0][i]=a[1][i]=a[1][i+1]='1';
                continue;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}