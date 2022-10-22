#include <bits/stdc++.h>
#define db(x) cout << x << '\n';
using namespace std;
typedef long long ull;

vector <ull> v,vv;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ull x,y,l,r;
    cin >> x >> y >> l >> r;
    v.push_back(1);
    for(ull i=1;i<=(r/x);i*=x)
        v.push_back(i*x);

    for(auto xx : v)
    {
        vv.push_back(xx+1);
        for(ull i=1;i<=(r/y);i*=y)
            if((i*y)+xx<=r)
                vv.push_back((i*y)+xx);
    }
    v.clear();
    for(int i=0;i<vv.size();i++)
        if(vv[i]>=l)
            v.push_back(vv[i]);
    v.push_back(l-1);
    v.push_back(r+1);

    sort(v.begin(),v.end());

    ull res=0;
    for(int i=0;i<v.size()-1;i++)
        if(v[i+1]!=v[i])
            res=max(v[i+1]-v[i]-1,res);

    db(res)

    return 0;
}