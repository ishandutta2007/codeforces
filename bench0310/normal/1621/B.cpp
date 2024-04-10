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
        map<array<int,2>,int> m;
        const int inf=(1<<30);
        array<int,2> x={inf,inf};
        array<int,2> y={-inf,-inf};
        for(int i=1;i<=n;i++)
        {
            int l,r,c;
            cin >> l >> r >> c;
            x=min(x,{l,c});
            y=max(y,{r,-c});
            int res=x[1]-y[1];
            if(!m.contains({l,r})) m[{l,r}]=c;
            m[{l,r}]=min(m[{l,r}],c);
            if(m.contains({x[0],y[0]})) res=min(res,m[{x[0],y[0]}]);
            cout << res << " \n"[i==n];
        }
    }
    return 0;
}