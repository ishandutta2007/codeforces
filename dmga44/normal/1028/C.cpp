#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

vector<ppp> vp;

bool intersect(pii x,pii y,int i)
{
    if(vp[i].first.first<=x.first && vp[i].second.first>=x.second)
        if(vp[i].first.second<=y.first && vp[i].second.second>=y.second)
            return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x1,y1,x2,y2;
    cin >> n;
    priority_queue<pii,vector<pii>,greater<pii>>pqx,pqy;
    for(int i=0;i<n;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        pqx.push(pii(x1,0));
        pqx.push(pii(x2,1));
        pqy.push(pii(y1,0));
        pqy.push(pii(y2,1));
        vp.push_back(ppp(pii(x1,y1),pii(x2,y2)));
    }

    vector<pii> ix,iy;
    int sx=0,sy=0,x,y,xxx,yyy,fx=0,fy=0;
    while(!pqx.empty())
    {
        if(pqx.top().second)
        {
            sx--;
            if(sx==(n-2))
                ix.push_back(pii(x,pqx.top().first));
        }
        else
        {
            sx++;
            if(sx==(n-1))
                x=pqx.top().first;
            if(sx==n)
            {
                xxx=pqx.top().first;
                fx=1;
            }
        }
        pqx.pop();
    }
    while(!pqy.empty())
    {
        if(pqy.top().second)
        {
            sy--;
            if(sy==n-2)
                iy.push_back(pii(y,pqy.top().first));
        }
        else
        {
            sy++;
            if(sy==n-1)
                y=pqy.top().first;
            if(sy==n)
            {
                yyy=pqy.top().first;
                fy=1;
            }
        }
        pqy.pop();
    }

    for(auto yx : ix)
        for(auto yy : iy)
        {
            int cont=0;
            for(int i=0;i<n;i++)
                if(intersect(yx,yy,i))
                    cont++;
            if(cont>=n-1)
                x=yx.first,y=yy.first;
        }

    if(fx)
        x=xxx;
    if(fy)
        y=yyy;

    cout << x << ' ' << y << '\n';

    return 0;
}