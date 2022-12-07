#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int va[n], t[n];
    for(int a=0; a<n; a++) scanf("%d", &va[a]), t[a]=0;
    int q;
    cin>>q;
    int suf[q+1];
    suf[0]=0;
    for(int a=0; a<q; a++)
    {
        suf[a+1]=0;
        int ty, p, x;
        scanf("%d", &ty);
        if(ty==1)
        {
            scanf("%d%d", &p, &x);
            p--;
            va[p]=x, t[p]=a+1;
        }
        else
        {
            scanf("%d", &x);
            suf[a+1]=x;
        }
    }
    for(int a=q-1; a>=0; a--) suf[a]=max(suf[a], suf[a+1]);
    for(int a=0; a<n; a++) printf("%d ", max(va[a], suf[t[a]]));
}