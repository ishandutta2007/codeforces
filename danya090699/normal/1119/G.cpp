#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int hp[m], yk=0, lef=0, su=0;
    for(int a=0; a<m; a++) scanf("%d", &hp[a]), su+=hp[a];
    lef=hp[0];
    vector <int> sp;
    while(yk<m)
    {
        if(lef<n)
        {
            int q=0;
            while(yk<m and q<n)
            {
                int add=min(lef, n-q);
                q+=add, lef-=add;
                if(lef==0)
                {
                    yk++;
                    if(yk<m) lef=hp[yk];
                }
                if(q<n and yk!=m) sp.push_back(q);
            }
        }
        else
        {
            lef-=n;
            if(lef==0)
            {
                yk++;
                if(yk<m) lef=hp[yk];
            }
        }
    }
    sp.push_back(n);
    while(sp.size()<m) sp.push_back(0);
    sort(sp.begin(), sp.end());
    for(int a=m-1; a; a--) sp[a]-=sp[a-1];

    cout<<su/n+(su%n>0)<<"\n";
    for(int a=0; a<m; a++) printf("%d ", sp[a]);
    printf("\n");
    yk=0;
    while(yk<m)
    {
        for(int a=0; a<m; a++)
        {
            if(yk<m)
            {
                hp[yk]-=sp[a];
                printf("%d ", yk+1);
                if(hp[yk]<=0) yk++;
            }
            else printf("1 ");
        }
        printf("\n");
    }
}