#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, qq;
    cin>>n>>qq;
    int ve[n+1][20], q[n+1];
    for(int a=0; a<20; a++) ve[0][a]=0;
    q[0]=1;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        for(int b=0; b<20; b++) ve[a+1][b]=ve[a][b];
        q[a+1]=q[a];
        for(int b=19; b>=0; b--) x=min(x, x^ve[a+1][b]);
        if(x==0) q[a+1]=(q[a+1]*2)%mod;
        else
        {
            for(int b=19; b>=0; b--)
            {
                if(x>=(1<<b))
                {
                    ve[a+1][b]=x;
                    break;
                }
            }
        }
    }
    for(int a=0; a<qq; a++)
    {
        int l, x;
        scanf("%d%d", &l, &x);
        for(int b=19; b>=0; b--) x=min(x, x^ve[l][b]);
        if(x==0) printf("%d\n", q[l]);
        else printf("%d\n", 0);
    }
}