#include <bits/stdc++.h>
using namespace std;
main()
{
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, m=0, d=0;
        cin>>n;
        while((1<<m)<n) m++;
        for(int i=0; i<m; i++)
        {
            vector <int> sp[2];
            for(int a=0; a<n; a++)
            {
                if(a&(1<<i)) sp[0].push_back(a+1);
                else sp[1].push_back(a+1);
            }
            printf("%d %d", sp[0].size(), sp[1].size());
            for(int b=0; b<2; b++) for(int a=0; a<sp[b].size(); a++) printf(" %d", sp[b][a]);
            cout<<endl;
            int re;
            scanf("%d", &re);
            d=max(d, re);
        }
        cout<<"-1 "<<d<<endl;
    }
}