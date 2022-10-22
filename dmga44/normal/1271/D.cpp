#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
#define MAXN 5005

int a[MAXN],b[MAXN],c[MAXN],mi[MAXN];
vector<int> g[MAXN];
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen(".in","r",stdin);

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        g[i].push_back(i);
    }

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
    }

    for(int i=0;i<n;i++)
    {
        mi[i]=k-a[i];
        k+=b[i];
    }

    mi[n]=k;

    for(int i=n-1;i>=0;i--)
        mi[i]=min(mi[i],mi[i+1]);

    if(mi[0]<0)
        db(-1)
    else
    {
        priority_queue<int,vector<int>,less<int> > pq;
        int pos=n,res=0,cont=0;
        for(int i=0;i<k;i++)
        {
            while(pos>0 && mi[pos]>=mi[n]-i)
            {
                pos--;
                for(auto y : g[pos])
                    if(!mk[y])
                    {
                        pq.push(c[y]);
                        mk[y]=1;
                    }
            }

            if(!pq.empty())
            {
                res+=pq.top();
                pq.pop();
            }
        }
        db(res)
    }

    return 0;
}