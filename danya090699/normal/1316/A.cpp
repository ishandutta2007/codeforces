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
        int n, m, su=0;
        cin>>n>>m;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            su+=x;
        }
        cout<<min(m, su)<<"\n";
    }
}