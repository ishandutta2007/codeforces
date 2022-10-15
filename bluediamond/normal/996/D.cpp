#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,v[205];
int ans=0;

int main()
{
 ///   ios_base::sync_with_stdio(false);
 ///   cin.tie(0);
    cin>>n;
    for(int i=1;i<=2*n;i++)
        cin>>v[i];
    for(int p=1;p<=2*n;p+=2)
    {
        int val=v[p];
        int poz=0;
        for(int j=p+1;j<=2*n;j++)
            if(v[j]==val)
            {
                poz=j;
                break;
            }
        ///cout<<p<<"\n";

        while(poz!=p+1)
        {
            ans++;
            swap(v[poz],v[poz-1]);
            poz--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/