#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, pr, cu, pos=1;
    cin>>n>>m;
    int ar[n];
    for(int a=0; a<n; a++) ar[a]=-1;
    for(int a=0; a<m; a++)
    {
        cin>>cu;
        if(a>0)
        {
            int va=cu-pr;
            if(va<=0) va+=n;
            if(ar[pr-1]!=-1 and ar[pr-1]!=va) pos=0;
            ar[pr-1]=va;
        }
        pr=cu;
    }
    if(pos)
    {
        for(int a=1; a<=n; a++)
        {
            int q=0;
            for(int b=0; b<n; b++) if(ar[b]==a) q++;
            if(q>1) pos=0;
            if(q==0)
            {
                for(int b=0; b<n; b++)
                {
                    if(ar[b]==-1)
                    {
                        ar[b]=a;
                        break;
                    }
                }
            }
        }
    }
    if(pos) for(int a=0; a<n; a++) cout<<ar[a]<<" ";
    else cout<<-1;
}