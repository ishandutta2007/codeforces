#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
const long long inf2=1e18;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    int pr[n];
    for(int a=0; a<n; a++) pr[a]=0;
    for(int a=0; a<m; a++)
    {
        int p;
        scanf("%d", &p);
        pr[p]=1;
    }
    for(int a=0; a<n; a++)
    {
        if(pr[a]==0) pr[a]=a;
        else
        {
            if(a==0) pr[a]=-inf;
            else pr[a]=pr[a-1];
        }
    }
    long long an=inf2;
    for(int a=1; a<=k; a++)
    {
        int va, yk=0;
        scanf("%d", &va);
        long long cu=0;
        while(yk<n)
        {
            if(pr[yk]+a>yk)
            {
                yk=pr[yk]+a, cu+=va;
            }
            else
            {
                cu=inf2;
                break;
            }
        }
        an=min(an, cu);
    }
    if(an!=inf2) cout<<an;
    else cout<<-1;
}