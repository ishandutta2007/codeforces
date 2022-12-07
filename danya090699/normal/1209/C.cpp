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
        string s;
        cin>>n>>s;
        int ar[n], ar2[n], an[n], yk=0;
        for(int a=0; a<n; a++) ar2[a]=s[a]-'0', ar[a]=ar2[a], an[a]=0;
        sort(ar, ar+n);
        for(int a=0; a<n; a++)
        {
            if(ar2[a]==ar[yk]) an[a]=1, yk++;
        }
        for(int a=0; a<n; a++)
        {
            if(an[a]==0)
            {
                if(ar2[a]==ar[yk]) an[a]=2, yk++;
                else break;
            }
        }
        if(yk==n)
        {
            for(int a=0; a<n; a++) printf("%d", an[a]);
        }
        else printf("-");
        printf("\n");
    }
}