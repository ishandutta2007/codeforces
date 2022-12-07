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
        set <int> se;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            se.insert(x);
        }
        printf("%d\n", se.size());
    }
}