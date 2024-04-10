#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

ll res,a[MAXN],ip[MAXN],rmq[MAXN][18];
ll lg[MAXN];

int q(int l,int r)
{
    int po=lg[r-l+1];
    return max(rmq[l][po],rmq[r-(1<<po)+1][po]);
}

void solve(int p,int l,int r)
{
    if(p==l && p==r)
        return;
    if(p==l || p==r)
    {
        if(p==l)
            solve(ip[q(l+1,r)],l+1,r);
        if(p==r)
            solve(ip[q(l,r-1)],l,r-1);
        return ;
    }
    int ini=l,fin=p-1,fi=p+1,ff=r;
    if(r-p<p-l)
    {
        swap(ini,fi);
        swap(fin,ff);
    }
    for(int i=ini;i<=fin;i++)
        if(ip[a[p]-a[i]]>=fi && ip[a[p]-a[i]]<=ff)
            res++;

    solve(ip[q(fi,ff)],fi,ff);
    solve(ip[q(ini,fin)],ini,fin);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lg[0]=-1;
    for(int i=1;i<MAXN;i++)
        lg[i]=(lg[i-1]+!(i&(i-1)));

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        ip[a[i]]=i;
    }

    for(int i=0;i<n;i++)
        rmq[i][0]=a[i];
    for(int i=1;i<=lg[n];i++)
        for(int j=0;j+(1<<i)<=n;j++)
            rmq[j][i]=max(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);

    solve(ip[n],0,n-1);

    db(res)

    return 0;
}