#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        int n[3]={b,b,b};
        int ans=0;
        for(;;ans++)
        {
            sort(n,n+3);
            if(n[1]+n[2]>a)n[0]=a;
            else n[0]=n[1]+n[2]-1;
//            printf("%d %d %d\n",n[0],n[1],n[2]);
            if(n[0]==a && n[1]==a && n[2]==a)break;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}