#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
using namespace std;
typedef long long LL;
char a[5][105];
int main()
{
    int l[5],i,j,f3=0;
    scanf("%s%s%s%s",a[1]+1,a[2]+1,a[3]+1,a[4]+1);
    l[1]=strlen(a[1]+1)-2;
    l[2]=strlen(a[2]+1)-2;
    l[3]=strlen(a[3]+1)-2;
    l[4]=strlen(a[4]+1)-2;
    for(i=1;i<=4;i++)
    {
        int f1=1,f2=1;
        for(j=1;j<=4;j++)
            if(i!=j)
            {
                if(l[i]>l[j]/2)
                    f1=0;
                if(l[i]<l[j]*2)
                    f2=0;
            }
        if(f1||f2)
        {
            if(f3!=0)
            {
                printf("C\n");
                return 0;
            }
            f3=i;
        }
    }
    if(!f3) printf("C\n");
    else printf("%c",f3+64);
    return 0;
}
// davidlee1999WTK 2014/