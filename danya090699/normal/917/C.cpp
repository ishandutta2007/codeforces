#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=(1<<8), inf=1e18;
int te[sz][sz], st[30][sz][sz];
vector <int> av;
int m;
void mul(int (*m1)[sz], int (*m2)[sz])
{
    for(int a=0; a<m; a++) for(int b=0; b<m; b++) te[av[a]][av[b]]=inf;
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<m; b++)
        {
            for(int c=0; c<m; c++)
            {
                int f=av[a], t=av[b], m=av[c];
                te[f][t]=min(te[f][t], m1[f][m]+m2[m][t]);
            }
        }
    }
    for(int a=0; a<m; a++) for(int b=0; b<m; b++) m1[av[a]][av[b]]=te[av[a]][av[b]];
}
main()
{
    //freopen("input.txt", "r", stdin);
    int x, k, n, q;
    cin>>x>>k>>n>>q;
    for(int a=0; a<(1<<k); a++) if(__builtin_popcount(a)==x) av.push_back(a);
    m=av.size();
    int ju[k];
    for(int a=0; a<k; a++) cin>>ju[a];
    for(int a=0; a<m; a++) for(int b=0; b<m; b++) st[0][av[a]][av[b]]=inf;
    for(int a=0; a<m; a++)
    {
        int f=av[a];
        if(f&1)
        {
            int t=(f>>1);
            for(int b=0; b<k; b++) if((t&(1<<b))==0) st[0][f][t|(1<<b)]=ju[b];
        }
        else st[0][f][f>>1]=0;
    }
    for(int i=1; i<30; i++)
    {
        for(int a=0; a<m; a++) for(int b=0; b<m; b++) st[i][av[a]][av[b]]=st[i-1][av[a]][av[b]];
        mul(st[i], st[i-1]);
    }
    map <int, int> sto;
    for(int a=0; a<q; a++)
    {
        int po, va;
        cin>>po>>va;
        sto[po-1]=va;
    }
    sto[n]=0;
    int cu=0, dp[sz], dp2[sz];
    for(int a=0; a<m; a++)
    {
        dp[av[a]]=inf, dp2[av[a]]=inf;
    }
    dp[av[0]]=0;
    while(cu<n-x)
    {
        int ne;
        if(sto.upper_bound(cu)==sto.end()) ne=-1;
        else ne=(*sto.upper_bound(cu)).first;
        if(ne<=cu+k)
        {
            for(int a=0; a<m; a++)
            {
                int f=av[a];
                if(f&1)
                {
                    int t=(f>>1);
                    for(int b=0; (b<k and cu+b+1<n); b++)
                    {
                        if((t&(1<<b))==0)
                        {
                            int add=0;
                            if(sto.find(cu+b+1)!=sto.end()) add=sto[cu+b+1];
                            dp2[t|(1<<b)]=min(dp2[t|(1<<b)], dp[f]+ju[b]+add);
                        }
                    }
                }
                else dp2[f>>1]=min(dp2[f>>1], dp[f]);
            }
            cu++;
        }
        else
        {
            int le=ne-(cu+k), ma[sz][sz];
            for(int a=0; a<m; a++)
            {
                for(int b=0; b<m; b++)
                {
                    if(a==b) ma[av[a]][av[b]]=0;
                    else ma[av[a]][av[b]]=inf;
                }
            }
            for(int a=0; a<30; a++) if(le&(1<<a)) mul(ma, st[a]);
            for(int a=0; a<m; a++)
            {
                for(int b=0; b<m; b++)
                {
                    int f=av[a], t=av[b];
                    dp2[t]=min(dp2[t], dp[f]+ma[f][t]);
                }
            }
            cu+=le;
        }
        for(int a=0; a<m; a++)
        {
            dp[av[a]]=dp2[av[a]], dp2[av[a]]=inf;
        }
    }
    cout<<dp[av[0]];
}