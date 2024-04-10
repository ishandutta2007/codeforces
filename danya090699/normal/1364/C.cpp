#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <int> se;
    for(int a=0; a<=n; a++) se.insert(a);
    int ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        se.erase(ar[a]);
    }
    for(int a=0; a<n; a++)
    {
        if(a and ar[a-1]!=ar[a]) se.insert(ar[a-1]);
        printf("%d ", *se.begin());
        se.erase(se.begin());
    }
}