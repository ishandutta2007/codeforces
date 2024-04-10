#include <bits/stdc++.h>

using namespace std;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--)
        {
                int n,r;
                cin>>n;
                r=sqrt(n);
                cout<<r-2+(n+r-1)/r<<"\n";
        }

}