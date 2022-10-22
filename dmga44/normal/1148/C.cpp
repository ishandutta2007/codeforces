#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 300005

int p[MAXN],f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        p[i]--;
        f[p[i]]=abs(p[i]-i);
        if(f[p[i]])
            q.push(i);
    }

    vector<pii> res;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(!f[p[u]])
            continue;
        int v=p[u];
        if((u<n/2)==(v<n/2))
        {
            int x=0;
            if(u<n/2)
                x=n-1;
            res.push_back(pii(u,x));
            res.push_back(pii(v,x));
            res.push_back(pii(u,x));
        }
        else
        {
            if(abs(u-v)>=n/2)
                res.push_back(pii(u,v));
            else
            {
                int x=0;
                if(u<n/2)
                    x=n-1;
                int y=n-x-1;
//                cout << x+1 << ' ' << y+1 << '\n';
//                cout << u+1 << ' ' << v+1 << '\n';
//                db("")
                res.push_back(pii(u,x));
                res.push_back(pii(y,x));
                res.push_back(pii(v,y));
                res.push_back(pii(y,x));
                res.push_back(pii(u,x));
            }
        }
        swap(p[u],p[v]);
        f[p[v]]=0;
        f[p[u]]=abs(p[u]-u);
        if(f[p[u]])
            q.push(u);
    }
    db(res.size())
    for(auto y : res)
        cout << y.first+1 << ' ' << y.second+1 << '\n';

    return 0;
}