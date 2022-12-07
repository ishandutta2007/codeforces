#include <bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++) printf("%d ", a%4+((b%4)<<2)+16*(a/4*(n/4)+b/4));
        printf("\n");
    }
}