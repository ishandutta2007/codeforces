#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int n;
int a[55];
void Q()
{
    cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>a[i+n];
    sort(a,a+n+n);
    rep(i,n<<1)
    {
        if(i&1)
        {
            cout<<a[(n<<1)-(i>>1)-1];
            if(i==(n<<1)-1) cout<<endl;
            else cout<<' ';
        }
        else
        {
            cout<<a[i>>1]<<' ';
        }
    }
}
int t;
int main()
{
    cin>>t;
    while(t--)
   Q();
    return 0;
}