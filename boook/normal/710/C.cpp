#include<bits/stdc++.h>
using namespace std;
#define MAX 500000
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        int A=1,B=2;
        int q=t/2,w=1;
        for(int i=0;i<t/2;i++)
        {
            printf("%d",B),B+=2;
            for(int j=1;j<q;j++)printf(" %d",B),B+=2;
            for(int j=0;j<w;j++)printf(" %d",A),A+=2;
            for(int j=0;j<q;j++)printf(" %d",B),B+=2;puts("");
            q--,w+=2;
        }
        printf("%d",A),A+=2;
        for(int j=1;j<t;j++)printf(" %d",A),A+=2;
        puts("");
        q=1,w=t-2;
        for(int i=0;i<t/2;i++)
        {
            printf("%d",B),B+=2;
            for(int j=1;j<q;j++)printf(" %d",B),B+=2;
            for(int j=0;j<w;j++)printf(" %d",A),A+=2;
            for(int j=0;j<q;j++)printf(" %d",B),B+=2;puts("");
            q++,w-=2;
        }
    }
    return 0;
}