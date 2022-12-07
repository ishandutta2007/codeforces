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
        int n, m;
        scanf("%d%d", &n, &m);
        bool us[3*n];
        for(int a=0; a<3*n; a++) us[a]=0;
        vector <int> re;
        for(int a=0; a<m; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            if(us[u]==0 and us[v]==0)
            {
                re.push_back(a+1);
                us[u]=1, us[v]=1;
            }
        }
        if(re.size()>=n)
        {
            printf("Matching\n");
            for(int a=0; a<n; a++) printf("%d ", re[a]);
            printf("\n");
        }
        else
        {
            printf("IndSet\n");
            int lef=n;
            for(int a=0; a<n*3; a++)
            {
                if(us[a]==0 and lef)
                {
                    lef--;
                    printf("%d ", a+1);
                }
            }
            printf("\n");
        }
    }
}