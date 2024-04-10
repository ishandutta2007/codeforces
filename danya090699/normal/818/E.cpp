#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    if(k==1) cout<<(1ll*n*n+n)/2;
    else
    {
    vector <int> de, pr, prq;
    for(int a=1; a*a<=k; a++)
    {
        if(k%a==0)
        {
            de.push_back(k/a);
            if(a!=k/a) de.push_back(a);
        }
    }
    sort(de.begin(), de.end());
    for(int a=1; a<de.size(); a++)
    {
        bool po=1;
        for(int b=a-1; b>0; b--) if(de[a]%de[b]==0) po=0;
        if(po) pr.push_back(de[a]);
    }
    for(int a=0; a<pr.size(); a++)
    {
        prq.push_back(0);
        while(k%pr[a]==0)
        {
            k/=pr[a], prq.back()++;
        }
    }
    int m=pr.size();
    int qq[n][m];
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        for(int b=0; b<m; b++)
        {
            qq[a][b]=0;
            while(x%pr[b]==0)
            {
                x/=pr[b], qq[a][b]++;
            }
        }
    }
    int cuq[m], yk=0;
    for(int a=0; a<m; a++) cuq[a]=0;
    long long ans=0;
    for(int a=0; a<n; a++)
    {
        while(yk<n)
        {
            bool po=1;
            for(int b=0; b<m; b++) if(cuq[b]<prq[b]) po=0;
            if(po) break;
            else
            {
                for(int b=0; b<m; b++) cuq[b]+=qq[yk][b];
                yk++;
            }
        }
        bool po=1;
        for(int b=0; b<m; b++) if(cuq[b]<prq[b]) po=0;
        if(po)
        {
            ans+=n-yk+1;
        }
        for(int b=0; b<m; b++) cuq[b]-=qq[a][b];
    }
    cout<<ans;
    }
}