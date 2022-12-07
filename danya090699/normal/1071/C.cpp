#include <bits/stdc++.h>
using namespace std;
struct el
{
    int x, y, z;
};
const int d=5, inf=1e9;
vector <el> op[1<<6];
int main()
{
    for(int s=-d; s<6; s++)
    {
        for(int st=1; s+st*2<6; st++)
        {
            int mask=0;
            if(s>=0) mask+=(1<<s);
            if(s+st>=0) mask+=(1<<(s+st));
            if(s+st*2>=0) mask+=(1<<(s+st*2));
            if(op[mask].size()==0) op[mask].push_back({s, s+st, s+st*2});
        }
    }
    bool ok=1;
    for(int mask=0; mask<(1<<6); mask++)
    {
        if(op[mask].size()==0)
        {
            for(int mask1=0; mask1<(1<<6); mask1++)
            {
                int mask2=mask^mask1;
                if(op[mask1].size()==1 and op[mask2].size()==1)
                {
                    op[mask].push_back(op[mask1][0]);
                    op[mask].push_back(op[mask2][0]);
                    break;
                }
            }
        }
    }
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    int k=n;
    vector <el> sp;
    while(k-6>=8)
    {
        int mask=0;
        for(int a=0; a<6; a++) mask+=(ar[k-6+a]<<a);
        for(int a=0; a<op[mask].size(); a++)
        {
            int add=k-6;
            int x=op[mask][a].x+add, y=op[mask][a].y+add, z=op[mask][a].z+add;
            ar[x]^=1, ar[y]^=1, ar[z]^=1;
            sp.push_back({x, y, z});
        }
        k-=6;
    }

    int dp[1<<k], pr[1<<k];
    el go[1<<k];
    for(int a=0; a<(1<<k); a++) dp[a]=inf;
    queue <int> qu;
    dp[0]=0, qu.push(0);
    while(qu.size())
    {
        int mask=qu.front();
        for(int s=0; s<k; s++)
        {
            for(int st=1; s+st*2<k; st++)
            {
                int nmask=mask^((1<<s)+(1<<(s+st))+(1<<(s+st*2)));
                if(dp[nmask]==inf)
                {
                    dp[nmask]=dp[mask]+1;
                    pr[nmask]=mask;
                    go[nmask]={s, s+st, s+st*2};
                    qu.push(nmask);
                }
            }
        }
        qu.pop();
    }
    int cu=0;
    for(int a=0; a<k; a++) cu+=(ar[a]<<a);
    if(dp[cu]==inf) cout<<"NO";
    else
    {
        while(cu!=0)
        {
            sp.push_back(go[cu]), cu=pr[cu];
        }
        cout<<"YES\n"<<sp.size()<<"\n";
        for(int a=0; a<sp.size(); a++) printf("%d %d %d\n", sp[a].x+1, sp[a].y+1, sp[a].z+1);
    }
}