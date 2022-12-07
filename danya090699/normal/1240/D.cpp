#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
map <int, int> to[sz];
int ar[sz], q[sz], pr[sz], prsy[sz];
long long an;
void dfs(int l, int r)
{
    if(l!=r)
    {
        int mid=(l+r)>>1, s=0, qnt=1;
        prsy[0]=-1;
        for(int a=mid; a>=l; a--)
        {
            int sy=ar[a];
            if(prsy[s]==sy) s=pr[s];
            else
            {
                if(to[s].find(sy)==to[s].end())
                {
                    pr[qnt]=s, prsy[qnt]=sy, to[s][sy]=qnt, s=qnt++;
                }
                else s=to[s][sy];

                //if(l==0 and r==4) cout<<mid<<" ";
            }
            q[s]++;
        }
        s=0;
        for(int a=mid+1; a<=r; a++)
        {
            int sy=ar[a];
            if(prsy[s]==sy) s=pr[s];
            else
            {
                if(to[s].find(sy)==to[s].end())
                {
                    pr[qnt]=s, prsy[qnt]=sy, to[s][sy]=qnt, s=qnt++;
                }
                else s=to[s][sy];

            }
            an+=q[s];
        }
        for(int a=0; a<qnt; a++) q[a]=0, to[a].clear();

        //cout<<an<<" ";

        dfs(l, mid);
        dfs(mid+1, r);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    while(q)
    {
        q--;
        int n;
        scanf("%d", &n);
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        an=0;
        dfs(0, n-1);
        printf("%lld\n", an);
    }
}