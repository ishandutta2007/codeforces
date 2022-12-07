#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n], ar2[m], yk=0, yk2=0, an=0;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=0; a<m; a++) scanf("%d", &ar2[a]);
    while(yk<n)
    {
        int q=ar[yk], q2=0;
        yk++;
        while(q!=q2)
        {
            if(q<q2)
            {
                q+=ar[yk], yk++;
            }
            else
            {
                q2+=ar2[yk2], yk2++;
            }
        }
        an++;
    }
    cout<<an;
}