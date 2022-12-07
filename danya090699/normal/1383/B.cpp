#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int ar[n], su=0;
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar[a]);
            su^=ar[a];
        }
        if(su)
        {
            int i=31-__builtin_clz(su);

            int q0=0, q1=0;
            for(int a=0; a<n; a++)
            {
                if(ar[a]&(1<<i)) q1++;
                else q0++;
            }
            if((q1+1)%4==0 and q0%2==0) printf("LOSE\n");
            else printf("WIN\n");
        }
        else printf("DRAW\n");
    }
}