#include<bits/stdc++.h>
using namespace std;
#define MAX 500000
int n[MAX];
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        for(int i=0;i<t;i++)
            scanf("%d",&n[i]);
        sort(n,n+t);
        printf("%d\n",n[(t-1)/2]);
    }
    return 0;
}