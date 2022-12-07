#include <bits/stdc++.h>
using namespace std;
const int sz=110;
int q[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        int lef=m-x, an=a;
        for(int b=1; b<sz; b++)
        {
            int ok=min(lef/b, q[b]);
            an-=ok, lef-=ok*b;
        }
        printf("%d ", an);
        q[x]++;
    }
}