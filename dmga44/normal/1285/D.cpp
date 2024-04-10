#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

ll solve(vector<int> v,int b)
{
    if(b==-1)
        return 0;
    int n=v.size();
    int c1=0;
    for(int i=0;i<n;i++)
        if(v[i]&(1<<b))
            c1++;

    if(c1==0)
        return solve(v,b-1);
    if(c1==n)
        return (1<<b)+solve(v,b-1);

    vector<int> b1,b2;
    for(int i=0;i<n;i++)
    {
        if(v[i]&(1<<b))
            b2.push_back(v[i]-(1<<b));
        else
            b1.push_back(v[i]);
    }

    int x1=solve(b1,b-1);
    int x2=solve(b2,b-1);
    int r1=0,r2=0;
    for(auto y : b1)
        r1=max(r1,y^x1);
    for(auto y : b2)
        r2=max(r2,y^x2);

    if(r1<r2)
        return x1+(1<<b);
    return x2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];

    int x=solve(v,29);

    int res=0;
    for(auto y : v)
        res=max(res,y^x);
    db(res)

    return 0;
}