#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        auto q=[&](int l,int r)->ll
        {
            cout << "? " << l << " " << r << endl;
            ll x;
            cin >> x;
            if(x==-1) exit(0);
            return x;
        };
        int l=1,r=n;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(q(1,m)==0) l=m;
            else r=m;
        }
        int a=l;
        int x=(q(a,n)-q(a+1,n)+1);
        int b=a+x;
        int y=(q(b,n)-q(b+1,n)+1);
        int c=b+y-1;
        cout << "! " << a << " " << b << " " << c << endl;
    }
    return 0;
}