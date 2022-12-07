#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        scanf("%d", &n);
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        sort(ar, ar+n, greater <int>());
        int ty=0, q[3]={0, 0, 0};
        for(int a=0; ar[a]>ar[n/2]; a++)
        {
            if(a and ar[a]!=ar[a-1] and ty<2)
            {
                if(ty==0 or (ty==1 and q[0]<q[1])) ty++;
            }
            q[ty]++;
        }
        if(q[2]<=q[0]) q[0]=0, q[1]=0, q[2]=0;
        for(int i=0; i<3; i++) printf("%d ", q[i]);
        printf("\n");
    }
}