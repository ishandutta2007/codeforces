#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x,y,d;
        scanf("%d%d%d%d",&n,&x,&y,&d);
        if(abs(x-y)%d==0)
        {
            printf("%d\n",abs(x-y)/d);
        }
        else{
            if((y-1)%d!=0&&(n-y)%d!=0) puts("-1");
            else{
                int left=0x3f3f3f3f,right=0x3f3f3f3f;
                if((y-1)%d==0)
                    left=ceil((x-1)/(double)(d))+(y-1)/d;
                if((n-y)%d==0)
                    right=ceil((n-x)/(double)(d))+(n-y)/d;
                printf("%d\n",min(left,right));
            }
        }
    }
}