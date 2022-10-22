#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 400005
#define l2 19

ll w[MAXN],level[MAXN],lca[MAXN][l2],slca[MAXN][l2],lg[MAXN],p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen(".in","r",stdin);

    lg[0]=-1;
    for(int i=1;i<MAXN;i++)
        lg[i]=lg[i-1]+!(i&(i-1));

    int q,last=0,cnt=1;
    cin >> q;

    level[0]=1;
    p[0]=-1;
    while(q--)
    {
        ll t,r,x;
        cin >> t >> r >> x;
        r^=last;
        x^=last;
        if(t==1)
        {
            int parent=r-1;
            w[cnt]=x;
            for(int i=l2-1;i>=0 && parent!=-1;i--)
                if(w[lca[parent][i]]<x && i<=lg[level[parent]])
                    parent=p[lca[parent][i]];

            p[cnt]=parent;
            level[cnt]++;
            if(p[cnt]!=-1)
                level[cnt]+=level[p[cnt]];

            lca[cnt][0]=cnt;
            for(int i=1;i<=lg[level[cnt]];i++)
                lca[cnt][i]=lca[p[lca[cnt][i-1]]][i-1];

            slca[cnt][0]=x;
            for(int i=1;i<=lg[level[cnt]];i++)
                slca[cnt][i]=slca[cnt][i-1]+slca[p[lca[cnt][i-1]]][i-1];

            cnt++;
        }
        else
        {
            int res=0,node=r-1;
            for(int i=l2-1;i>=0 && node!=-1;i--)
                if(i<=lg[level[node]] && slca[node][i]<=x)
                {
                    res+=(1<<i);
                    x-=slca[node][i];
                    node=p[lca[node][i]];
                }
            db(res)
            last=res;
        }
    }

    return 0;
}