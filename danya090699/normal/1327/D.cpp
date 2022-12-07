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
        int n, an=1e9;
        scanf("%d", &n);
        int to[n], c[n], us[n];
        for(int a=0; a<n; a++) scanf("%d", &to[a]), to[a]--, us[a]=0;
        for(int a=0; a<n; a++) scanf("%d", &c[a]);
        for(int a=0; a<n; a++)
        {
            if(!us[a])
            {
                int v=a;
                vector <int> sp;
                while(!us[v])
                {
                    us[v]=1, sp.push_back(v), v=to[v];
                }
                int m=sp.size();
                for(int b=1; b<=m; b++)
                {
                    if(m%b==0)
                    {
                        for(int i=0; i<b; i++)
                        {
                            bool ok=1;
                            for(int j=i; j<m; j+=b) if(c[sp[j]]!=c[sp[i]]) ok=0;
                            if(ok) an=min(an, b);
                        }
                    }
                }
            }
        }
        printf("%d\n", an);
    }
}