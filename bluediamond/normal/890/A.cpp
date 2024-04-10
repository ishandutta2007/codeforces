#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[7],s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=1;i<=6;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    for(int i=1;i<=6;i++)
    {
        for(int j=i+1;j<=6;j++)
        {
            for(int k=j+1;k<=6;k++)
            {
                int x=a[i]+a[j]+a[k];
                if(x==s-x)
                {
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
/**


**/