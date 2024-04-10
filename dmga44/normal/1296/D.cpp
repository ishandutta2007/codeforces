#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,a,b,k;
    cin >> n >> a >> b >> k;
    vector<int> res;
    int ans=0,v;
    for(int i=0;i<n;i++)
    {
        cin >> v;
        v%=(a+b);
        if(v==0)
            v=a+b;
        res.push_back(v);
    }

    sort(res.begin(),res.end());

    int ac=0;
    for(int i=0;i<n;i++)
    {
//        db(res[i])
        if((ac+(res[i]-1)/a)<=k)
        {
            ans++;
            ac+=(res[i]-1)/a;
        }
    }
    db(ans)

    return 0;
}