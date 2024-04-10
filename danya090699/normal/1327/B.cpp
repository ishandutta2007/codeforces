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
        cin>>n;
        int us[n], bad=-1;
        for(int a=0; a<n; a++) us[a]=0;
        for(int a=0; a<n; a++)
        {
            int q, fo=0;
            scanf("%d", &q);
            for(int b=0; b<q; b++)
            {
                int i;
                scanf("%d", &i);
                i--;
                if(!fo and !us[i]) us[i]=1, fo=1;
            }
            if(!fo) bad=a;
        }
        if(bad==-1) printf("OPTIMAL\n");
        else
        {
            int i;
            for(int a=0; a<n; a++) if(!us[a]) i=a;
            printf("IMPROVE\n%d %d\n", bad+1, i+1);
        }
    }
}