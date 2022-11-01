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
        vector a(n+1,vector(n+1,bool(0)));
        vector<array<int,2>> v(n);
        for(auto &[l,r]:v)
        {
            cin >> l >> r;
            a[l][r]=1;
        }
        auto ok=[&](int l,int r)->bool{return (l>r||a[l][r]);};
        for(auto [l,r]:v)
        {
            for(int i=l;i<=r;i++)
            {
                if(ok(l,i-1)&&ok(i+1,r)) cout << l << " " << r << " " << i << "\n";
            }
        }
    }
    return 0;
}