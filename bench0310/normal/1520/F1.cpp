#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin >> n >> t;
    int k;
    cin >> k;
    auto qry=[&](int l,int r)->int
    {
        cout << "? " << l << " " << r << "\n";
        cout.flush();
        int s;
        cin >> s;
        return s;
    };
    auto ans=[&](int p)
    {
        cout << "! " << p << "\n";
        cout.flush();
        t--;
        if(t==0) exit(0);
        cin >> k;
    };
    int l=0,r=n;
    while(l<r-1)
    {
        int m=(l+r)/2;
        if(m-qry(1,m)>=k) r=m;
        else l=m;
    }
    ans(r);
    return 0;
}