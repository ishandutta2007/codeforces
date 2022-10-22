#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
#define MAXN 200005

int x[MAXN],y[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen(".in","r",stdin);

    int n,sx,sy;
    cin >> n >> sx >> sy;
    for(int i=0;i<n;i++)
        cin >> x[i] >> y[i];

    vector<pip> v;
    int px=sx-1,py=sy;
    if(px>=0)
    {
        int cont=0;
        for(int i=0;i<n;i++)
            if(x[i]<sx)
                cont++;
        v.push_back(pip(cont,pii(px,py)));
    }

    px=sx+1,py=sy;
    if(px<=1000000000)
    {
        int cont=0;
        for(int i=0;i<n;i++)
            if(x[i]>sx)
                cont++;
        v.push_back(pip(cont,pii(px,py)));
    }

    px=sx,py=sy-1;
    if(py>=0)
    {
        int cont=0;
        for(int i=0;i<n;i++)
            if(y[i]<sy)
                cont++;
        v.push_back(pip(cont,pii(px,py)));
    }

    px=sx,py=sy+1;
    if(py<=1000000000)
    {
        int cont=0;
        for(int i=0;i<n;i++)
            if(y[i]>sy)
                cont++;
        v.push_back(pip(cont,pii(px,py)));
    }

    sort(v.rbegin(),v.rend());

    db(v[0].first)
    cout << v[0].second.first << ' ' << v[0].second.second << '\n';

    return 0;
}