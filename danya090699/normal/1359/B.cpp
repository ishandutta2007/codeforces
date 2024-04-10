#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, x, y, an=0;
        scanf("%d%d%d%d", &n, &m, &x, &y);
        for(int a=0; a<n; a++)
        {
            char s[m+1];
            scanf("%s", s);
            int yk=0;
            while(yk<m)
            {
                if(s[yk]=='*') yk++;
                else
                {
                    int q=0;
                    while(s[yk]=='.') yk++, q++;
                    an+=q/2*min(y, x*2)+q%2*x;
                }
            }
        }
        printf("%d\n", an);
    }
}