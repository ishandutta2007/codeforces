#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
#define MAXN 3005

ll ma[MAXN][MAXN],g[MAXN*MAXN],lg[MAXN];
int a1[MAXN][MAXN],res[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,a,b;
    cin >> n >> m >> a >> b;
    ll g0,x,y,z;
    cin >> g0 >> x >> y >> z;
    g[0]=g0;
    for(int i=1;i<MAXN*MAXN;i++)
        g[i]=(g[i-1]*x+y)%z;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ma[i][j]=g[i*m+j];

    for(int i=0;i<n;i++)
    {
        deque<pii> q;
        for(int j=m-1;j>=0;j--)
        {
            while(!q.empty() && q.front().second>(j+b))
                q.pop_front();
            if(!q.empty() && j<m-b)
                a1[i][j+1]=q.front().first;
            while(!q.empty() && q.back().first>ma[i][j])
                q.pop_back();
            q.push_back(pii(ma[i][j],j));
        }
        while(!q.empty() && q.front().second>(b-1))
            q.pop_front();
        if(!q.empty())
            a1[i][0]=q.front().first;
    }

    for(int i=0;i<m;i++)
    {
        deque<pii> q;
        for(int j=n-1;j>=0;j--)
        {
            while(!q.empty() && q.front().second>(j+a))
                q.pop_front();
            if(!q.empty() && j<n-a)
                res[j+1][i]=q.front().first;
            while(!q.empty() && q.back().first>a1[j][i])
                q.pop_back();
            q.push_back(pii(a1[j][i],j));
        }
        while(!q.empty() && q.front().second>(a-1))
            q.pop_front();
        if(!q.empty())
            res[0][i]=q.front().first;
    }

//    for(int i=0;i<n;i++,cout << '\n')
//        for(int j=0;j<m;j++)
//            cout << res[i][j] << ' ';

    ll re=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            re+=(ll)(res[i][j]);
    db(re)

    return 0;
}