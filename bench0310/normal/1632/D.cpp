#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,3>> v;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        v.push_back({i,i,a});
        for(auto &[l,r,g]:v) g=gcd(g,a);
        vector<array<int,3>> u;
        int l=0;
        int sz=v.size();
        bool ok=1;
        while(l<sz)
        {
            int r=l;
            while(r+1<sz&&v[l][2]==v[r+1][2]) r++;
            int tl=v[l][0];
            int tr=v[r][1];
            int g=v[l][2];
            u.push_back({tl,tr,g});
            ok&=(!(i-tr+1<=g&&g<=i-tl+1));
            l=r+1;
        }
        v=u;
        if(!ok)
        {
            cnt++;
            v.clear();
        }
        cout << cnt << " \n"[i==n];
    }
    return 0;
}