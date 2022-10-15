#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    if(n%2==0)
    {
        cout<<n/2<<"\n";
        for(int i=1;i<=n/2;i++)
            cout<<"2 ";
        cout<<"\n";
        return 0;
    }
    cout<<n/2<<"\n";
    for(int i=1;i<n/2;i++)
        cout<<"2 ";
    cout<<"3 \n";
    return 0;
}
/**

**/