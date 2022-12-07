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
        if(n==1) printf("-1\n");
        else
        {
            for(int a=0; a<n-2; a++) printf("5");
            if(((n-2)*5)%3==0) printf("53\n");
            else printf("33\n");
        }
    }
}