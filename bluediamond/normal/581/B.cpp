#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

const int N=100000+5;

int n;
int v[N];
int a[N];
int mx=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=n;i>=1;i--)
    {
        if(v[i]<=mx)
        {
            a[i]=mx+1-v[i];
        }
        else
        {
            mx=v[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
/**


**/