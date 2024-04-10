#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 100005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,t,s,d;
    cin >> n >> t;
    pii res=pii(MAXN,0);
    for(int i=0;i<n;i++)
    {
        cin >> s >> d;
        if(s>=t)
            res=min(res,pii(s-t,i+1));
        else
            res=min(res,pii((s-t+d*MAXN)%d,i+1));
    }
    db(res.second)

    return 0;
}