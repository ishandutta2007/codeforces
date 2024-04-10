#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

int n,k;
int v[55];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    for(int i=1;i<=n;i++)
    {
        int x=v[i];
        int s=0;
        for(int j=1;j<=n;j++)
        {
            if(x<=v[j])
            {
                s++;
            }
        }
        if(s==k)
        {
            cout<<x<<" "<<x<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}
/**


**/