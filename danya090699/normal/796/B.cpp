#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, cu=0;
    scanf("%d%d%d", &n, &m, &k);
    bool ot[n];
    for(int a=0; a<n; a++) ot[a]=0;
    for(int a=0; a<m; a++)
    {
        int pos;
        scanf("%d", &pos);
        pos--;
        ot[pos]=1;
    }
    for(int a=0; a<k; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        if(ot[cu]) break;
        else
        {
            if(u==cu) cu=v;
            else if(v==cu) cu=u;
        }
    }
    cout<<cu+1;
}