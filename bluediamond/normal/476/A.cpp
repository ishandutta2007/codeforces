#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    int c2;
    int c1;
    if(n%2==0)
    {
        c2=n/2;
        c1=0;
    }
    else
    {
        c2=n/2;
        c1=1;
    }
    while((c1+c2)%k!=0)
    {
        if(c2==0)
        {
            cout<<"-1\n";
            return 0;
        }
        c2--;
        c1+=2;
    }
    cout<<c1+c2<<"\n";
    return 0;
}
/**


**/