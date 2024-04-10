#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int sm[n][n], mi=2e9, inf=2e9, di[n];
    bool us[n];
    for(int a=0; a<n; a++)
    {
        sm[a][a]=0;
        for(int b=a+1; b<n; b++)
        {
            scanf("%d", &sm[a][b]);
            mi=min(mi, sm[a][b]);
            sm[b][a]=sm[a][b];
        }
        us[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        di[a]=inf;
        for(int b=0; b<n; b++)
        {
            if(a!=b)
            {
                sm[a][b]-=mi;
                di[a]=min(di[a], sm[a][b]*2);
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        int bva=inf, bnu;
        for(int b=0; b<n; b++)
        {
            if(us[b]==0 and di[b]<bva)
            {
                bva=di[b], bnu=b;
            }
        }
        us[bnu]=1;
        for(int b=0; b<n; b++) di[b]=min(di[b], bva+sm[bnu][b]);
    }
    for(int a=0; a<n; a++) cout<<di[a]+1ll*mi*(n-1)<<"\n";
}