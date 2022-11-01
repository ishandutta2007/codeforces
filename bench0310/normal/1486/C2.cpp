#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto query=[](int l,int r)->int
    {
        cout << "? " << l << " " << r << "\n";
        cout.flush();
        int a;
        cin >> a;
        return a;
    };
    auto solve=[](int a)
    {
        cout << "! " << a << "\n";
        cout.flush();
        exit(0);
    };
    int two=query(1,n);
    if(two>1&&query(1,two)==two)
    {
        int l=1,r=two;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(query(m,two)==two) l=m;
            else r=m;
        }
        solve(l);
    }
    else
    {
        int l=two,r=n;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(query(two,m)==two) r=m;
            else l=m;
        }
        solve(r);
    }
    return 0;
}