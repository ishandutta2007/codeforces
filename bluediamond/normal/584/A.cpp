#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,t;
    cin>>n>>t;
    if(n==1)
    {
        if(t==10)
            cout<<"-1\n";
        else
            cout<<t<<"\n";
        return 0;
    }
    int p=1;
    for(int i=1;i<n;i++)
        p=10*p%t;
    cout<<1;
    for(int i=1;i<=n-2;i++)
        cout<<0;
    if(p==0)
        cout<<0;
    else
        cout<<t-p;
    cout<<"\n";
    return 0;
}